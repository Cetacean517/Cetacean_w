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
    vector<int> nums(10,3);//初始化一个vector对象（10是数组长度，3是数组默认值）
    cout << "原始数组：" << endl;
    Show(nums);
    nums.push_back(5);
    cout << "push_back 增加5：" << endl;
    Show(nums);
    nums.insert(nums.begin(),5,1);  //向量末尾插入5个1
    cout << "insert 多个相同元素:" << endl;
    Show(nums);
    cout << "at位置" << endl;
    cout << nums.at(4) << endl;
    cout << "size:" << nums.size() << nums.max_size() << endl;
    
    
    system("Pause");
}