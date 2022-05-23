class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), cur(amount+1, 0);
        
        for(int i = 0; i <= amount; i += coins[0]) {
            prev[i] = 1;
        }
        
        for(int i = 1; i < n; i++) {
            for(int a = 0; a <= amount; a++) {
                int notPick = prev[a];
                int pick = 0;
                if(a >= coins[i]) pick = cur[a-coins[i]];
                
                cur[a] = pick + notPick;
            }
            
            prev = cur;
        }
        
        return prev[amount];
    }
};