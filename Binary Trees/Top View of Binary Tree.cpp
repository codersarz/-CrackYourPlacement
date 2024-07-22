vector<int> topView(Node *root)
    {
        if(root==NULL){
            return {};
        }
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int x=it.second;
            if(mp.find(x)==mp.end()){
                mp[x]=node->data;
            }
            
            if(node->left!=NULL){
                q.push({node->left,x-1});
            }
            if(node->right!=NULL){
                q.push({node->right,x+1});
            }
        }
        
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
