#include<iostream>
#include<vector>
#include <algorithm> 
#include <string>
using namespace std;

//encrypt
string encrypt(string message,vector<int> &key){
    /** 参数列表： 需要加密的字符串，密钥的数组*/
    // 对于字符串中的每一个字符加上对应的偏移值，并模26
	for(int i=0;i<message.size();i++){
		message[i]=(message[i]-'a'+key[i%key.size()])%26+'a';
	}
	return message;
}
//decipher
string decipher(string cipher,vector<int> &key){
    /** 参数列表： 需要加密的字符串，密钥的数组*/
    // 更新密钥，反向进行加密
	vector<int> k1=key;
	for(int i=0;i<key.size();i++){
		k1[i]=26-key[i];
	}
	return encrypt(cipher,k1);
}

vector<int> word2key(string keyword){
    /** 参数列表： 密钥字符串*/
    // 更具密钥字符串和小写a的差值，求得密钥字符串
    vector<int> key(keyword.size());
    for(int i = 0; i < keyword.size();i++){
        key[i] = int(keyword[i]) - int('a');
    }
    return key;
}

int main(){
    // 1. 初始化变量
	vector<int> key;
	string message,cipher,keyword;
    // 2. 输入需要加密的字符串，同时对字符串的大小写进行统一
	cout<<"Please enter the message:";
	cin>>message;
    transform(message.begin(), message.end(), message.begin(), ::tolower); 
    cout<<"Please enter the keyword:";
	cin>>keyword;
    // 3. 根据密钥生成对应的整型密钥
    key = word2key(keyword);
    // 4. 进行加密和解密
	cipher = encrypt(message,key);
    deciphe =decipher(cipher,key)
    // 输出结果
	cout<<"After encode:"<<cipher<<endl;
	cout<<"After decode:"<<deciphe<<endl;
}
