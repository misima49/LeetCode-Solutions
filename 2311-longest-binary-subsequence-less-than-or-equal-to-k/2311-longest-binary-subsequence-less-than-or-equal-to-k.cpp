class Solution {
public:
    int longestSubsequence(string s, int k) {
        int curLen = 0;
        for(int i = s.length()-1; i >= 0; i--) {
            if(s[i] == '0') curLen++;
            else if(pow(2, s.length()-i-1) <= k) {
            // cout << k << " " << pow(2, s.length()-i-1) << "\n";
                k -=  pow(2, s.length()-i-1);
                curLen++;
            }
        }
        
        return curLen;
    }
};