class Solution {
    static bool sortComp(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
    bool compare(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();
        if(m != n+1) return false;
        
        int itr1 = 0, itr2 = 0;
        while(itr1 < m) {
            if(itr2 < n && s1[itr1] == s2[itr2]) {
                itr1++;
                itr2++;
            } else {
                itr1++;
            }
        }
        
        if(itr1 == m && itr2 == n) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), sortComp);
        int n = words.size();
        vector<int> dp(n, 1);
        int longest = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(compare(words[i], words[j]) && dp[i] < 1+dp[j]) {
                    dp[i] = 1+dp[j];
                }
            }
            
            longest = max(longest, dp[i]);
        }
        // for(int i = 0; i < n; i++) {
        //     cout << dp[i] << " ";
        // }
        return longest;
    }
};