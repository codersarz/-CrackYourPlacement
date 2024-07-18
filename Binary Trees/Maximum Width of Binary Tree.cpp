//Approach-1 (Using BFS)
//Time-Complexity->O(n)
//Space-Complexity->O(n)
typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll maxW=0;

        while(!q.empty()){
            int n=q.size();
            ll L=q.front().second;
            ll R=q.back().second;
            maxW=max(maxW,R-L+1);
            while(n--){
                auto node=q.front().first;
                ll idx=q.front().second;
                q.pop();

                if(node->left!=NULL){
                    q.push({node->left,2*idx+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,2*idx+2});
                }
            }
        }

        return maxW;
    }
