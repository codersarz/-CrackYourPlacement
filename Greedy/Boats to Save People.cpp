int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();

        sort(begin(people),end(people));

        int boats=0;
        int i=0,j=n-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
            }else{
                j--;
            }
            boats+=1;
        }

        return boats;
    }
