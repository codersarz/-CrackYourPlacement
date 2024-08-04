//Time-Complexity->O(n^2)
//Space-Compelxity->O(n^2)
    int dx[8]={1,2,2,1,-1,-2,-2,-1};
    int dy[8]={2,1,-1,-2,-2,-1,1,2};
    
    int BFS(vector<vector<bool>> &vis,int startX,int startY,int endX,int endY,int n){
        int distance=0;
        
        queue<pair<int,int>> q;
        q.push({startX,startY});
        vis[startX][startY]=true;
        
        while (!q.empty()) {
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if (x==endX && y==endY) {
                    return distance;
                }
                
                for (int i=0;i<8;i++) {
                    int row=x+dx[i];
                    int col=y+dy[i];
                    if (row>=0&&row<n&&col>=0&&col<n&&!vis[row][col]){
                        q.push({row,col});
                        vis[row][col]=true;
                    }
                }
            }
            distance++;
        }
        
        return -1;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    vector<vector<bool>> vis(n,vector<bool> (n,false));
	    int startX=KnightPos[0]-1;
	    int startY=KnightPos[1]-1;
	    int endX=TargetPos[0]-1;
	    int endY=TargetPos[1]-1;
	    
	    if(startX==endX && startY==endY){
	        return 0;
	    }
	    
	    return BFS(vis,startX,startY,endX,endY,n);
	}
