//Time-Complexity->O(N)
//Space-Complexity->O(h)
bool isBST(TreeNode* root,long long start,long long end){
        if(root==NULL){
            return true;
        }

        if(root->val<=start || root->val>=end){
            return false;
        }

        return isBST(root->left,start,root->val) && isBST(root->right,root->val,end);
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
    }
