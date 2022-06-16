#define dir vector<int>({0, 1, 0, -1, 0})
struct hashFunction
{
    size_t operator()(const pair<int, int> &x) const
    {
        return x.first ^ x.second;
    }
};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        unordered_set<pair<int, int>, hashFunction> atlan;
        unordered_set<pair<int, int>, hashFunction> pacif;
        
        for(int i = 0; i < n; i++) {
            dfs(0, i, pacif, heights);
            dfs(m-1, i, atlan, heights);
        }
        
        for(int i = 0; i < m; i++) {
            dfs(i, 0, pacif, heights);
            dfs(i, n-1, atlan, heights);
        }
        
        vector<vector<int>> ans;
        
        auto itr = atlan.begin();
        while(itr != atlan.end()) {
            if(pacif.find(*itr) != pacif.end()) {
                ans.push_back({itr->first, itr->second});
            }
            itr++;
        }
        
        return ans;
    }
    
private:
    bool isValid(int r, int c, int m, int n) {
        if(r < 0 || c < 0 || r >= m || c >= n) return false;
        return true;
    }
    
    void dfs(int R, int C, unordered_set<pair<int, int>, hashFunction>& ocean,
             vector<vector<int>>& heights) {
        // cout << R << " " << C << " " << heights[R][C] << "\n";
        int m = heights.size();
        int n = heights[0].size();
        ocean.insert({R, C});
        
        for(int i = 0; i < 4; i++) {
            int x = R+dir[i];
            int y = C+dir[i+1];
            if(isValid(x, y, m, n) && heights[R][C] <= heights[x][y]
               && ocean.find({x, y}) == ocean.end()) {
                dfs(x, y, ocean, heights);
            }
        }
    }
};