int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;

        stack<pair<char,int>> st;

        for(int i=0;i<n;i++){
            st.push({colors[i],neededTime[i]});
        }
        
        while(!st.empty()){
            char color=st.top().first;
            int time=st.top().second;
            st.pop();

            if(!st.empty() && color==st.top().first){
                if(st.top().second<time){
                    ans+=st.top().second;
                    st.pop();
                    st.push({color,time});
                }else{
                    ans+=time;
                }
            }
        }

        return ans;
    }
