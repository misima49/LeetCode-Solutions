class Solution {
    vector<int> makeHash(string& st) {
        vector<int> temp(26, 0);
        for(char& ch : st) {
            temp[ch-'a']++;
        }
        
        return temp;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int hashForTotalInWords2[26]{};
        vector<int> temp;
        for(string& st : words2) {
            temp = makeHash(st);
            for(int i = 0; i < 26; i++) {
                hashForTotalInWords2[i] = max(hashForTotalInWords2[i], temp[i]);
            }
        }
        vector<string> ans;
        for(string& st : words1) {
            temp = makeHash(st);
            bool flag = true;
            for(int i = 0; i < 26; i++) {
                if(temp[i] < hashForTotalInWords2[i]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) ans.push_back(st);
        }
        
        return ans;
    }
};