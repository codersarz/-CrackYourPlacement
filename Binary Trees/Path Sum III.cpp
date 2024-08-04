//Brute-Force Approach
//Time-Complexity->O(n^2)
//Space-Complexity->O(h)
typedef long long ll;
    void solve(TreeNode* root,ll sum,int targetSum,int &count){
        if(root==NULL){
            return;
        }

        sum+=root->val;

        if(sum==targetSum){
            count++;
        }

        if(root->left!=NULL){
            solve(root->left,sum,targetSum,count);
        }
        if(root->right!=NULL){
            solve(root->right,sum,targetSum,count);
        }
    }
    void preorder(TreeNode* root,int targetSum,int &count){
        if(root==NULL){
            return;
        }

        solve(root,0,targetSum,count);

        preorder(root->left,targetSum,count);
        preorder(root->right,targetSum,count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        preorder(root,targetSum,count);

        return count;
    }
//Optimal-Solution (Using a map for storing sums we have got so far and checking if we got CurrSum-targetSum)
//Time-Complexity->O(n)
//Space-Complexity->O(h)
typedef long long ll;
    void dfs(TreeNode* root,ll currSum,unordered_map<ll,int> &prefixSumCount,int targetSum,int &count){
        if(root==NULL){
            return;
        }

        currSum+=root->val;

        if(prefixSumCount.find(currSum-targetSum)!=prefixSumCount.end()){
            count+=prefixSumCount[currSum-targetSum];
        }
        prefixSumCount[currSum]++;

        dfs(root->left,currSum,prefixSumCount,targetSum,count);
        dfs(root->right,currSum,prefixSumCount,targetSum,count);
        prefixSumCount[currSum]--;//Backtracking reduce the count
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll,int> prefixSumCount;
        prefixSumCount[0]=1;
        int count=0;
        dfs(root,0,prefixSumCount,targetSum,count);

        return count;
    }
