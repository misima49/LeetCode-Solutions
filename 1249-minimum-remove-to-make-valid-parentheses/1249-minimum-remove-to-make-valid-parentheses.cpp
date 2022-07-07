class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.emplace('(', i);
            } else if(s[i] == ')') {
                if(st.empty()) {
                    // cout << i;
                    s.erase(i, 1);
                    i--;
                    n--;
                } else {
                    st.pop();
                }
            }
        }
        
        while(!st.empty()) {
            s.erase(st.top().second, 1);
            st.pop();
        }
        
        return s;
    }
};