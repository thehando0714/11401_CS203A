class Solution {
public:
    vector<vector<bool>>vis{100,vector<bool>(100,false)};
    
    int ans=-1;
    int n,m;
    vector<vector<int>>go{{0,1},{0,-1},{1,0},{-1,0}};
    int stx,sty;
    void bfs(int x,int y,int step){
        queue<pair<int,pair<int,int>>>qu;
        qu.push({0,{x,y}});
        vis[x][y]=true;
        while(!qu.empty()){
            int step=qu.front().first;
            int a=qu.front().second.first;
            int b=qu.front().second.second;
            qu.pop();
            
            if((a==0||b==0||a==n-1||b==m-1)&&(a!=stx||b!=sty)){
                ans=step;
                return;
                
            }
            for(int i=0;i<4;i++){
                int dx=a+go[i][0];
                int dy=b+go[i][1];
                if(dx>=0&&dx<n&&dy>=0&&dy<m&&!vis[dx][dy]){
                    qu.push({step+1,{dx,dy}});
                    vis[dx][dy]=true;
                }
            }
        }
        
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n=maze.size();
        m=maze[0].size();
        for(int i=0;i<maze.size();i++){
            for(int k=0;k<maze[i].size();k++){
                if(maze[i][k]=='+')vis[i][k]=true;
            }
        }
        stx=entrance[0];
        sty=entrance[1];
        bfs(stx,sty,0);
        return ans;
    }
};
