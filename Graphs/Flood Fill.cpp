//Using DFS
//Time-Complexity->O(m*n)
//Space-Complexity->O(m*n)
    int m,n;
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    void DFS(vector<vector<int>>& image,int r,int c,int color,int originalColor){
        if(image[r][c] != originalColor) return;
        image[r][c] = color;
        for(int i=0;i<4;i++){
            int row=r+dr[i];
            int col=c+dc[i];
            if(row>=0 && row<m && col>=0 && col<n){
                DFS(image,row,col,color,originalColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        int originalColor=image[sr][sc];

        if(image[sr][sc]!=color){
            DFS(image,sr,sc,color,originalColor);
        }

        return image;
    }
