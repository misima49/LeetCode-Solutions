class Solution {
    bool isPalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    int findCuts(int ind, int n, string& s, vector<int>& dp) {
        if(ind == n) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int minCost = 1e8;
        for(int i = ind; i < n; i++) {
            if(isPalindrome(ind, i, s)) {
                int cost = 1+findCuts(i+1, n, s, dp);
                
                minCost = min(minCost, cost);
            }
        }
        
        return dp[ind] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        
        return findCuts(0, n, s, dp)-1;
    }
};