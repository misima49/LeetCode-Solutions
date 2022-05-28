class Solution {
public:
    string reverseWords(string s) {
        stringstream sst(s);
        string word;
        string ans = "";
        int st, end;
        while(sst >> word) {
            st = 0;
            end = word.length()-1;
            while(st < end) {
                swap(word[st++], word[end--]);
            }
            word.append(" ");
            ans.append(word);
        }
        
        ans.pop_back();
        return ans;
    }
};