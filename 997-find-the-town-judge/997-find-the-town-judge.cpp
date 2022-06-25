class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, unordered_set<int>> graph;
        
        for(vector<int> itr : trust) {
            graph[itr[0]].insert(itr[1]);
        }
        
        int judgeCand;
        for(judgeCand = 1; judgeCand <= n; judgeCand++) {
            if(!graph.count(judgeCand)) break;
        }
        if(judgeCand > n) return -1;
        // cout << judgeCand;
        for(int i = 1; i <= n; i++) {
            if(i == judgeCand) continue;
            
            if(!graph[i].count(judgeCand)) return -1;
        }
        
        return judgeCand;
    }
};