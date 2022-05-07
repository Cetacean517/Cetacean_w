// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<algorithm>
#include<iostream>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start

class Solution {
public:
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     int count = 0;
    //     vector<int>::iterator st = s.begin();   //point to the beginning of s[](biscits)
    //     // sort g[i] and s[j]
    //     sort(g.begin(),g.end());
    //     sort(s.begin(),s.end());
    //     // use iterator to traverse the array s
    //     if(s.size() == 0){
    //         return count;
    //     }

    //     for (vector<int>::iterator it = g.begin();it != g.end();it++){
    //         while(st < s.end() && *it > *st ){ //when none of the number in s[] is fit the condition,
    //                                                 // st will still move to next step, therefore will lead to the overflow of s[]
    //                                                 // so we have to use prev to point to the member before s.end()
    //             st++;
    //         }
    //         if (st == s.end()){
    //             break;
    //         }
    //         else {
    //             count ++;
    //         }
    //         st++;
    //     }
    //     return count;
    // }


    int findContentChildren(vector<int>& g, vector<int>& s) {
    int count = 0;
    int j = 0;
    // sort g[i] and s[j]
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    // use iterator to traverse the array s
    if(s.size()==0){        //用s.empty()会慢
        return count;
    }
    for(int i = 0 ;i < g.size();i++){
        while(j < s.size() && g[i] > s[j]){
            j++;
        }
        if (j == s.size()){
            break;
        }
        else{
            count++;
        }
        j++;
    }
    return count;
}
};
// @lc code=end

// 21/21 cases passed (28 ms)
// Your runtime beats 85.4 % of cpp submissions
// Your memory usage beats 71.58 % of cpp submissions (17 MB)

// 21/21 cases passed (24 ms)
// Your runtime beats 95.85 % of cpp submissions
// Your memory usage beats 19.89 % of cpp submissions (17.1 MB)
