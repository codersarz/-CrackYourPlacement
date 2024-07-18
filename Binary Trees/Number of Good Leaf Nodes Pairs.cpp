//Graph Conversion + BFS Method
//Time-Complexity->O(N^2)
//Space-Complexity->O(N)
void makeGraph(TreeNode* root,TreeNode* prev,unordered_map<TreeNode*,vector<TreeNode*>> &adj,unordered_set<TreeNode*> &st){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            st.insert(root);
        }

        if(prev!=NULL){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left,root,adj,st);
        makeGraph(root->right,root,adj,st);
    }
    int countPairs(TreeNode* root, int distance) {
       unordered_map<TreeNode*,vector<TreeNode*>> adj;//Graph
       unordered_set<TreeNode*> st;//Leaf Nodes
        //SC->O(n)
        makeGraph(root,NULL,adj,st);//O(n)

        int count=0;//Count of leaf Node pairs

        //TC->O(n^2)
        for(auto &leaf:st){//proportional to number of nodes in the tree ~ O(n)

            //BFS hit karo and see if you can find another leaf nodes within distance
            queue<TreeNode*> q;
            unordered_set<TreeNode*> vis;
            q.push(leaf);
            vis.insert(leaf);

            for(int level=0;level<=distance;level++){// only go till level<=distance
                int n=q.size();
                while(n--){
                    auto curr=q.front();
                    q.pop();

                    if(curr!=leaf && st.count(curr)){
                        count++;
                    }
                    for(auto &ngbr:adj[curr]){
                        if(!vis.count(ngbr)){
                            q.push(ngbr);
                            vis.insert(ngbr);
                        }
                    }
                }
            }
        }

        return count/2;
    }
