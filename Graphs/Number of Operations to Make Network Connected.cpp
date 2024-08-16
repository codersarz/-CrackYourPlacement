class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,0);
    }

    int find(int x){
        if(x==parent[x]){
            return x;
        }

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x==parent_y){
            return;
        }
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_y]>rank[parent_x]){
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }

        int components=n;
        DSU dsu(n);

        for(auto &edge:connections){
            int a=edge[0];
            int b=edge[1];
            if(dsu.find(a)!=dsu.find(b)){
                dsu.Union(a,b);
                components--;
            }
        }

        return components-1;
    }
};
