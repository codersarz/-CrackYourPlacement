//Optimal-Solution
//Time-Complexity->O((n)
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
