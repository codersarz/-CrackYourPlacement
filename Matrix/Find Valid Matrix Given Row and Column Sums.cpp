//Time-Complexity->O(m+n)
//Greedy Approach
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();

        vector<vector<int>> matrix(m,vector<int> (n,0));

        int i=0;//row
        int j=0;//col
        while(i<m && j<n){
            matrix[i][j]=min(rowSum[i],colSum[j]);
            rowSum[i]-=matrix[i][j];
            colSum[j]-=matrix[i][j];
            if(rowSum[i]==0){
                i++;
            }
            if(colSum[j]==0){
                j++;
            }
        }

        return matrix;
    }
