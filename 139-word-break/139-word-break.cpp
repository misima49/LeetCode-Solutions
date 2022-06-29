class Solution {
    bool findIfContained(int st, string& s, unordered_set<string>& words, unordered_map<int, bool>& dp) {
        if(st == s.length()) return true;
        
        if(dp.count(st)) return dp[st];
        
        int n = s.length();
        string sub = "";
        
        for(int i = st; i <= n; i++) {
            if(words.count( sub += s[i] )) {
                if(findIfContained(i+1, s, words, dp)) {
                    dp.insert({st, true});
                    return true;
                }
            }
        }
        
        dp.insert({st, false});
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> dp;
        return findIfContained(0, s, words, dp);
    }
};