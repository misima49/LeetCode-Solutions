class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.emplace(i);
            } else if(s[i] == ')') {
                if(st.empty()) {
                    s.erase(i, 1);
                    i--; n--;
                } else {
                    st.pop();
                }
            }
        }
        
        while(!st.empty()) {
            s.erase(st.top(), 1);
            st.pop();
        }
        
        return s;
    }
};