class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";
        for(char i = '1'; i <= n+'1'; i++) {
            ans.push_back(i);
        }

        int lf = 0, rt = 0;
        while(rt < n) {
            if(pattern[rt] == 'I') {
                reverse(ans.begin()+lf, ans.begin()+rt+1);
                lf = rt+1;
            }
            rt++;
        }
        
        if(rt != lf) reverse(ans.begin()+lf, ans.begin()+rt+1);
        
        return ans;
    }
};