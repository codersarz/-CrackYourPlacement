//Approach-1 (Using DFS)
//Time-Complexity->O(m*n)
//Space-Complexity->O(m*n)
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    int m,n;
    void DFS(vector<vector<char>>& grid,vector<vector<bool>> &vis,int r,int c){
        vis[r][c]=true;

        for(int i=0;i<4;i++){
            int row=r+dr[i];
            int col=c+dc[i];
            if(row>=0 && row<m && col>=0 && col<n && grid[row][col]=='1' && !vis[row][col]){
                DFS(grid,vis,row,col);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();//rows
        n=grid[0].size();//cols
        int island=0;
        vector<vector<bool>> vis(m,vector<bool> (n,false));

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]=='1' && !vis[r][c]){
                    DFS(grid,vis,r,c);
                    island++;
                }
            }
        }

        return island;
    }
//Approach-1 (Using BFS)
//Time-Complexity->O(m*n)
//Space-Complexity->O(m*n)
int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    int m,n;
    void BFS(vector<vector<char>>& grid,vector<vector<bool>> &vis,int r,int c){
        vis[r][c]=true;
        queue<pair<int,int>> q;
        q.push({r,c});

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int row=r+dr[i];
                int col=c+dc[i];
                if(row>=0 && row<m && col>=0 && col<n && !vis[row][col] && grid[row][col]=='1'){
                    q.push({row,col});
                    vis[row][col]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();//rows
        n=grid[0].size();//cols
        int island=0;
        vector<vector<bool>> vis(m,vector<bool> (n,false));

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]=='1' && !vis[r][c]){
                    BFS(grid,vis,r,c);
                    island++;
                }
            }
        }

        return island;
    }
