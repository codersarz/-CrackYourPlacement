//Approach-1 (Using Parent Pointers)
//Time-Complexity->O(n)
//Space-Complexity->O(n)

unordered_map<TreeNode*,TreeNode*> parent;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }

        if(root->left!=NULL){
            parent[root->left]=root;
        }
        inorder(root->left);
        if(root->right!=NULL){
            parent[root->right]=root;
        }
        inorder(root->right);
    }
    void BFS(TreeNode* target,int k,vector<int> &result){
        queue<TreeNode*>q;
        q.push(target);
        
        unordered_set<int> visited;
        visited.insert(target->val);
        int level=0;

        while(!q.empty()){
            int n=q.size();
            if(k==0)
                break;

            while(n--){
                auto node=q.front();
                q.pop();

                //Left
                if(node->left!=NULL && !visited.count(node->left->val)){
                    q.push(node->left);
                    visited.insert(node->left->val);
                }
                //Right
                if(node->right!=NULL && !visited.count(node->right->val)){
                    q.push(node->right);
                    visited.insert(node->right->val);
                }
                //Parent
                if(parent.count(node) && !visited.count(parent[node]->val)){
                    q.push(parent[node]);
                    visited.insert(parent[node]->val);
                }
            }
            k--;
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            result.push_back(node->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        inorder(root);

        BFS(target,k,result);

        return result;
    }
