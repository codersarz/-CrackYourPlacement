//Brute-Force
//Time-Complexity->O(N+H*2^H)
//Space-Complexity->O(N*H)
vector<vector<int>> paths;
    void solve(TreeNode* root,vector<int> &temp){
        if(root==NULL){
            return;
        }

        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            paths.push_back(temp);
        }
        if(root->left!=NULL){
            solve(root->left,temp);
        }
        if(root->right!=NULL){
            solve(root->right,temp);
        }
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;

        solve(root,temp);

        vector<vector<int>> ans;
        for(auto &path:paths){
            int sum=0;
            for(int i=0;i<path.size();i++){
                sum+=path[i];
            }
            if(sum==targetSum){
                ans.push_back(path);
            }
        }

        return ans;
    }
//Optimal-Approach
//Time-Complexity->O(N)
//Space-Complexity->O(H)
vector<vector<int>> ans;
    void solve(TreeNode* root,vector<int> &temp,int sum,int targetSum){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
            }
        }
        if(root->left!=NULL){
            solve(root->left,temp,sum,targetSum);
        }
        if(root->right!=NULL){
            solve(root->right,temp,sum,targetSum);
        }
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum=0;
        solve(root,temp,sum,targetSum);

        return ans;
    }
