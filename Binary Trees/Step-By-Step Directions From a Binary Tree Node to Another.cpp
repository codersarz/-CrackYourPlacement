//Approach-1
//Time-Complexity->O(N)
//Space-Complexity->O(N)
TreeNode* lca(TreeNode* root,int src,int dest){
        if(root==NULL){
            return NULL;
        }
        if(root->val==src || root->val==dest){
            return root;
        }
        TreeNode* left=lca(root->left,src,dest);
        TreeNode* right=lca(root->right,src,dest);
        if(left!=NULL && right!=NULL){
            return root;
        }
        if(left==NULL){
            return right;
        }
        return left;
    }
    bool findPath(TreeNode* LCA,int target,string &path){
        if(LCA==NULL){
            return false;
        }
        if(LCA->val==target){
            return true;
        }

        path.push_back('L');
        if(findPath(LCA->left,target,path)==true){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(LCA->right,target,path)==true){
            return true;
        }
        path.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA=lca(root,startValue,destValue);//O(n)
        string lcaTOsrc="";
        string lcaTOdest="";

        findPath(LCA,startValue,lcaTOsrc);//O(n)
        findPath(LCA,destValue,lcaTOdest);//O(n)

        string ans="";
        for(int i=0;i<lcaTOsrc.length();i++){//O(n)
            ans.push_back('U');
        }
        ans+=lcaTOdest;

        return ans;
    }
//Approach-2 (More-Optimized Solution)
//Time-Complexity->O(N)
//Space-Complexity->O(N)
bool findPath(TreeNode* root,int target,string &path){
        if(root==NULL){
            return false;
        }
        if(root->val==target){
            return true;
        }

        path.push_back('L');
        if(findPath(root->left,target,path)==true){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right,target,path)==true){
            return true;
        }
        path.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootTOSrc="";
        string rootTODes="";

        findPath(root,startValue,rootTOSrc);//O(n)
        findPath(root,destValue,rootTODes);//O(n)

        int l=0;//Common Path Length
        while(l<rootTOSrc.length() && l<rootTODes.length()){
            if(rootTODes[l]==rootTOSrc[l]){
                l++;
            }
            else break;
        }

        string ans="";
        for(int i=l;i<rootTOSrc.length();i++){
            ans.push_back('U');
        }
        for(int i=l;i<rootTODes.length();i++){
            ans.push_back(rootTODes[i]);
        }

        return ans;
    }
