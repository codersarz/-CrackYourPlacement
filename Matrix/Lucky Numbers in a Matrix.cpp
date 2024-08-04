//Approach-1
//Time-Complexity->O(m*n)
//Space-Complexity->O(m+n)
vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> rowMin(m);
        vector<int> colMax(n);
        vector<int> ans;

        for(int r=0;r<m;r++){
            int minEl=INT_MAX;
            for(int c=0;c<n;c++){
                minEl=min(minEl,matrix[r][c]);
            }
            rowMin[r]=minEl;
        }

        for(int c=0;c<n;c++){
            int maxEl=INT_MIN;
            for(int r=0;r<m;r++){
                maxEl=max(maxEl,matrix[r][c]);
            }
            colMax[c]=maxEl;
        }

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(matrix[r][c]==rowMin[r] && matrix[r][c]==colMax[c]){
                    ans.push_back(matrix[r][c]);
                }
            }
        }

        return ans;
    }
//Approach-2 (Greedy- Only One Lucky Number can Exist or None)
vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int rMinMax=INT_MIN;
        for(int r=0;r<m;r++){
            int rMin=INT_MAX;
            for(int c=0;c<n;c++){
                rMin=min(rMin,matrix[r][c]);
            }
            rMinMax=max(rMin,rMinMax);
        }

        int cMaxMin=INT_MAX;
        for(int c=0;c<n;c++){
            int cMax=INT_MIN;
            for(int r=0;r<m;r++){
                cMax=max(cMax,matrix[r][c]);
            }
            cMaxMin=min(cMax,cMaxMin);
        }

        if(rMinMax==cMaxMin){
            return {cMaxMin};
        }

        return {};
    }
