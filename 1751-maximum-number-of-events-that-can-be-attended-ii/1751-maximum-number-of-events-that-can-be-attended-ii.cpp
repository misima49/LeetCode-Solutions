class Solution {
    int findNext(vector<vector<int>>& events, int prevEd) {
        int st = 0, ed = events.size()-1;
        int lastFound = events.size();
        
        while(st <= ed) {
            int md = (st+ed)/2;
            
            if(events[md][0] >= prevEd) {
                lastFound = md;
                ed = md - 1;
            } else {
                st = md+1;
            }
        }
        
        // cout << prevEd << " " << lastFound << "\n";
        return lastFound;
    }
    
    int findAttendable(int ind, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        int n = events.size();
        if(ind >= n || k == 0) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int notAttend = findAttendable(ind+1, events, k, dp);

        int nexEvent = findNext(events, events[ind][1]+1);
        int attend = findAttendable(nexEvent, events, k-1, dp) + events[ind][2];
        
        return dp[ind][k] = max(attend, notAttend);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return findAttendable(0, events, k, dp);
    }
};