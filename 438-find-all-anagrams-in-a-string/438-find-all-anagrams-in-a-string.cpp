class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length(), plen = p.length();
        if(slen < plen) return {};
        
        unordered_map<char, int> phash, shash;
        for(char c : p) {
            phash[c]++;
        }
        
        vector<int> ans;
        int st = 0, ed = 0;
        while(ed < plen) {
            shash[s[ed]]++;
            ed++;
        }
        ed--;
        while(ed < slen) {
            if(shash == phash) {
                ans.push_back(st);
            }
            
            shash[s[st]]--;
            if(shash[s[st]] == 0) 
                shash.erase(s[st]);
            
            st++;
            ed++;
            if(ed < slen) {
                shash[s[ed]]++;
            }
        }
        
        return ans;
    }
};