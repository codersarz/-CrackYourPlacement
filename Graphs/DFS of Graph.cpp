//Time-Complexity->O(V+E)
//Space-Complexity->O(V)
void DFS(vector<int> adj[],int u,vector<bool> &vis,vector<int> &result){
        if(vis[u]==true){
            return;
        }
        
        vis[u]=true;
        result.push_back(u);
        
        for(auto &v:adj[u]){
            if(!vis[v]){
                DFS(adj,v,vis,result);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<int> result;
        
        DFS(adj,0,vis,result);
        
        return result;
    }
