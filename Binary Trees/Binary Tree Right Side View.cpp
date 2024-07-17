//Approach-1(DFS Recursive)
//Time-Complexity->O(n)
//Space-Complexity->O(h)
void solve(TreeNode* root,int depth,vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(ans.size()==depth){
            ans.push_back(root->val);
        }
            
        solve(root->right,depth+1,ans);
        solve(root->left,depth+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,0,ans);

        return ans;
    }
//Appraoch-2(BFS Level Order Traversal)
//Time-Complexity->O(n)
//Space-Complexity->O(n)
vector<int> rightSideView(TreeNode* root) {
         vector<int> v;
       
       if(root == NULL){
           return v;
       }
       
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
           
           int n = q.size();
           for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(i == n-1){
                    v.push_back(temp->val);
                }
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
                
           }
           
       }
       return v;
    }
