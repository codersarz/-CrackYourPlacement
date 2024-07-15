//Time-Complexity->O(n)
//Space-Complexity->O(n)

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        set<int> childSet;
        for(auto &description:descriptions){
            int parent=description[0];
            int child=description[1];
            int isLeft=description[2];
            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }

            if(isLeft==1){
                mp[parent]->left=mp[child];
            }else{
                mp[parent]->right=mp[child];
            }
            
            childSet.insert(child);
        }

        //Find root
        for(auto &description:descriptions){
            int parent=description[0];
            if(childSet.count(parent)==0){
                return mp[parent];
            }
        }

        return NULL;
    }
