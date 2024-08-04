//Recursive
//Time-Complexity->O(h)
//Space-Complexity->O(h)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
//Iterative
//Time-Complexity->O(h)
//Space-Complexity->O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(p->val<root->val && q->val<root->val){
                root=root->left;
            }
            else if(p->val>root->val && q->val>root->val){
                root=root->right;
            }else{
                return root;
            }
        }
        return NULL;
    }
