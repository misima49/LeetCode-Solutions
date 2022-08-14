class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<char> st;
        string ans;
        
        for(int i = 0; i <= n; i++) {
            st.push(i+'1');
            if(i == n || pattern[i] == 'I') {
                while(!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};