class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> maxH;
        int i;

        for(i = 0; i < n-1; i++) {
            if(heights[i] > heights[i+1]) {
                continue;
            }
            // cout << i << " "<< bricks << "\n";
            int diff = heights[i+1] - heights[i];
            
            if(bricks >= diff) {
                bricks -= diff;
                maxH.push(diff);
            } else if(ladders) {
                if(!maxH.empty() && maxH.top() > diff) {
                    bricks += maxH.top() - diff;
                    maxH.pop();
                    maxH.push(diff);
                }
                
                ladders--;
            } else 
                break;
        }
        return i;
    }
};