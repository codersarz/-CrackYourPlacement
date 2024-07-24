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
