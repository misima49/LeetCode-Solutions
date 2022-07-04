class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = nums[0];
        int posMax = 1, negMax = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            vector<int> temp({nums[i], negMax*nums[i], posMax*nums[i]});
            posMax = *max_element(temp.begin(), temp.end());
            negMax = *min_element(temp.begin(), temp.end());
            
            maxPro = max(maxPro, posMax);
        }
        
        return maxPro;
    }
};