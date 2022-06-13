class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            // cout << c;
            switch(c) {
                case ')' : 
                    if(!st.empty() && st.top() == '(')
                        st.pop();
                    else 
                        return false;
                    break;
                    
                case '}' :
                    if(!st.empty() && st.top() == '{')
                        st.pop();
                    else
                        return false;
                    break;
                    
                case ']' : 
                    if(!st.empty() && st.top() == '[')
                        st.pop();
                    else 
                        return false;
                    break;
                    
                default :
                    st.push(c);
            }
        }
        
        if(st.empty()) return true;
        return false;
    }
};