class Solution {
    static bool sortComp(string& a, string& b) {
        return a.length() < b.length();
    }
    
    bool isPred(string& s1, string& s2) {
        int n = s1.length(), m = s2.length();
        int i = 0, j = 0;
        bool flag = true;
        if(n+1 != m) return false;
        
        while(i < n) {
            if(s1[i] == s2[j]) {
                i++; j++;
            } else if(flag) {
                j++;
                flag = false;
            } else {
                return false;
            }
        }
        
        return true;
    }
    
//     int findChain(int cur, int prev, vector<string>& words, vector<vector<int>>& dp) {
//         if(cur == words.size()) return 0;
//         if(dp[cur][prev+1] != -1) return dp[cur][prev+1];
        
//         int pick = 0;
//         int notPick = findChain(cur+1, prev, words, dp);
        
//         if(prev == -1 || isPred(words[prev], words[cur])) {
//             pick = 1+findChain(cur+1, cur, words, dp);
//         }
        
//         // cout << cur << " " << prev << " " << words[cur] << " " << pick << " " << notPick << "\n";
        
//         return dp[cur][prev+1] = max(pick, notPick);
//     }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), sortComp);
        int longestChain = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(isPred(words[j], words[i]) && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                }
            }
            
            longestChain = max(longestChain, dp[i]);
        }
        
        return longestChain;
    }
};