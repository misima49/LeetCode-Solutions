class Solution {
    bool isValid(int r, int c, int rlen, int clen) {
        if(r < 0 || c < 0 || r >= rlen || c >= clen) return false;
        return true;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        int rlen = maze.size();
        int clen = maze[0].size();
        vector<int> dir({0, 1, 0, -1, 0});
        
        maze[entrance[0]][entrance[1]] = '-';
        for(int i = 0; i < 4; i++) {
            if(isValid(entrance[0] + dir[i], entrance[1] + dir[i+1], rlen, clen) && 
              maze[entrance[0] + dir[i]][entrance[1] + dir[i+1]] == '.') {
                q.push({entrance[0] + dir[i], entrance[1] + dir[i+1]});
                maze[entrance[0] + dir[i]][entrance[1] + dir[i+1]] = '-';
            }
        }
        
        
        
        // if(isValid(entrance[0]+1, entrance[1], rlen, clen) && maze[entrance[0]+1][entrance[1]] == 1) {
        //     q.push({entrance[0]+1, entrance[1]});
        // }
        // if(isValid(entrance[0]-1, entrance[1], rlen, clen) && maze[entrance[0]-1][entrance[1]] == 1) {
        //     q.push({entrance[0]-1, entrance[1]});
        // }
        // if(isValid(entrance[0], entrance[1]+1, rlen, clen) && maze[entrance[0]][entrance[1]+1] == 1) {
        //     q.push({entrance[0], entrance[1]+1});
        // }
        // if(isValid(entrance[0], entrance[1]-1, rlen, clen) && maze[entrance[0]][entrance[1]-1] == 1) {
        //     q.push({entrance[0], entrance[1]-1});
        // }
        int answer = 1;
        
        while(!q.empty()) {
            int qSize = q.size();
            
            for(int itr = 0; itr < qSize; itr++) {
                int x = q.front().first;
                int y = q.front().second;
                // cout << x << " q " << y << "\n";
                q.pop();
                for(int i = 0; i < 4; i++) {
                    if(isValid(x + dir[i], y + dir[i+1], rlen, clen)) {
                        if(maze[x + dir[i]][y + dir[i+1]] == '.') {
                            q.push({x + dir[i], y + dir[i+1]});
                            maze[x+dir[i]][y+dir[i+1]] = '-';
                        }
                    } else {
                        cout << x << " " << y << "\n";
                        return answer;
                    }

                }
            }
            answer++;
        }
        
        return -1;
    }
};