class Solution {
    unordered_map<char, vector<char>> hash;    
public:
    Solution() {
        hash['2'] = {'a', 'b', 'c'};
        hash['3'] = {'d', 'e', 'f'};
        hash['4'] = {'g', 'h', 'i'};
        hash['5'] = {'j', 'k', 'l'};
        hash['6'] = {'m', 'n', 'o'};
        hash['7'] = {'p', 'q', 'r', 's'};
        hash['8'] = {'t', 'u', 'v'};
        hash['9'] = {'w', 'x', 'y', 'z'};
    }
    
    void makeOrder(int ind, vector<string>& ans, string& digits, string& cur) {
        int n = digits.length();
        if(ind == n) {
            ans.push_back(cur);
            return;
        }
        
        for(char ch : hash[digits[ind]]) {
            cur.push_back(ch);
            makeOrder(ind+1, ans, digits, cur);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string cur = "";
        makeOrder(0, ans, digits, cur);
        
        return ans;
    }
};