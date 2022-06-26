/*
    Possible rolls if prev roll was:
        1 -> 2,3,4,5,6
        2 -> 1,3,5
        3 -> 1,2,4,5
        4 -> 1,3,5
        5 -> 1,2,3,4,6
        6 -> 1,5
*/

vector<vector<int>> dir({
            {1,2,3,4,5,6}, 
            {2,3,4,5,6},
            {1,3,5},
            {1,2,4,5},
            {1,3,5},
            {1,2,3,4,6},
            {1,5}});

int mod = 1e9 + 7;

class Solution {
    vector<vector<vector<int>>> dp;
    
    long long findRolls(int ind, int prev, int prev2, int n) {
        if(ind == n) return 1;
        // cout << ind << " " << prev << " " << prev2 << "\n";
        if(dp[prev][prev2][ind] != -1) return dp[prev][prev2][ind];
        
        long long seqCount = 0;
        for(int itr : dir[prev]) {
            if(itr != prev2) {
                seqCount += findRolls(ind+1, itr, prev, n);
            }
        }
        
        
        return dp[prev][prev2][ind] = seqCount % mod;
    }
public:
    int distinctSequences(int n) {
        dp.resize(7, vector<vector<int>>(7, vector<int>(n+1, -1)));
        return findRolls(0, 0, 0, n);
    }
};