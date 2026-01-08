#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        set<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i]))return nums[i];
            st.insert(nums[i]);
        }
        return 0;
    }
};