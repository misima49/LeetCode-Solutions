class Solution {
    void findSum(int ind, int target, vector<int>& cur, vector<vector<int>>& answer, vector<int>& cand) {
        if(target == 0) {
            answer.push_back(cur);
            return;
        }
        
        if(ind == cand.size()) return;
        
        if(cand[ind] <= target) {
            cur.push_back(cand[ind]);
            findSum(ind, target-cand[ind], cur, answer, cand);
            cur.pop_back();
        }
        findSum(ind+1, target, cur, answer, cand);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> answer;
        findSum(0, target, cur, answer, candidates);
        
        return answer;
    }
};