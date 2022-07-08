class Solution {
    void prefix_function(string& needle, vector<int>& pi) {
        int n = needle.length();
        for(int i = 1; i < n; i++) {
            int j = pi[i-1];
            
            while(j > 0 && needle[i] != needle[j]) {
                j = pi[j-1];
            }
                
            if(needle[j] == needle[i]) {
                j++;
            }
            
            pi[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        vector<int> pi(m, 0);
        prefix_function(needle, pi);
        
        int i = 0, j = 0;
        while(i < haystack.length()) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if(j != 0) {
                    j = pi[j-1];
                } else {
                    i++;
                }
            }
            
            if(j == m) return i-m;
        }
        
        return -1;
    }
};