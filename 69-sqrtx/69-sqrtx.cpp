class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int croot = x/2+1;
        int nroot = x/2;
        
        while(croot > nroot) {
            croot = nroot;
            nroot = (croot + x/croot)/2;
        }
        
        return croot;
    }
};