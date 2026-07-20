class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        queue<pair<int, pair<int,int>>> q;

        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        q.push({0,{src,0}});
        vector<int> dist(n, 1e9);

        while(!q.empty()){
            int step= q.front().first;
            int node= q.front().second.first;
            int cost= q.front().second.second;
            q.pop();

            if(step>k) continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edW= it.second;

                if(cost + edW < dist[adjNode] && step <=k){
                    dist[adjNode]= cost+ edW;
                    q.push({step+1,{adjNode, cost + edW}});
                }
            }
        }
        return (dist[dst]== 1e9) ? -1 : dist[dst];
    }
};