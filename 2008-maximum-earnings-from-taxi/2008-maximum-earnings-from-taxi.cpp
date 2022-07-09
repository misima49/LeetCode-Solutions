class Solution {
    int searchRide(vector<vector<int>>& rides, int rideSt) {
        int st = 0, ed = rides.size()-1;
        int lastFound = rides.size();
        
        while(st <= ed) {
            int md = (st+ed)/2;

            if(rides[md][0] >= rideSt) {
                lastFound = md;
                ed = md-1;
            }
            else st = md+1;
        }
        
        return lastFound;
    }
    
    long long findEarnings(int ind, vector<vector<int>>& rides, vector<long long>& dp) {
        if(ind >= rides.size()) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        long long notPick = findEarnings(ind+1, rides, dp);
        
        int nexPossible = searchRide(rides, rides[ind][1]);
        long long pick = rides[ind][1] - rides[ind][0] + rides[ind][2] + findEarnings(nexPossible, rides, dp);
        
        return dp[ind] = max(pick , notPick);
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
  
        int sz = rides.size();
        vector<long long> dp(sz, -1);
        
        return findEarnings(0, rides, dp);
    }
};