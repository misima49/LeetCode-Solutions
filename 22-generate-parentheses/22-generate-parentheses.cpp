class Solution {
    vector<string> ans;
    void findCombs(int op, int ed, int& n, string& curS) {
        if(op == n && ed == n) {
            ans.push_back(curS);
            return;
        } else if(ed > op) return;
        
        if(op <= n) {
            curS.push_back('(');
            findCombs(op+1, ed, n, curS);
            curS.pop_back();
        }
        
        if(ed <= op) {
            curS.push_back(')');
            findCombs(op, ed+1, n, curS);
            curS.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string curS = "";
        findCombs(0, 0, n, curS);
        return ans;
    }
};