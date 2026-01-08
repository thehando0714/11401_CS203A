#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class RecentCounter {
public:
    queue<int>qu;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(qu.empty()){
            qu.push(t);
            return 1;
        }
        while(!qu.empty()&&qu.front()<t-3000){
            qu.pop();
        }
        qu.push(t);
        return qu.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */