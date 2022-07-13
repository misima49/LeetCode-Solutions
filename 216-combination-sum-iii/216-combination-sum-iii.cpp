class Solution {
    vector<vector<int>> ans;
    void findComb(int ind, int k, int n, vector<int>& curComb) {
        if(curComb.size() == k) {
            if(n == 0) ans.push_back(curComb);
            return;
        } 
        if(n <= 0 || ind > 9) return;
        
        findComb(ind+1, k, n, curComb);
        curComb.push_back(ind);
        findComb(ind+1, k, n-ind, curComb);
        curComb.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curComb;
        
        findComb(1, k, n, curComb);
        return ans;
    }
};