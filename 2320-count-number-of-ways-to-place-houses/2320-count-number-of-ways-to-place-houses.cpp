typedef long long ll;
ll mod = 1e9 + 7;

class Solution {    
public:
    int countHousePlacements(int n) {
        ll next = 1, next2 = 1;
        ll cur;
        for(int i = n-1; i >= 0; i--) {
            cur = next + next2;
            next2 = next;
            next = cur % mod;
        }
        
        return (cur * cur) % mod;
    }
};