class Solution {
    bool isPalindrome(int start, int end, string& s) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        
        return true;
    }
public:
    int removePalindromeSub(string s) {
        int n = s.length();
        int answer = 0;
        
        if(isPalindrome(0, n-1, s)) return 1;
        
        return 2;
    }
};