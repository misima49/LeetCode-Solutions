class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long curDay = 1;
        unordered_map<int, long long> doneOn;
        int n = tasks.size();
        
        for(int i = 0; i < n; i++) {
            if(!doneOn.count(tasks[i])) {
                doneOn[tasks[i]] = curDay;
                curDay++;
            } else {
                long long canBeDone = doneOn[tasks[i]] + space + 1;
                if(curDay >= canBeDone) {
                    doneOn[tasks[i]] = curDay;
                    curDay++;
                } else {
                    doneOn[tasks[i]] = canBeDone;
                    curDay = canBeDone+1;
                }
            }
        }
        
        return curDay-1;
    }
};