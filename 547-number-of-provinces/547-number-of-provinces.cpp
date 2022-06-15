class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
        
        return provinces;
    }
private:
    void dfs(int sc, vector<vector<int>>& isConnected, vector<bool>& visited) {
        stack<int> st;
        int n = isConnected.size();
        visited[sc] = true;
        st.push(sc);
        
        while(!st.empty()) {
            bool flag = false;
            int cur = st.top();
            for(int i = 0; i < n; i++) {
                if(isConnected[cur][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    flag = true;
                    st.push(i);
                }
            }
            
            if(!flag) {
                st.pop();
            }
        }
    }
};