class Solution {
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int largestRec = 0;
        
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int width = 0;
                int height = heights[st.top()];
                st.pop();
                if(st.empty()) 
                    width = i;
                else
                    width = i-st.top()-1;
                
                largestRec = max(largestRec, height*width);
            }
            
            st.push(i);
        }
        return largestRec;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int largestArea = 0;
        vector<int> heights(n, 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
                
            }
            
            largestArea = max(largestRectangleArea(heights), largestArea);
        }
        
        return largestArea;
    }
};