class Solution {
    bool findPossibility(int maxInt, int targ, int state, vector<int>& dp) {
        if(targ <= 0)
            return dp[state] = false;
        
        if(dp[state] != -1) return dp[state];
        
        for(int i = 1; i <= maxInt; i++) {
            if(!(state & (1 << i)) && !findPossibility(maxInt, targ-i, state | (1 << i), dp)) {
                return dp[state] = true;
            }
        }
        
        return dp[state] = false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int maxSum = maxChoosableInteger*(maxChoosableInteger+1)/2;
        vector<int> dp(1 << (maxChoosableInteger+1), -1);
        
        if(maxChoosableInteger >= desiredTotal) return true;
        else if(maxSum < desiredTotal) return false;
        else if(maxSum == desiredTotal) {
            if(maxChoosableInteger % 2 == 0) return false;
            else return true;
        } else {
            return findPossibility(maxChoosableInteger, desiredTotal, 0, dp);
        }
    }
};