//Using Level Order Traversal
//Time-Complexity->O(n)
//Space-Complexity->O(n)

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string s="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            if(node==NULL){
                s.append("#,");
            }else{
                s.append(to_string(node->val)+',');
            }
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }
            else{
                TreeNode* rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};
