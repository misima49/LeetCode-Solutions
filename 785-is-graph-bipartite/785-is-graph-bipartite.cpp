class Solution {
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& color) {
        if(color[i] == -1) 
            color[i] = 1;
        
        for(int node : graph[i]) {
            if(color[node] == -1) {
                color[node] = 1-color[i];
                if(!dfs(node, graph, color)) {
                    return false;
                }
            } else if(color[node] == color[i])
                return false;
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        
        for(int i = 0; i < color.size(); i++) {
            if(color[i] == -1) {
                if(!dfs(i, graph, color)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};