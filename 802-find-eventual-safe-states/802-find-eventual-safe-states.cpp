class Solution {
    unordered_set<int> inCycle;
    unordered_set<int> isSafe;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_set<int> visited;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(dfs(i, visited, graph))
                ans.push_back(i);
        }
        
        return ans;
    }
    
private:
    bool dfs(int sc, unordered_set<int> visited, vector<vector<int>>& graph) {        
        if(isSafe.find(sc) != isSafe.end()) return true;
        if(inCycle.find(sc) != inCycle.end()) return false;
        
        if(visited.find(sc) != visited.end()) {
            inCycle.insert(sc);
            return false;
        }
        
        visited.insert(sc);
        
        for(int i : graph[sc]) {
            if(!dfs(i, visited, graph)) {
                inCycle.insert(sc);
                return false;
            }
        }
        
        isSafe.insert(sc);
        return true;;
    }
};