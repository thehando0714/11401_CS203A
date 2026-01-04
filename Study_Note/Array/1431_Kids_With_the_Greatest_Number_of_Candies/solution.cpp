#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int>vt=candies;
        sort(vt.begin(),vt.end());
        vector<bool>ans(candies.size());
        for(int i=0;i<candies.size();i++){
            if(candies[i]>=vt[vt.size()-1]||candies[i]+extraCandies>=vt[vt.size()-1]){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};
