//Time-Complexity->O(n)
//Space-Complexity->O(h)
void countNodes(Node* root,int &count,int l,int h){
        if(root==NULL){
            return;
        }
        
        if(root->data>h){
            countNodes(root->left,count,l,h);
        }
        else if(root->data<l){
            countNodes(root->right,count,l,h);
        }
        else{
            count++;
            countNodes(root->left,count,l,h);
            countNodes(root->right,count,l,h);
        }
    }
    int getCount(Node *root, int l, int h)
    {
        int count=0;
        countNodes(root,count,l,h);
        return count;
    }
