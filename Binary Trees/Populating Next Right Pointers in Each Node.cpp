Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        Node *curr=root;
        while(curr->left!=NULL){
            Node* temp=curr;
            while(curr!=NULL){
                curr->left->next=curr->right;
                if(curr->next==NULL){
                    curr->right->next=NULL;
                }else{
                    curr->right->next=curr->next->left;
                }
                curr=curr->next;
            }
            curr=temp->left;
        }

        return root;
    }
//Approach-2 (Using Level Order Traversal)
Node* connect(Node* root) {
        if(root==NULL)return root;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node *t=q.front();
                q.pop();
                if(t->left!=NULL)q.push(t->left);
                if(t->right!=NULL)q.push(t->right);
                Node *temp=q.front();
                t->next=temp;
                if(i==n-1)t->next=NULL;
            }
        }
        return root;
    }
