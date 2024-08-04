//Approach-1
//Time-Complexity->O(n)
//Space-Complexity->O(n)
void make(set<int> &leaf,set<int> &nodes,Node* root){
        if(!root){
            return;
        }
        
        nodes.insert(root->data);
        if(root->left==NULL && root->right==NULL){
            leaf.insert(root->data);
        }
        
        make(leaf,nodes,root->left);
        make(leaf,nodes,root->right);
    }
    bool isDeadEnd(Node *root)
    {
        set<int> nodes,leaf;
        make(leaf,nodes,root);
        
        for(auto l:leaf){
            if(nodes.count(l+1) && (nodes.count(l-1) || l==1)){
                return true;
            }
        }
        
        return false;
    }

//Optimal-Solution
//Time-Complexity->O(n)
//Space-Complexity->O(h)
bool solve(Node* root,int start,int end){
        if(!root){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if(root->data-start==1 && end-root->data==1){
                return true;
            }
            return false;
        }
        
        return solve(root->left,start,root->data)||solve(root->right,root->data,end);
    }
    bool isDeadEnd(Node *root)
    {
        int start=0,end=INT_MAX;
        return solve(root,start,end);
    }
