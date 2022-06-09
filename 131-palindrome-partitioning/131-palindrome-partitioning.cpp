class Solution {
    bool isPalindrome(int st, int ed, string& s) {
        while(st < ed) {
            if(s[st++] != s[ed--]) return false;
        }
        
        return true;
    }
    
    void findPalin(int ind, vector<string>& curPart, string& s, vector<vector<string>>& answer) {
        int n = s.length();
        if(ind == n) {
            answer.push_back(curPart);
            return;
        }
        
        for(int i = ind; i < n; i++) {
            if(isPalindrome(ind, i, s)) {
                curPart.push_back(s.substr(ind, i-ind+1));
                findPalin(i+1, curPart, s, answer);
                curPart.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curPart;
        vector<vector<string>> answer;
        findPalin(0, curPart, s, answer);
        
        return answer;
    }
};