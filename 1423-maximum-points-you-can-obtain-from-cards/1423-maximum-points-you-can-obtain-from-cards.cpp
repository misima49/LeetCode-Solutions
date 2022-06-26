class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxSum = 0;
        int curSum = 0;
        
        for(int i = 0; i < k; i++) {
            curSum += cardPoints[i];
        }
        
        for(int i = n-1, j = k-1; i >= n-k; i--, j--) {
            if(maxSum < curSum) maxSum = curSum;
            
            curSum -= cardPoints[j];
            curSum += cardPoints[i];
        }
        
        if(maxSum < curSum) maxSum = curSum;
        return maxSum;
    }
};