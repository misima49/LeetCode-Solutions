class Solution {
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    void findSubStr(string s, int ind, vector<string>& curSol, vector<vector<string>>& answer) {
        if(ind == s.length()) {
            answer.push_back(curSol);
            return;
        }
        
        cout << ind << " ";
        for(int i = ind; i < s.length(); i++) {
            if(isPalindrome(s, ind, i)) {
                curSol.push_back(s.substr(ind, i - ind + 1));
                findSubStr(s, i+1, curSol, answer);
                curSol.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curSol;
        vector<vector<string>> answer;
        findSubStr(s, 0, curSol, answer);
        
        return answer;
    }
};