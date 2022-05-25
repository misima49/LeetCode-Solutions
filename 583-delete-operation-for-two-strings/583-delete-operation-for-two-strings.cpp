class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> prev(n+1, 0), cur(n+1, 0);
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    cur[j] = 1+prev[j-1];
                } else {
                    cur[j] = max(cur[j-1], prev[j]);
                }
            }
            
            prev = cur;
        }
        
        // cout << prev[n];
        
        return m+n-2*prev[n];
    }
};