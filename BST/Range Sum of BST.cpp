// Approach-1(Brute Force) Using Inorder Traversal
//Time-Complexity->O(n)
//Space-Complexity->O(h)
int sum;
    void inorder(TreeNode* root,int low,int high){
        if(!root){
            return;
        }
        inorder(root->left,low,high);

        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }

        inorder(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum=0;
        inorder(root,low,high);
        return sum;
    }
// Approach-2(Optimal Solution) taking advantage of BST Property
//Time-Complexity->O(n)
//Space-Complexity->O(h)
int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root){
            return 0;
        }
        if(root->val>=low && root->val<=high){
            return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }
        if(root->val<low){
            return rangeSumBST(root->right,low,high);
        }
        return rangeSumBST(root->left,low,high);
    }
