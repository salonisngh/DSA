class Solution {
public:
    bool canFinish(int numCourse, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourse);

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]); 
        }

        
        vector<int> indegree(numCourse,0);
        for(int i=0;i<numCourse;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q; vector<int>topo;
        for(int i=0;i<numCourse; i++){
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }

        }
        if(topo.size()==numCourse) return true;
        return false;
    }
};