class Solution {
    bool findSides(int ind, vector<int>& matchsticks, vector<int>& sides, const int targ) {
        
        if(ind == matchsticks.size()) {
            for(int i = 1; i < 4; i++) {
                if(sides[i] != sides[0]) return false;
            }
            return true;
        }
        
        for(int i = 0; i < 4; i++) {
            if(matchsticks[ind] + sides[i] > targ) continue;
            
            int j;
            for(j = i-1; j >= 0; j--) {
                if(sides[j] == sides[i]) break;
            }
            
            if(j != -1) continue;
            
            sides[i] += matchsticks[ind];
            if(findSides(ind+1, matchsticks, sides, targ)) return true;
            sides[i] -= matchsticks[ind];
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int itr : matchsticks) {
            sum += itr;
        }
        if(sum % 4) return false;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4, 0);
        
        return findSides(0, matchsticks, sides, sum / 4);
    }
};