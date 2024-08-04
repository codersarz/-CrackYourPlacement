//Time-Complexity->O(4^(n^2))
//Space-Complexity->O(n^2)
    int n;
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    vector<string> paths;
    void DFS(vector<vector<int>> &mat,int r,int c,string path,vector<vector<bool>> &vis){
        if(r==n-1 && c==n-1){
            paths.push_back(path);
            return;
        }
        
        vis[r][c]=true;
        
        for(int i=0;i<4;i++){
            int row=r+dr[i];
            int col=c+dc[i];
            if(row>=0 && row<n && col>=0 && col<n && mat[row][col]==1 && !vis[row][col]){
                if(dr[i]==0 && dc[i]==1){
                    path.push_back('R');
                }
                else if(dr[i]==1 && dc[i]==0){
                    path.push_back('D');
                }
                else if(dr[i]==0 && dc[i]==-1){
                    path.push_back('L');
                }
                else{
                    path.push_back('U');
                }
                
                DFS(mat,row,col,path,vis);
                
                path.pop_back();
            }
        }
        
        vis[r][c]=false;
        
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        n=mat[0].size();
        vector<vector<bool>> vis(n,vector<bool> (n,false));
        string path="";
        
        if(mat[0][0]==1){
            DFS(mat,0,0,path,vis);
        }
        
        return paths;
    }
