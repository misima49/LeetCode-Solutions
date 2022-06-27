class Solution {
    
    int findParent(int u, vector<int>& parents) {
        if(parents[u] < 0) return u;
        
        return parents[u] = findParent(parents[u], parents);
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> type3Parent(n+1, -1);
        int nonRemovalEdges = 0;
        
        for(int type = 3; type >= 1; type--) {
            vector<int> otherTypeParent = type3Parent;
            
            vector<int>& parent = type == 3 ? type3Parent : otherTypeParent;
            
            for(vector<int> itr : edges) {
                if(itr[0] == type) {
                    int u = findParent(itr[1], parent);
                    int v = findParent(itr[2], parent);
                    
                    if(u != v) {
                        nonRemovalEdges++;
                        if(v < u) swap(v, u);
                        
                        parent[u] += parent[v];
                        parent[v] = u;
                    }
                }
            }
            
            if(type != 3 && parent[findParent(1, parent)] != -n)
                return -1;
        }
        
        return edges.size() - nonRemovalEdges;
    }
};