class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans = "";
        while(ss >> word) {
            word.append(" ");
            ans = word + ans;
        }
        ans.pop_back();
        return ans;
    }
};