//Time-Complexity->O(n)
//Space-Complexity->O(n*h)
vector<vector<int>> paths;
    void solve(TreeNode* root,vector<int> &temp){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            paths.push_back(temp);
        }
        solve(root->left,temp);
        solve(root->right,temp);
        temp.pop_back();
    }

    string convertPathToString(vector<int> &path){
        if(path.empty()){
            return "";
        }
        string result=to_string(path[0]);
        for(int i=1;i<path.size();i++){
            result+="->"+to_string(path[i]);
        }
        return result;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> temp;
        solve(root,temp);
        vector<string> ans;
        for(auto &path:paths){
            ans.push_back(convertPathToString(path));
        }
        return ans;
    }
