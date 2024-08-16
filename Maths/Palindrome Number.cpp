class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }

        int temp=x;
        long rev=0;
        int digit;
        while(x>0){
            digit=x%10;
            rev=rev*10+digit;
            x=x/10;
        }

        if(temp==rev){
            return true;
        }

        return false;
    }
};
