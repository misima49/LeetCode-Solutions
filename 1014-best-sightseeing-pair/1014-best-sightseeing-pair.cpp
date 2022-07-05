class Solution {
    // int maxSightVal;
//     int findMaxRight(int ind, vector<int>& values) {
//         int n = values.size();
//         if(ind == n-1) return values[ind]-ind;
        
//         int maxVal = 0;
//         maxVal = max(maxVal,findMaxRight(ind+1, values));
//         maxSightVal = max(maxSightVal, values[ind]+ind+maxVal);
        
//         return max(maxVal, values[ind]-ind);
//     }
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxSightVal = 0;
        // findMaxRight(0, values);
        vector<int> dp(n, 0);
        // dp[n-1] = values[n-1] - (n-1);
        int nex = values[n-1] - (n-1);
        
        for(int i = n-2; i >= 0; i--) {
            // int cur = max(values[i] - i, nex);
            maxSightVal = max(maxSightVal, values[i] + i + nex);
            nex = max(values[i] - i, nex);
            // dp[i] = max(values[i] - i, dp[i+1]);
            // maxSightVal = max(maxSightVal, values[i] + i + dp[i+1]);
        }
        
        return maxSightVal;
    }
};