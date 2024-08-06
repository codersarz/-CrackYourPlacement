//Using BFS(Kahn's Algorithm)
//Time-Complexity->O(V+E)
//Space-Complexity->O(V+E)
bool topologicalSortCheck(unordered_map<int,vector<int>> &adj,int n,vector<int> &indegree){
        queue<int> q;

        int count=0;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            count++;

            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        return count==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);

        for(auto &v:prerequisites){
            int a=v[0];
            int b=v[1];
            //b--->a
            adj[b].push_back(a);
            indegree[a]++;
        }

        //if cycle is present not possible since deadlock condition
        return topologicalSortCheck(adj,numCourses,indegree);
    }

//using DFS
//Time-Complexity->O(V+E)
//Space-Complexity->O(V+E)
bool isCycleDFS(unordered_map<int,vector<int>> &adj,int u,vector<bool> &vis,vector<bool> &inRecursion){
        vis[u]=true;
        inRecursion[u]=true;

        for(int &v:adj[u]){
            if(!vis[v] && isCycleDFS(adj,v,vis,inRecursion)){
                return true;
            }
            if(inRecursion[v]){
                return true;
            }
        }
        
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>> adj;
        vector<bool> vis(n,false);
        vector<bool> inRecursion(n,false);

        for(auto &v:prerequisites){
            int a=v[0];
            int b=v[1];
            //b--->a
            adj[b].push_back(a);
        }

        //if cycle is present not possible since deadlock condition
        for(int i=0;i<n;i++){
            if(!vis[i] && isCycleDFS(adj,i,vis,inRecursion)){
                return false; 
            }
        }

        return true;
    }
