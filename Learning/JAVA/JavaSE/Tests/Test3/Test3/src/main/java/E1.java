//题目   输出 101-200 之内的所有质数；
public class E1 {
    boolean isPrime(int num){
        int div = 2;
        if (num == 1)
        {
            return false;
        }
        while(div < Math.sqrt(num) + 1){
//            System.out.println("num "+num+"div "+div);
            if(num % div == 0)
                return false;
            else{
                div++;
            }
        }
        return true;
    }

    public void E1(){
        int no = 0;     // 计数器
        for (int i = 101; i < 201; i++) {
            if (isPrime(i)) {
                no++;
                System.out.println("No"+no+". "+i);
            }
        }
    }
}
