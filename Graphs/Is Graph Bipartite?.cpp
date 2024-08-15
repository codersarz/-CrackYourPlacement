//Using DFS
class Solution {
public:
    bool checkBipartite(vector<vector<int>>& adj,int curr,vector<int> &color,int currColor){
        color[curr]=currColor;
        for(int &v:adj[curr]){
            if(color[v]==currColor){
                return false;
            }
            if(color[v]==-1){
                int colorOfV=1-currColor;
                if(checkBipartite(adj,v,color,colorOfV)==false){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V,-1);

        //red=1
        //green=0

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(checkBipartite(graph,i,color,1)==false){
                    return false;
                }
            }
        }

        return true;
    }
};

//Using BFS
class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>>& adj,vector<int> &color,int curr,int currColor){
        queue<int> q;
        q.push(curr);
        color[curr]=currColor;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int &v:adj[u]){
                if(color[v]==color[u]){
                    return false;
                }
                if(color[v]==-1){
                    if(checkBipartiteBFS(adj,color,v,1-color[u])==false){
                        return false;
                    }
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V,-1);

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(checkBipartiteBFS(graph,color,i,1)==false){
                    return false;
                }
            }
        }

        return true;
    }
};
