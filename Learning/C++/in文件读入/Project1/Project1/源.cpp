# include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int x;
	char y;
	FILE* stream;
	freopen_s(&stream,"gangs.in", "r", stdin);
	freopen_s(&stream,"gangs.out", "w", stdout);
	while (cin >> x >> y) {
		cout << x << endl;
		cout << y << endl;
	}
	fclose(stdin);//�ر��ļ� 
	fclose(stdout);//�ر��ļ�
}