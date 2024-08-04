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
//Approach-2 (Using LCA Concept:Minimum Distance between two nodes will be through LCA of them)
//Time-Complexity->O(n)
//Space-Complexity->O(h)
Node *lca(Node* root,int a,int b){
        if(root==NULL){
            return NULL;
        }
        
        if(root->data==a || root->data==b){
            return root;
        }
        
        Node* left=lca(root->left,a,b);
        Node* right=lca(root->right,a,b);
        
        if(left!=NULL && right!=NULL){
            return root;
        }
        if(left==NULL){
            return right;
        }
        return left;
    }
    
    int DistFromLCA(Node* root,int target,int distance){
        if(root==NULL){
            return -1;
        }
        if(root->data==target){
            return distance;
        }
        int left=DistFromLCA(root->left,target,distance+1);
        if(left!=-1){
            return left;
        }
        return DistFromLCA(root->right,target,distance+1);
        
    }
    int findDist(Node* root, int a, int b) {
         Node* LCA=lca(root,a,b);
         
         int d1=DistFromLCA(LCA,a,0);
         int d2=DistFromLCA(LCA,b,0);
         
         return d1+d2;
    }
