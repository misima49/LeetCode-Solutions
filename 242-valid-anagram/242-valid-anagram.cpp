class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
        
        for(char ch : s) {
            mapS[ch]++;
        }
        
        for(char ch : t) {
            mapT[ch]++;
        }
        
        return mapS == mapT;
    }
};