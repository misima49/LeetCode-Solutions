class Solution {
    void findSum(int i, int target, vector<int>& cur, vector<vector<int>>& answer, vector<int>& cand) {
        if(i == cand.size()) {
            if(target == 0) {
                answer.push_back(cur);
            }
            
            return;
        }
        
        if(cand[i] <= target) {
            cur.push_back(cand[i]);
            findSum(i+1, target-cand[i], cur, answer, cand);
            cur.pop_back();
        }
        
        while(i+1 < cand.size() && cand[i] == cand[i+1]) i++;
        findSum(i+1, target, cur, answer, cand);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> answer;
        sort(candidates.begin(), candidates.end());
        findSum(0, target, cur, answer, candidates);
        
        return answer;
    }
};