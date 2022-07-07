#define mod 1000000007

class Solution {
    int findWays(int ind, int prev, vector<bool>& isNumAvail, string& s, vector<vector<int>>& dp) {
        int n = s.length();
        if(ind == n+1) return 1;
        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
        int ways = 0;
        if(prev == -1) {
            for(int i = 0; i <= n; i++) {
                if(isNumAvail[i]) {
                    isNumAvail[i] = false;
                    ways = ways%mod + findWays(ind+1, i, isNumAvail, s, dp)%mod;
                    isNumAvail[i] = true;
                }
            }
        } else if(s[ind-1] == 'D') {
            for(int i = 0; i <= prev; i++) {
                if(isNumAvail[i]) {
                    isNumAvail[i] = false;
                    ways = ways%mod + findWays(ind+1, i, isNumAvail, s, dp)%mod;
                    isNumAvail[i] = true;
                }
            }
        } else if(s[ind-1] == 'I') {
            for(int i = prev; i <= n; i++) {
                if(isNumAvail[i]) {
                    isNumAvail[i] = false;
                    ways = ways%mod + findWays(ind+1, i, isNumAvail, s, dp)%mod;
                    isNumAvail[i] = true;
                }
            }
        }
        
        return dp[ind][prev+1] = ways%mod;
    }
public:
    int numPermsDISequence(string s) {
        int n = s.length();
        vector<bool> isNumAvail(n+1, true);
        vector<vector<int>> dp(n+1, vector<int>(n+2, -1));

        return findWays(0, -1, isNumAvail, s, dp);
    }
};