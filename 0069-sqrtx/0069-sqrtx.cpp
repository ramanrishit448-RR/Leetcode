class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        for(int num = 1;num <= x; num= num+1){
            long val = (long) num * num;
            if(val>x){
            break;
            }
            ans = num;
        }

        return ans;
    }
};