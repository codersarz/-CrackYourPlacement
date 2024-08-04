//Appraoch-1 (Using Parent Pointer)
//Time-Complexity->O(n)
//Space-Complexity->O(h)
int solve(TreeNode* curr,TreeNode* parent){
        if(curr==NULL){
            return 0;
        }

        if(curr->left==NULL && curr->right==NULL){
            if(parent!=NULL && parent->left==curr){
                return curr->val;
            }
        }

        return solve(curr->left,curr)+solve(curr->right,curr);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,NULL);
    }
//Approach-2 (Using a bool Variable isLeft)
//Time-Complexity->O(n)
//Space-Complexity->O(h)
int solve(TreeNode* curr,bool isLeft){
        if(curr==NULL){
            return 0;
        }

        if(curr->left==NULL && curr->right==NULL){
            if(isLeft){
                return curr->val;
            }
        }

        return solve(curr->left,true)+solve(curr->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,false);
    }
