//Time-Complexity->O(n*m) No. of Nodes in Tree = n and No. of Nodes in Subtree = m
//Space-Complexity->O(height of tree + height of subtree) => O(n+m) Worst Case when both Trees are skewed
bool isSameTree(TreeNode* p,TreeNode* q){
        if(p==NULL||q==NULL){
            return p==q;
        }
        return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        if(isSameTree(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
