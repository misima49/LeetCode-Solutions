class Solution {
    void makeCombi(int i, int k, int n, vector<int>& cur, vector<vector<int>>& answer) {
        if(cur.size() == k) {
            answer.push_back(cur);
            return;
        }
        if(i > n) return;
        
        cur.push_back(i);
        makeCombi(i+1, k, n, cur, answer);
        cur.pop_back();
        makeCombi(i+1, k, n, cur, answer);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> cur;
        
        makeCombi(1, k, n, cur, answer);
        
        return answer;
    }
};