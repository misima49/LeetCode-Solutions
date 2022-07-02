#define vows vector<char>({'0', 'a', 'e', 'i', 'o', 'u'})

class Solution {
    int findSubstr(int prev, int ind, int& n, vector<vector<int>>& dp) {
        if(ind == n) return 1;
        
        if(dp[prev][ind] != -1) return dp[prev][ind];
        
        int count = 0;
        for(int i = 1; i < 6; i++) {
            if(vows[i] >= vows[prev]) {
                count += findSubstr(i, ind+1, n, dp);
            }
        }
        
        return dp[prev][ind] = count;
    }
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(6, vector<int>(n, -1));
        return findSubstr(0, 0, n, dp);
    }
};