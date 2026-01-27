//279. Perfect Squares

//brute force TLE
//TLE issue
class Solution {
public:
    void Squares(int n, int root, int ans, int& count){
        if(n == 0) return;
        if(n == 3){
            count = count + 2;
            return;
        }
        float root2 = sqrt(n); 
        ans = (int)root2 * (int)root2;
        if(ans <= n) {
            count = count + 1;
        }
        Squares(n-ans, (int)root2, ans, count);
    }

    int numSquares(int n) {
        if(n == 0) return 0;
        float root = sqrt(n); 
        int ans = (int)root * (int)root;
        int count = 0;
        if(ans <= n) {
            count = count + 1;
        }
        
        Squares(n-ans, (int)root, ans, count);

        return count;     
    }
};


// Greedy + recursive approach
class Solution {
public:
    void Squares(int n, int& count){
        if(n == 0) return;
        int root = (int)sqrt(n);
        int ans = root * root;

        count += 1; 
        Squares(n - ans, count); 
    }

    int numSquares(int n) {
        int count = 0;
        Squares(n, count);
        return count;
    }
};

//Mathematical approach
// Optimal approach using Lagrange's Four Square Theorem

class Solution {
public:
    bool isPerfectSquare(int n) {
        int r = (int)sqrt(n);
        return r * r == n;
    }

    int numSquares(int n) {
        if (isPerfectSquare(n)) return 1;
        for (int i = 1; i * i <= n; i++) {
            if (isPerfectSquare(n - i * i)) return 2;
        }

        int temp = n;
        while (temp % 4 == 0) temp /= 4;
        if (temp % 8 == 7) return 4;

        return 3;
    }
};

