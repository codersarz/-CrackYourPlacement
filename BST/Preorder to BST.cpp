//OptimalSolution
//Time-Complexity->O(n)
//Space-Complexity->O(h)
Node* constructBST(int pre[],int &i,int n,int upper_bound){
        if(i==n||pre[i]>upper_bound){
            return NULL;
        }
        Node* root=newNode(pre[i++]);
        root->left=constructBST(pre,i,n,root->data);
        root->right=constructBST(pre,i,n,upper_bound);
        return root;
    } 
    Node* Bst(int pre[], int n) {
        int i=0;
        constructBST(pre,i,n,INT_MAX);
    }
