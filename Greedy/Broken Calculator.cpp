//Recursive solution
int brokenCalc(int startValue, int target) {
        if(startValue>=target){
            return startValue-target;
        }

        if(target%2==0){
            return 1+brokenCalc(startValue,target/2);
        }

        return 1+brokenCalc(startValue,target+1);
    }

//iterative solution
int brokenCalc(int startValue, int target) {
        int op=0;

        while(target>startValue){
            if(target%2==0){
                target/=2;
                op++;
            }
            else{
                op++;
                target++;
            }
        }

        return op+startValue-target;
    }
