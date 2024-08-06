//Time-Complexity->O(V+E)
//Space-Complexity->O(V+E)
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);

        for(auto &v:prerequisites){
            int a=v[0];
            int b=v[1];
            //b--->a
            adj[b].push_back(a);
            indegree[a]++;
        }

        vector<int> ans;
        int count=0;

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            count++;
            
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        if(count==numCourses){
            return ans;
        }
        return {};
    }
