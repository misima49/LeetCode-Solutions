class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMax(n, 0), postMax(n, 0);
        preMax[0] = height[0];
        postMax[n-1] = height[n-1];
        for(int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i-1], height[i]);
            postMax[n-1-i] = max(postMax[n-1-i+1], height[n-1-i]);
        }
        
        // for(int i = 0; i < n; i++) {
        //     cout << preMax[i] << " " << postMax[i] << "\n";
        // }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            // cout << min(preMax[i], postMax[i]) << " " << height[i] << "\n";
            ans += min(preMax[i], postMax[i]) - height[i];
        }
        
        return ans;
    }
};