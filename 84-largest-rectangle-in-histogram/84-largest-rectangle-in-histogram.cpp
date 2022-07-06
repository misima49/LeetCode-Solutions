class Solution {
public:
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
};