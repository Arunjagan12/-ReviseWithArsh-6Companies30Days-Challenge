class Solution {
public:

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long  mul  = ( long )divisor1*divisor2/gcd(divisor1, divisor2); 
        int  lo  =  1 , hi= INT_MAX; 
        // binary search 
        while (lo<hi) { 
            int  mid  = lo+(hi-lo)/ 2 ; 
            if (mid -(mid/divisor1) >= uniqueCnt1 
                && mid-(mid/divisor2) >=uniqueCnt2 
                && mid-(mid/mul) >= uniqueCnt1+uniqueCnt2) { 
                   
                     hi = mid; 
            } else 
                 lo = mid+ 1 ; 
        } 
        return lo; 
    }
     int  gcd ( int a, int b) { 
        if (a== 0 ) return b; 
        return gcd(b%a, a); 
    } 
};

