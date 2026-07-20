class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int,int>> adj[n];

        for(auto &it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        const int mod = 1e9 + 7;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){

            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(cost > dist[node])
                continue;

            for(auto &it : adj[node]){

                int adjNode = it.first;
                int edgeW = it.second;

                if(cost + edgeW < dist[adjNode]){

                    dist[adjNode] = cost + edgeW;
                    ways[adjNode] = ways[node];

                    pq.push({dist[adjNode], adjNode});
                }

                else if(cost + edgeW == dist[adjNode]){

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};