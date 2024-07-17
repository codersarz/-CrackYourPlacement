//Inorder Traversal Approach
//Time-Complexity->O(n)
//Space-Complexity->O(h)
int minDiff=INT_MAX;
    void inorder(TreeNode* root,TreeNode* &prev){
        if(root==NULL){
            return;
        }
        inorder(root->left,prev);
        if(prev!=NULL){
            minDiff=min(minDiff,abs(root->val-prev->val));
        }
        prev=root;
        inorder(root->right,prev);
    }

    int getMinimumDifference(TreeNode* root) {
        
        TreeNode* prev=NULL;
        inorder(root,prev);

        return minDiff;
    }
