#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0, end = numbers.size() - 1,sum;
        while (1 < end)
        {
            sum = numbers[begin] + numbers[end];
            if(sum == target){
                break;
            };
            if(sum > target) --end;
            else ++begin;
        }
        vector<int> li = {begin+1,end+1};
        return li;
    }
};

int main(){
    Solution s;
    vector<int> numbers = {2,7,8,9};
    int target = 9;
    s.twoSum(numbers,target);
}