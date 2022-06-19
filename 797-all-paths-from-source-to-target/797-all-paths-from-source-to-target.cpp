class Solution {
private:
    void dfs(int i, vector<int>& path, vector<vector<int>>& ans, vector<vector<int>>& graph) {
        path.push_back(i);
        
        if(i == graph.size()-1) {
            ans.push_back(path);
        } 
        for(int itr : graph[i]) {
            dfs(itr, path, ans, graph);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, path, ans, graph);
        
        return ans;
    }
};