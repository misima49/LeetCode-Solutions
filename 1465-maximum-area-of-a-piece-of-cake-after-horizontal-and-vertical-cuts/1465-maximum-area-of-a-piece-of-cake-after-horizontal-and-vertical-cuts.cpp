#define mod 1000000007

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxHori = max(horizontalCuts[0], h-horizontalCuts.back());
        int maxVert = max(verticalCuts[0], w-verticalCuts.back());
        
        for(int i = 0; i < horizontalCuts.size()-1; i++) {
            maxHori = max(horizontalCuts[i+1]-horizontalCuts[i], maxHori);
        }
        
        for(int i = 0; i < verticalCuts.size()-1; i++) {
            maxVert = max(verticalCuts[i+1]-verticalCuts[i], maxVert);
        }
        
        return ((long)maxHori*maxVert)%mod;
    }
};