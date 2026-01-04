#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>pre(nums.size()+1);
        pre[0]=0;
        for(int i=0;i<nums.size();i++){
            pre[i+1]=pre[i]+nums[i];
        }
        for(int i=1;i<pre.size();i++){
            if(pre[pre.size()-1]-pre[i]==pre[i-1]){
                return i-1;
            }
        }
        return -1;
    }
};
