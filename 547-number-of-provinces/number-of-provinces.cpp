class Solution {
public:

    void bfs(int node, vector<vector<int>>& adjMat, vector<int>& vis){
        queue<int> q;
        q.push(node);
        vis[node]=1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(int i=0; i< adjMat.size(); i++){
                if(adjMat[frontNode][i]==1 && !vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n; i++){
            if(!vis[i]){
                    bfs(i,isConnected, vis);
                    cnt++;
            }

        }
         return cnt;
    }

};