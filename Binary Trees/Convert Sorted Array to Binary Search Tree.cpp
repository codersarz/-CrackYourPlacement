//Time-Complexity->O(n) since We are traversing all nodes.
//Space-Complexity->O(n) for TreeNodes

TreeNode* makeTree(vector<int>& nums,int l,int r){
        if(l>r){
            return NULL;
        }
        int mid=l+(r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=makeTree(nums,l,mid-1);
        root->right=makeTree(nums,mid+1,r);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return new TreeNode(nums[0]);
        }
        return makeTree(nums,0,n-1);;
    }
