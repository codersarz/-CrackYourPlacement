//Approach-1
//Time-Complexity->O(n)
//Space-Complexity->O(n)
unordered_set<TreeNode*> covered;
    int cameras;
    void dfs(TreeNode* root,TreeNode* parent){
        if(root==NULL){
            return;
        }
        dfs(root->left,root);
        dfs(root->right,root);

        if(parent==NULL && (!covered.count(root) || !covered.count(root->left) || !covered.count(root->right))){
            cameras++;
            covered.insert(root);
            covered.insert(parent);
            covered.insert(root->left);
            covered.insert(root->right);
        }
    }
    int minCameraCover(TreeNode* root) {
        cameras=0;
        covered.insert(NULL);
        dfs(root,NULL);
        return cameras;
    }
//Approach-2
//Time-Complexity->O(n)
    //3 types of nodes
    //1->No camera,Not being watched
    //2->No camera,being Watched
    //3->camera,being Watched
    int cameras;
    int solve(TreeNode* root){
        if(root==NULL){
            return 2;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        if(left==1 || right==1){
            cameras++;
            return 3;
        }
        if(left==3 || right==3){
            return 2;
        }
        return 1;
    }
    int minCameraCover(TreeNode* root) {
        cameras=0;
        if(solve(root)==1){
            cameras++;
        }
        return cameras;
    }
