class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        stack<pair<int, int>> st;
        int origColor = image[sr][sc];
        int rLen = image.size();
        int cLen = image[0].size();
        vector<vector<int>> result = image;
        int x, y;
        result[sr][sc] = newColor;
        image[sr][sc] = -1;
        st.push({sr, sc});
        
        while(!st.empty()) {
            x = st.top().first;
            y = st.top().second;
            st.pop();
            image[x][y] = -1;
            if(x < rLen - 1 && image[x+1][y] == origColor) {
                st.push({x+1, y});
                result[x+1][y] = newColor;
            } else if(x < rLen - 1 && image[x+1][y] != -1) {
                result[x+1][y] = image[x+1][y];
            }
            
            if(x > 0 && image[x-1][y] == origColor) {
                st.push({x-1, y});
                result[x-1][y] = newColor;
            } else if(x > 0 && image[x-1][y] != -1) {
                result[x-1][y] = image[x-1][y];
            }
            
            if(y < cLen - 1 && image[x][y+1] == origColor) {
                st.push({x, y+1});
                result[x][y+1] = newColor;
            } else if(y < cLen - 1 && image[x][y+1] != -1) {
                result[x][y+1] = image[x][y+1];
            }
            
            if(y > 0 && image[x][y-1] == origColor) {
                st.push({x, y-1});
                result[x][y-1] = newColor;
            } else if(y > 0 && image[x][y-1] != -1) {
                result[x][y-1] = image[x][y-1];
            }
        }
        
        return result;
    }
};