# include <iostream>
# include <vector>
using namespace std;

void Show(const vector<int>& nums){
    int i = 0;
    while(i< nums.size()-1){
    cout << nums[i] << ' ';
    i++;
    }
    cout << nums[nums.size() - 1] << endl;
}
int main(){
    vector<int> nums(10,3);//��ʼ��һ��vector����10�����鳤�ȣ�3������Ĭ��ֵ��
    cout << "ԭʼ���飺" << endl;
    Show(nums);
    nums.push_back(5);
    cout << "push_back ����5��" << endl;
    Show(nums);
    nums.insert(nums.begin(),5,1);  //����ĩβ����5��1
    cout << "insert �����ͬԪ��:" << endl;
    Show(nums);
    cout << "atλ��" << endl;
    cout << nums.at(4) << endl;
    cout << "size:" << nums.size() << nums.max_size() << endl;
    
    
    system("Pause");
}