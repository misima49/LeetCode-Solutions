class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, prev2 = 1;
        int cur = 0;
        for(int i = 2; i <= n; i++) {
            cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        
        return prev;
    }
};