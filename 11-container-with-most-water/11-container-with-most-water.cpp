class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int maxAr = 0;
        int length = 0;
        
        while(start < end) {
            length = end - start;
            if(height[start] < height[end]) {
                maxAr = max(maxAr, height[start] * length);
                start++;
            } else {
                maxAr = max(maxAr, height[end] * length);
                end--;
            }
        }
        
        return maxAr;
    }
};