class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec:times){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];

            adj[u].push_back({v,w});
        }

        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &v:adj[node]){
                int adjNode=v.first;
                int wt=v.second;

                if(d+wt<dist[adjNode]){
                    dist[adjNode]=d+wt;
                    pq.push({d+wt,adjNode});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }

        if(ans==INT_MAX) return -1;

        return ans;
    }
};
