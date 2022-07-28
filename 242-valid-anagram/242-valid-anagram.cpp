class Solution {
public:
    bool isAnagram(string s, string t) {
        int sArr[26]{}, tArr[26]{};
        
        for(char ch : s) {
            sArr[ch-'a']++;
        }
        
        for(char ch : t) {
            tArr[ch-'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(sArr[i] != tArr[i]) return false;
        }
        
        return true;
    }
};