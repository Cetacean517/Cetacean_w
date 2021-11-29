#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<signal.h>

#define N 5 	// 消费者或者生产者的数目
#define M 10 	// 缓冲数目

int in = 0;	// 生产者放置产品的位置
int out = 0;	// 消费者取产品的位置
int buff[M] = {0};	// 缓冲初始化为0，开始时没有产品

sem_t empty_sem; // 同步信号量，当满了时组织生产者放产品
sem_t full_sem;
pthread_mutex_t mutex;

int product_id = 0;
int prochase_id = 0;

// 信号处理函数
void Handlesignal(int signo){
	printf("程序%d退出\n",signo);
	exit(0);
}

// 打印缓冲情况
void print(){
	int i;
	printf("产品队列为");
	for(i = 0; i < M; i++)
		printf("%d",buff[i]);
	printf("\n");
}

// 生产者方法
void *product() {
	int id = ++product_id;
	while(1){
		sleep(2);
		sem_wait(&empty_sem);
		pthread_mutex_lock(&mutex);

		in = in % M;
		printf("生产者%d在产品队列中放入第%d个产品\t",id,in);

		buff[in] = 1;
		print();
		++in;

		pthread_mutex_unlock(&mutex);
		sem_post(&full_sem);
	}
}

// 消费者方法
void *prochase(){
	int id = ++prochase_id;
	while(1){
		sleep(5);

		sem_wait(&full_sem);
		pthread_mutex_lock(&mutex);

		out = out % M;
		printf("消费者%d从产品队列中取出第%d个产品\t",id,out);

		buff[out] = 0;
		print();
		++out;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty_sem);
	}
}
int main(){
	print("生产者和消费者数目都为5，产品缓冲为10，生产者每2秒生产一个产品，消费者每5秒消费一个产品，Ctrl+退出程序\n");
	pthread_t id1[N];
	pthread_t id2[N];
	int i;
	int ret[N];

	if(signal(SIGINT,Handlesignal) == SIG_ERR){
		printf("信号安装出错\n");
	}

	int ini1 = sem_init(&empty_sem,0,M);
	int ini2 = sem_init(&full_sem,0,0);
	if(ini1 && ini2 != 0){
		printf("信号初始化失败!\n");
		exit(1);
	}
	int ini3 = pthread_mutex_init(&mutex,NULL);
	if(ini3 != 0){
		printf("线程同步初始化失败!\n");
		exit(1);
	}

	for (i=0; i<N;i++){
		ret[i] = pthread_create(&id2[i],NULL,prochase,NULL);
		if(ret[i] != 0){
			printf("消费者%d线程创建失败!\n",i);
			exit(1);
		}
	}

	for(i = 0;i<N;i++){
		pthread_join(id1[i],NULL);
		pthread_join(id2[i],NULL);
	}
	exit(0);
}
