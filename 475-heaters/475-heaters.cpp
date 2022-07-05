class Solution {
    int findNearestHeaterDist(int targ, vector<int>& heaters) {
        if(targ < heaters[0]) return heaters[0] - targ;
        if(targ > heaters.back()) return targ - heaters.back();
        
        int n = heaters.size();
        int st = 0, ed = n-1;
        
        while(st <= ed) {
            int md = (st+ed)/2;
            
            if(heaters[md] == targ) return 0;
            
            if(targ < heaters[md]) {
                if(md > 0 && targ > heaters[md-1]) {
                    return min(heaters[md]-targ, targ-heaters[md-1]);
                }
                
                ed = md-1;
            } else {
                if(md < n-1 && targ < heaters[md+1]) {
                    return min(targ-heaters[md], heaters[md+1]-targ);
                }
                
                st = md+1;
            }
        }
        
        return targ-heaters[ed];
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int minRad = -1e8;
        for(int itr : houses) {
            int nearestHeater = findNearestHeaterDist(itr, heaters);
            // cout << nearestHeater << " ";
            minRad = max(minRad, nearestHeater);
        }
        
        return minRad;
    }
};