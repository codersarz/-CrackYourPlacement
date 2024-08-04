//Time-Complexity->O(n)
//Space-Complexity->O(n)
vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        if(root == NULL){
            return v;
        }

        while(!q.empty()){
            int x = q.size();
            vector<int> v1(x);

            for(int i=0; i<x;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(level == 0){
                        v1[i] = temp->val;
                }
                else{
                        v1[x-i-1] = temp->val;
                }
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            v.push_back(v1);
            level = !level;
        }
        return v;
    }
