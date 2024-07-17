//Naive Approach
//Time-Complexity->O(n^2)
//Space-Complexity->O(h)
int getHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        
        return (abs(getHeight(root->left)-getHeight(root->right))<=1) && isBalanced(root->left) && isBalanced(root->right);
    }
//Optimal Approach
//Time-Complexity->O(n)
//Space-Complexity->O(h)
int checkBalanced(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int lh=checkBalanced(root->left);
        if(lh==-1){
            return -1;
        }

        int rh=checkBalanced(root->right);
        if(rh==-1){
            return -1;
        }
        
        if(abs(lh-rh)>1){
            return -1;
        }

        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root)!=-1;
    }
