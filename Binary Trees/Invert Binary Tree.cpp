//Approach-1 (Recursive)
//Time Complexity-> O(n)
//Space Complexity-> O(height of Tree) since Recursion would take stack space
TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        
        root->left=right;
        root->right=left;

        return root;
    }

//Approach-2 (Using Level Order Traversal BFS)
//Time Complexity-> O(n)
//Space Complexity-> O(n) since we are using a Queue
TreeNode* invertTree(TreeNode* root) {
       if(root==NULL){
            return NULL;
       }
       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
            auto node=q.front();
            q.pop();

            swap(node->left,node->right);

            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
       }

       return root;
    }
