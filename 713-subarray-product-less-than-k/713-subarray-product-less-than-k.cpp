class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int subCount = 0;
        int curProduct = 1;
        int st = 0;
        int ed = 0;
        
        while(ed < n) {
            // cout << ed << " " << nums[ed] << endl;
            curProduct *= nums[ed];
            while(st < ed && curProduct >= k) {
                curProduct /= nums[st];
                st++;
            }
            if(st != ed || curProduct < k) 
                subCount += ed-st+1;
            
            ed++;
        }

        
        return subCount;
    }
};