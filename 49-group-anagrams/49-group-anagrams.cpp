class Solution {
    void strSort(string& s) {
        vector<int> alpha(26, 0);
        for(char& ch : s) {
            alpha[ch - 'a']++;
        }
        
        s.clear();
        for(int i = 0; i < 26; i++) {
            while(alpha[i]--) {
                s.push_back('a'+i);
            }
        }
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(string& s : strs) {
            string t = s;
            strSort(t);
            hash[t].push_back(s);
        }
        
        vector<vector<string>> ans;
        ans.reserve(hash.size());
        for(auto& itr : hash) {
            ans.push_back(itr.second);
        }
        
        return ans;
    }
};