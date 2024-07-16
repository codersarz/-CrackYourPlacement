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
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int>temp;

        solve(root,temp);

        for(auto &path:paths){
            int sum=0;
            for(int i=0;i<path.size();i++){
                sum+=path[i];
            }
            if(sum==targetSum){
                return true;
            }
        }

        return false;
    }
//Optimal Approach
//Time-Complexity->O(N)
//Space->Complexity->O(H)
bool solve(TreeNode* root,vector<int> &temp,int sum,int targetSum){
        if(root==NULL){
            return false;
        }
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                return true;
            }
            return false;
        }

        return solve(root->left,temp,sum,targetSum)||solve(root->right,temp,sum,targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum=0;
        return solve(root,temp,sum,targetSum);
    }
