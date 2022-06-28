class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> counts;
        int charCount[26]{};
        
        for(char ch : s) {
            charCount[ch-'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            for(; charCount[i] > 0 && !counts.insert(charCount[i]).second; charCount[i]--) {
                ans++;
            };
        }
        
        return ans;
    }
};