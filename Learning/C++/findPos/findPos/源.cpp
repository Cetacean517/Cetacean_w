#include<iostream>
using namespace std;


int main() {
	int aNum, bNum, cNum;
	int i = 0,j = 0,k = 0;
	aNum = 5, bNum = 5, cNum = 7;
	cout << "enter aNum,bNum,cNum" << endl;
	//int* a = new int[aNum];
	int a[] = { 3,3,5,7,9 };
	int b[] = { 1,3,7,9,11 };
	int c[] = { 2,4,6,7,8,9,11 };
	int min = a[j];


	while (j < bNum) {
		if (min > b[j]) j++;
		else if (min < b[j]) {
			i++;
			min = a[i];
		}
		else if (min == b[j]) {
			if (min > c[k]) k++;
			else if (min == c[k]) {
				break;
			}

		}
	}


	if (j == bNum) cout << "Error!" << endl;
	//cout << i <<"  "<< j << endl;
	
	return 0;
}