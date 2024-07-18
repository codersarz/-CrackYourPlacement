//Make Graph + BFS 
//Time-Complexity->O(n)
//Space-Complexity->O(n)
void makeGraph(Node* root,Node* prev,Node* &src,unordered_map<Node*,vector<Node*>>&adj,int a){
        if(root==NULL){
            return;
        }
        if(root->data==a){
            src=root;
        }
        if(prev!=NULL){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        
        makeGraph(root->left,root,src,adj,a);
        makeGraph(root->right,root,src,adj,a);
    }
    int findDist(Node* root, int a, int b) {
        unordered_map<Node*,vector<Node*>>adj;
        Node* src=NULL;
        
        makeGraph(root,NULL,src,adj,a);
        
        queue<Node*> q;
        unordered_set<Node*> vis;
        q.push(src);
        vis.insert(src);
        int ans=0;
        int distance=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto node=q.front();
                q.pop();
                
                if(node->data==b){
                    ans=distance;
                    break;
                }
                
                for(auto &ngbr:adj[node]){
                    if(!vis.count(ngbr)){
                        q.push(ngbr);
                        vis.insert(ngbr);
                    }
                }
            }
            distance++;
        }
        
        return ans;
    }
