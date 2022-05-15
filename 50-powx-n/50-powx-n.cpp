class Solution {
public:
    double myPow(double x, int n) {
        long int nn = n;
        if(nn < 0) nn *= -1;
        
        double answer = 1.0;
        
        while(nn) {
            if(nn%2 == 0) {
                x = x*x;
                nn /= 2;
            } else {
                answer *= x;
                nn--;
            }
        }
        
        if(n < 0) return 1/answer;
        
        return answer;
    }
};