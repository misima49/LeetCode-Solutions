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
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
  
        int sz = rides.size();
        vector<long long> dp(sz+1, 0);
        
        for(int ind = sz-1; ind >= 0; ind--) {
            long long notPick = dp[ind+1];
        
            int nexPossible = searchRide(rides, rides[ind][1]);
            long long pick = rides[ind][1] - rides[ind][0] + rides[ind][2] + dp[nexPossible];

            dp[ind] = pick > notPick ? pick : notPick;
        }
        
        
        return dp[0];
    }
};