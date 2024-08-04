//DFS
int n;
void DFS(vector<vector<int>> &isConnected,int u, vector<bool> &vis){
        vis[u]=true;

        for(int v=0;v<n;v++){
            if(!vis[v] && isConnected[u][v]==1){
                DFS(isConnected,v,vis);
            }
        }
    }
int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        int count=0;
        vector<bool> vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(isConnected,i,vis);
                count++;
            }
        }
        
        return count;
    }
//BFS
void BFS(unordered_map<int,vector<int>> &adj,int u,vector<bool> &vis){
        queue<int> q;
        vis[u]=true;
        q.push(u);

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int &v:adj[curr]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<bool> vis(n,false);
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                BFS(adj,i,vis);
                count++;
            }
        }

        return count;
    }
