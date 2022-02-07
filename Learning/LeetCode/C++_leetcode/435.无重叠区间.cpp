/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>::iterator it;
        for(it = intervals.begin();(it+1) != intervals.end();it++){
            vector<vector<int>>::iterator temp;
            if ((*it)[1] > (*(it+1))[1]){
                temp = it;
                it = it+1;
                it+1 = temp;
            }
        int count = 0;
        int i = 0;
        while(i<intervals.size()){
            int ori = intervals[i][1];
            if(ori > intervals[i+1][0]){
                count++;
            }
        }
    }
}
};
// @lc code=end

