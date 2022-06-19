class Solution {
private:
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& rooms) {
        if(visited[i]) return;
        
        visited[i] = true;
        for(int itr : rooms[i]) {
            dfs(itr, visited, rooms);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, visited, rooms);
        
        for(bool itr : visited) 
            if(!itr) return false;
        
        return true;
    }
};