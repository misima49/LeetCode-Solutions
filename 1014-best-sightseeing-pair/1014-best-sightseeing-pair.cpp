class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxSightVal = 0;
        int nex = values[n-1] - (n-1);
        
        for(int i = n-2; i >= 0; i--) {
            maxSightVal = max(maxSightVal, values[i] + i + nex);
            nex = max(values[i] - i, nex);
        }
        
        return maxSightVal;
    }
};