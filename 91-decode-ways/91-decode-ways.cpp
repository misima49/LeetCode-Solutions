class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        
        int n = s.length();
        int next = 1, next2, cur;
        
        for(int i = n-1; i >= 0; i--) {
            cur = (s[i] == '0') ? 0 : next;
            
            if(i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) cur += next2;
            
            next2 = next;
            next = cur;
        }
        
        return next;
    }
};