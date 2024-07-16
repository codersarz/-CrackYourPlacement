//Brute-Force takes 3 traversals of the tree but also works when both p and q are not present in the binary tree.
//Time-Complexity->O(n)
//Space-Complexity->O(h)
bool findPath(TreeNode* root, vector<TreeNode*>& path, int k) {
    if (root == NULL) return false;
    
    path.push_back(root);
    
    if (root->val == k) return true;
    
    if (findPath(root->left, path, k) || findPath(root->right, path, k)) return true;
    
    path.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path1, path2;
    
    if (!findPath(root, path1, p->val) || !findPath(root, path2, q->val)) return NULL;
    
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); ++i) {
        if (path1[i] != path2[i]) {
            break;
        }
    }
    
    return path1[i - 1];
}
//Optimal Solution takes only 1 traversal of binary tree but only gives correct answer under the assumption that both p and q are present in the tree.
//Time-Complexity->O(n)
//Space-Complexity->O(h)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL){
            return root;
        }
        if(left!=NULL){
            return left;
        }
        return right;
    }
