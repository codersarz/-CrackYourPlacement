//Time-Complexity->O(V+E)
//Space-Complexity->O(V)
void BFS(vector<int> adj[],int u,vector<bool> &vis,vector<int> &result){
        queue<int> q;
        
        q.push(u);
        vis[u]=true;
        result.push_back(u);
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            
            for(int &v:adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                    result.push_back(v);
                }
            }
        }
        
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<bool> vis(V,false);
        
        BFS(adj,0,vis,result);
        
        return result;
    }
