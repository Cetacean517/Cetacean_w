# include<iostream>
using namespace std;

int main(){
	int i,j,t;
	int N = 5;
	int A[N][N];
	int B[N][N];
	for(i=0;i<N;i++)
	{
		t = i + 1;
        for(j=0;j<N;j++)
	    {
           A[i][j]= t ++ ;
           B[i][j]= 1;
		   cout << B[i][j];
	    }
		cout << endl;
	}
}