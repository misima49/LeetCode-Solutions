class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        
        unordered_map<char, int> toBeChecked, curWin;
        
        for(char c:s1) {
            toBeChecked[c]++;
        }
        
        for(int i = 0; i < s1.length(); i++) {
            curWin[s2[i]]++;
        }
        
        for(int i = s1.length(), st = 0; i < s2.length(); i++) {
            if(curWin == toBeChecked) return true;
            // cout << curWin[s2[st]] << " " << s2[st] << "\n";
            curWin[s2[st]]--;
            if(curWin[s2[st]] == 0) curWin.erase(s2[st]);
            st++;
            curWin[s2[i]]++;
        }
        
        // for(auto itr:curWin) {
        //     cout << itr.first << " " << itr.second << "\n";
        // }
        
        return curWin == toBeChecked;
    }
};