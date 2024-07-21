//Using Level Order Traversal
//Time-Complexity->O(n*logn)
//Space-Complexity->O(n)
vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto node=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();

            mp[x][y].insert(node->val);
            if(node->left!=NULL){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right!=NULL){  
                q.push({node->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto &v:mp){
            vector<int> col;
            for(auto &k:v.second){
                col.insert(col.end(),k.second.begin(),k.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
