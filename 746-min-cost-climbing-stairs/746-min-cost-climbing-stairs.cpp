class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = cost[0];
        int prev2 = cost[1];
        int cur;
        
        for(int i = 2; i < cost.size(); i++) {
            cur = (prev1 < prev2 ? prev1 : prev2) + cost[i];
            prev1 = prev2;
            prev2 = cur;
        }
        
        cur = prev1 < prev2 ? prev1 : prev2;
        return cur;
    }
};