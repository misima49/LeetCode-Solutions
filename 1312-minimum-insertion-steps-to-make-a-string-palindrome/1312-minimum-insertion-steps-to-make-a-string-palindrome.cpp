class Solution {
public:
    int minInsertions(string s1) {
        int n = s1.length();
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        vector<int> prev(n+1, 0), cur(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    cur[j] = 1+prev[j-1];
                } else {
                    cur[j] = max(cur[j-1], prev[j]);
                }
            }
            
            prev = cur;
        }
        
        return n-prev[n];
    }
};