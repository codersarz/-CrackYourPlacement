//Cycle Detection Using DFS
//Time-Complexity->O(V+E)
//Space-Complexity->O(V)
bool isCycleDFS(vector<int> adj[],int u,vector<bool> &vis,int parent){
        vis[u]=true;
        
        for(int &v:adj[u]){
            if(v==parent) continue;
            
            if(vis[v]){
                return true;
            }
            if(isCycleDFS(adj,v,vis,u)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i] && isCycleDFS(adj,i,vis,-1)){
                return true;
            }
        }

//Cycle Detection Using BFS
//Time-Complexity->O(V+E)
//Space-Complexity->O(V)
bool isCycleBFS(vector<int> adj[],int u, vector<bool> &vis){
        queue<pair<int,int>> q;
        q.push({u,-1});
        vis[u]=true;
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
             for(int &v:adj[node]){
                 if(!vis[v]){
                     vis[v]=true;
                     q.push({v,node});
                 }else if(v!=parent){
                     return true;
                 }
             }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i] && isCycleBFS(adj,i,vis)){
                return true;
            }
        }
        
        return false;
    }
