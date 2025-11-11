class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>go={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,pair<int,int>>>qu;//min x y
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int k=0;k<grid[i].size();k++){
                if(grid[i][k]==2){
                    qu.push({0,{i,k}});
                }
            }
        }
        int ans=0;
        
        while(!qu.empty()){
            int time=qu.front().first;
            int x=qu.front().second.first;
            int y=qu.front().second.second;
            qu.pop();
            ans=max(ans,time);
            
            for(int i=0;i<4;i++){
                int dx=x+go[i][0];
                int dy=y+go[i][1];
                if(dx>=0&&dy>=0&&dx<m&&dy<n&&grid[dx][dy]==1){
                    grid[dx][dy]=2;
                    qu.push({time+1,{dx,dy}});
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int k=0;k<grid[i].size();k++){
                if(grid[i][k]==1){
                    ans=-1;
                    break;
                }
            }
        }
        return ans;
    }
};
