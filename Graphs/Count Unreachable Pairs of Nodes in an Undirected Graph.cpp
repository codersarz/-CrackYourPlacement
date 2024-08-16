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
        else if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_x]=parent_y;;
            rank[parent_y]++;
        }
    }

};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            dsu.Union(u,v);
        }

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int parent=dsu.find(i);
            mp[parent]++;
        }

        long long pairs=0;
        long long remaining=n;
        for(auto &it:mp){
            long long size=it.second;
            pairs+=(remaining-size)*size;
            remaining-=size;
        }

        return pairs;
    }
};
