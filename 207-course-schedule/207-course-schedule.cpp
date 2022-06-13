class Solution {
    bool dfsDetectCycle(int sc, vector<bool>& visited, vector<vector<int>>& G) {
        vector<bool> dfsVisited(visited.size(), false);
        stack<int> st;
        
        visited[sc] = dfsVisited[sc] = true;
        st.push(sc);
        
        while(!st.empty()) {
            bool flag = false;
            int cur = st.top();
            
            for(int it : G[cur]) {
                if(!visited[it]) {
                    visited[it] = dfsVisited[it] = true;
                    st.push(it);
                    flag = true;
                    break;
                } else if(dfsVisited[it]) 
                    return true;
            }
            
            if(!flag) {
                dfsVisited[cur] = false;
                st.pop();
            }
        }
        
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        vector<bool> visited(numCourses, false);
        
        for(vector<int> it : prerequisites) {
            G[it[0]].push_back(it[1]);
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(dfsDetectCycle(i, visited, G)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};