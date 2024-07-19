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
