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
        }else if(rank[parent_y]>rank[parent_x]){
            parent[parent_x]=parent_y;
        }else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }
    
};
class Solution
{
    public:
        
	int detectCycle(int V, vector<int>adj[])
	{
	   DSU dsu(V);
	    
	   for(int u=0;u<V;u++){
	       for(int &v:adj[u]){
	           if(u<v){
	               int parent_u=dsu.find(u);
	               int parent_v=dsu.find(v);
	               if(parent_u==parent_v) return true;
	               dsu.Union(u,v);
	           }
	       }
	   }
	   
	   return false;
	}
