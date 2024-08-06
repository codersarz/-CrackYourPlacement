//Time-Complexity->O(E*log(V))
//Space-Complexity->O(V)
    typedef pair<int,int> P; 
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<P,vector<P>,greater<P>> pq;
        
        vector<int> dist(V,INT_MAX);
        
        dist[S]=0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto &v:adj[node]){
                int adjNode=v[0];
                int wt=v[1];
                
                if(d+wt<dist[adjNode]){
                    dist[adjNode]=d+wt;
                    pq.push({d+wt,adjNode});
                }
            }
        }
        
        return dist;
    }
