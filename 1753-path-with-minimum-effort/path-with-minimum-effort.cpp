class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        int n= heights.size();
        int m= heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        
        dist[0][0]=0;
        pq.push({0,{0,0}});

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
       
        while(!pq.empty()){
            int d= pq.top().first;
            int r= pq.top().second.first;
            int c= pq.top().second.second;
            pq.pop();

            if(r == n-1 && c == m-1)
                return d;

            for(int i=0; i<4;i++){
                int nr= dr[i]+ r;
                int nc= dc[i]+ c;

                if( nr >=0 && nr<n && nc >=0 && nc<m){
                    int nd= heights[r][c]-heights[nr][nc];
                    int newEffort= max(d, abs(nd));

                    if(newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
     return 0;
    }
};