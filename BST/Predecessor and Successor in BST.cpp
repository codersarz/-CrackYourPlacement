//Brute-Force Approach
//Time-Complexity->O(n)
//Space-Complexity->O(n)
void inorderTraversal(Node* root, vector<int>& inorder) {
        if(root==NULL){
            return;
        }
        
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->key);
        inorderTraversal(root->right,inorder);
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
    
        auto itLower=lower_bound(inorder.begin(),inorder.end(),key);
        auto itUpper=upper_bound(inorder.begin(),inorder.end(),key);
    
        if(itLower!=inorder.begin()) {
            pre=new Node(*(itLower - 1));
        }else{
            pre=NULL;
        }
    
        if(itUpper!=inorder.end()) {
            suc=new Node(*itUpper);
        }else{
            suc=NULL;
        }
    }
//Optimal-Solution
//Time-Complexity->O(h)
//Space-Complexity->O(h)
void inorderSuccessor(Node* root,Node* &suc,int key){
        if(root==NULL){
            return;
        }

        if(root->key<=key){
            inorderSuccessor(root->right,suc,key);
        }
        else{
            suc=new Node(root->key);
            inorderSuccessor(root->left,suc,key);
        }
        
    }
    void inorderPredecessor(Node* root,Node* &pre,int key){
        if(root==NULL){
            return;
        }
        
        if(root->key>=key){
            inorderPredecessor(root->left,pre,key);
        }
        else{
            pre=new Node(root->key);
            inorderPredecessor(root->right,pre,key);
        }
        
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        suc=NULL;
        pre=NULL;
        inorderSuccessor(root,suc,key);
        inorderPredecessor(root,pre,key);
    }
