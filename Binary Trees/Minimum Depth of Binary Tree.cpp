//BFS Approach(Iterative)
//Time-Complexity->O(n)
//Space-Complexity->O(n)
int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto node=q.front();
                q.pop();
                if(node->left==NULL && node->right==NULL){
                    return depth;
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            depth++;
        }

        return -1;
    }

//DFS Approach(Recursive)
//Time-Complexity->O(n)
//Space-Complexity->O(h) => Worst-Case->O(n) Skewed Tree, Best-Case->O(logn) Balanced Tree
int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        if(root->left==NULL){
            return 1+minDepth(root->right);
        }
        if(root->right==NULL){
            return 1+minDepth(root->left);
        }
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
