//BFS Approach(Iterative)
//Time-Complexity->O(n)
//Space-Complexity->O(n)
 int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto node=q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            depth++;
        }

        return depth;
    }

//DFS Approach(Recursive)
//Time-Complexity->O(n)
//Space-Complexity->O(h) => Worst-Case->O(n) Skewed Tree, Best-Case->O(logn) Balanced Tree
int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        if(root->left==NULL){
            return 1+maxDepth(root->right);
        }
        if(root->right==NULL){
            return 1+maxDepth(root->left);
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
