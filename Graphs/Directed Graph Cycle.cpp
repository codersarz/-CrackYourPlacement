//Using DFS Recursion
//Time-Complexity->O(V+E)
//Space-Complexity->O(V)
bool isCycleDFS(vector<int> adj[],int u,vector<bool> &vis,vector<bool> &inRecursion){
        vis[u]=true;
        inRecursion[u]=true;
        
        for(int &v:adj[u]){
            if(!vis[v] && isCycleDFS(adj,v,vis,inRecursion)){
                return true;
            }
            else if(inRecursion[v]){
                return true;
            }
        }
        
        inRecursion[u]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<bool> inRecursion(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i] && isCycleDFS(adj,i,vis,inRecursion)){
                return true;
            }
        }
        
        return false;
    }

//Using BFS (Kahn's Algorithm)
//Time-Complexity->O(V+E)
//Space-Complexity->O(V)
bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }    
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int nodeCount=0;
        while(!q.empty()){
            int u=q.front();
            nodeCount++;
            q.pop();
            
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        
        if(nodeCount==V){
            return false;
        }
        return true;
    }
