//Brute-Force Approach
//Time-Complexity->O(n^2)
bool isBST(Node* root,int start,int end){
        if(root==NULL){
            return true;
        }
        
        if(root->data<=start || root->data>=end){
            return false;
        }
        
        return isBST(root->left,start,root->data) && isBST(root->right,root->data,end);
    }
    int getSize(Node *root){
        if(root==NULL){
            return 0;
        }
        return 1+getSize(root->left)+getSize(root->right);
    }
    int maxSize;
    void solve(Node *root){
        if(root==NULL){
            return;
        }
        
        if(isBST(root,INT_MIN,INT_MAX)){
            maxSize=max(maxSize,getSize(root));
        }
        
        solve(root->left);
        solve(root->right);
    }
    int largestBst(Node *root)
    {
        maxSize=INT_MIN;
        
        solve(root);
        
        return maxSize;
    }
//Optimal-Solution
//Time-Complexity->O(n)
struct node1{
        int isbst;
        int size;
        int mn;
        int mx;
    };
    struct node1 bst(Node *root){
        struct node1 x;
        if(root==NULL){
            x.isbst=1;
            x.size=0;
            x.mn=INT_MAX;
            x.mx=INT_MIN;
            return x;
        }
        struct node1 left = bst(root->left);
        struct node1 right = bst(root->right);
        if(left.isbst==1 && right.isbst==1 && root->data>left.mx && root->data<right.mn){
            x.isbst=1;
            x.size=1+left.size+right.size;
            x.mx=max(root->data,right.mx);
            x.mn=min(root->data,left.mn);
        }
        else{
            x.isbst = 0;
            x.size = max(left.size,right.size);
            x.mn=INT_MAX;
            x.mx = INT_MIN;
        }
        return x;
    }
    int largestBst(Node *root)
    {
    	return bst(root).size;
    }
