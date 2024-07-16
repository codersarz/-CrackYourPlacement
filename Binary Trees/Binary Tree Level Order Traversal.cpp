//Time-Complexity->O(N)
//Space-Complexity->O(N)
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);

        if(root == NULL){
            return v;
        }

        while(!q.empty()){
            int x = q.size();
            vector<int> v1;
            while(x--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
                v1.push_back(temp->val);
            }
            v.push_back(v1);
        }
        return v;
    }
