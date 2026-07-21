class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n + 1];

        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }


        queue<pair <int,int>> q;
        q.push({k,0});
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;

        while(!q.empty()){
            int node= q.front().first;
            int cost= q.front().second;
            q.pop();

            for(auto it: adj[node]){
                int adjnode= it.first;
                int edjW= it.second;

                if(edjW + cost < dist[adjnode]){
                    dist[adjnode]=edjW + cost;
                    q.push({adjnode, edjW + cost});
                }
            }
        }
        int maxi=0;
        for(int i=1; i<= n; i++){
            if(dist[i]==INT_MAX) return -1;
            maxi= max(dist[i], maxi);
        }
        return maxi;
    }
};