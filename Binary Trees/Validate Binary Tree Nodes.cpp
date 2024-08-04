//Approach-1
//Time-Complexity->O(n)
//Space-Complexity->O(n)
bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>> adj;//Traversal
        unordered_map<int,int> parent;//Unique parents and Unique root

        for(int i=0;i<n;i++){
            int node=i;
            int leftC=leftChild[i];
            int rightC=rightChild[i];

            if(leftC!=-1){
                adj[node].push_back(leftC);
                if(parent.find(leftC)==parent.end()){
                    parent[leftC]=node;
                }else{
                    return false;
                }
            }
            if(rightC!=-1){
                adj[node].push_back(rightC);
                if(parent.find(rightC)==parent.end()){
                    parent[rightC]=node;
                }else{
                    return false;
                }
            }
        }

        int root=-1;
        for(int i=0;i<n;i++){
            if(parent.find(i)==parent.end()){
                if(root!=-1){
                    return false;
                }else{
                    root=i;
                }
            }
        }
        if(root==-1){
            return false;
        }

        //BFS or DFS Traversal
        int count=0;
        queue<int> q;
        vector<bool> visited(n,false);

        q.push(root);
        count=1;
        visited[root]=true;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int &v:adj[node]){
                if(!visited[v]){
                    visited[v]=true;
                    count++;
                    q.push(v);
                }
            }
        }

        return count==n;
    }
//Approach-2 (USING DSU)
//Time-Complexity->O(n*alpha(n)) approximately=>O(n)
//Space-Complexity->O(n)
vector<int> parent;
    int components;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    bool Union(int P,int C){
        if(find(C)!=C){
            return false;
        }
        if(find(P)==C){
            return false;
        }

        parent[C]=P;
        components--;

        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components=n;
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            int node=i;
            int lc=leftChild[i];
            int rc=rightChild[i];

            if(lc!=-1 && Union(node,lc)==false){
                return false;
            }  
            if(rc!=-1 && Union(node,rc)==false){
                return false;
            }
        }

        return components==1;
    }
