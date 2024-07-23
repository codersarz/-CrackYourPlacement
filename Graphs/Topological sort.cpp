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
//Topological Sorting Using BFS(Kahn's Algorithm)
//Time-Complexity->O(V+E)
//Space-Complexity->O(V)
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    for(int u=0;u<V;u++){
	        for(int &v:adj[u]){
	            indegree[v]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> result;
	    while(!q.empty()){
	        int u=q.front();
	        result.push_back(u);
	        q.pop();
	        
	        for(int &v:adj[u]){
	            indegree[v]--;
	            
	            if(indegree[v]==0){
	                q.push(v);
	            }
	        }
	    }
	    
	    return result;
	}
