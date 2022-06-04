class Solution {
    string curStr = "";
    vector<string> answer;
    
    void findPermutations(int ind, string s) {
        // cout << curStr << "\n";
        
        if(ind == s.length()) {
            if(curStr.length() == s.length())
                answer.push_back(curStr);
            return;
        }
        if(!isdigit(s[ind])) {
            curStr.push_back(tolower(s[ind]));
            findPermutations(ind+1, s);
            curStr.pop_back();
            curStr.push_back(toupper(s[ind]));
            findPermutations(ind+1, s);
            curStr.pop_back();
        } else {
            curStr.push_back(s[ind]);
            findPermutations(ind+1, s);
            curStr.pop_back();
        }
        
        // findPermutations(ind+1, s);
    }
public:
    vector<string> letterCasePermutation(string s) {
        findPermutations(0, s);
        return answer;
    }
};