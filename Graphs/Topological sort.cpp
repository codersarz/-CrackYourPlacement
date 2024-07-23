//Topological Sorting Using DFS
//Time-Complexity->O(V+E)
//Space-Complexity->O(V)
void DFS(vector<int> adj[],int u,vector<bool> &vis,stack<int> &st){
	    vis[u]=true;
	    
	    for(int &v:adj[u]){
	        if(!vis[v]){
	            DFS(adj,v,vis,st);
	        }
	    }
	    
	    st.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> vis(V,false);
	    stack<int> st;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            DFS(adj,i,vis,st);
	        }
	    }
	    
	    vector<int> result;
	    while(!st.empty()){
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	    return result;
	}
