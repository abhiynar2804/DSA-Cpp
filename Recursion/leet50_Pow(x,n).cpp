//50. Pow(x, n)

//recursive approach 
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;   // convert to long long to handle INT_MIN case
        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        return power(x, N);
    }
    
    double power(double x, long long n) {
        if (n == 0) return 1.0;
        
        double half = power(x, n / 2);
        
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};
