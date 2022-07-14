class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int boatCount = 0;
        int st = 0, ed = people.size()-1;
        while(st < ed) {
            if(people[st]+people[ed] <= limit) {
                st++;
                ed--;
            } else {
                ed--;
            }
            boatCount++;
        }
        if(st == ed) boatCount++;
        
        return boatCount;
    }
};