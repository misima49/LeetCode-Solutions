class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int charFreq[26]{0};
        int maxFreq = 0, ans = 0;
        int lt = 0, rt = 0;
        
        while(rt < n) {
            charFreq[s[rt]-'A']++;
            int maxFreq = 0;
            
            for(int& itr : charFreq) {
                if(maxFreq < itr) maxFreq = itr;
            }
            if(rt-lt+1 - maxFreq > k) {
                charFreq[s[lt]-'A']--;
                lt++;
                for(int& itr : charFreq) {
                    if(maxFreq < itr) maxFreq = itr;
                }
            }
            
            ans = max(ans, rt-lt+1);
            rt++;
        }
        
        return ans;
    }
};