class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int Fcnt= 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>, int>> q;

        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1){
                    Fcnt++;
                }
            }
        }
        int cnt=0; int tm=0;

        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};
        while(!q.empty()){
           int nrow, ncol;
           int row= q.front().first.first;
           int col= q.front().first.second;
           int t= q.front().second;
           q.pop();
           tm=max(tm,t);

           for (int i=0; i< 4 ; i++){
                nrow= row + delR[i];
                ncol= col + delC[i];
                if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && grid[nrow][ncol]==1 
                    && vis[nrow][ncol]!=2){
                        q.push({{nrow,ncol},t+1});
                        cnt++;
                        vis[nrow][ncol]=2;
                }
            } 
        }

        if(cnt!=Fcnt){
            return -1;
        }

    return tm;  
    }
    
    
};