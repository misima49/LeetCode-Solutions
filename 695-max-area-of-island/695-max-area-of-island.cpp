class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int largestAr = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) 
                    largestAr = max(dfs(grid, i, j), largestAr);
            }
        }
        
        return largestAr;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        stack<pair<int, int>> st;
        int islandSize = 1;
        
        st.push({x, y});
        grid[x][y] = 0;
        
        while(!st.empty()) {
            x = st.top().first;
            y = st.top().second;
            
            st.pop();
            
            if(x < grid.size() - 1 && grid[x+1][y] == 1) {
                st.push({x+1, y});
                islandSize++;
                grid[x+1][y] = 0;
            } 
            
            if(x > 0 && grid[x-1][y] == 1) {
                st.push({x-1, y});
                islandSize++;
                grid[x-1][y] = 0;
            } 
            
            if(y < grid[0].size() - 1 && grid[x][y+1] == 1) {
                st.push({x, y+1});
                islandSize++;
                grid[x][y+1] = 0;
            } 
            
            if(y > 0 && grid[x][y-1] == 1) {
                st.push({x, y-1});
                islandSize++;
                grid[x][y-1] = 0;
            } 
        }
        
        cout << islandSize << "\n";
        return islandSize;
    }
};