// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem135.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = 0;
        int num = 1;
        cout << ratings.size();
        sort(ratings.begin(),ratings.end());
        for(int i = 0; i < ratings.size();i++){
            if(ratings[i] < ratings[i+1]){
                num++;
                count += num;
            }
            else{
                count += num;
            }
        }
        cout << count;
        return count;
    }
};
// @lc code=end

