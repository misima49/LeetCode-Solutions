class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1 || num == 4) return true;
        // if(1 < num && num < 9) return false;
        
        int st = 1, ed = num/2;
        long long md = (st+ed)/2;
        
        while(st <= ed) {
            if(md*md == num) return true;
            
            if(md*md < num) 
                st = md+1;
            else 
                ed = md-1;
            
            md = (st+ed)/2;
        }
        
        return false;
    }
};