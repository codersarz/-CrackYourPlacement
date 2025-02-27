//Time-Complexity-> O(n)
//Space-Complexity->O(n)
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) { 
        if(root1==NULL && root2==NULL){
            return NULL;
        }
        if(root1==NULL){
            return root2;
        }
        if(root2==NULL){
            return root1;
        }

        TreeNode* root=new TreeNode(root1->val+root2->val);
        root->left=mergeTrees(root1->left,root2->left);
        root->right=mergeTrees(root1->right,root2->right);

        return root;
    }
