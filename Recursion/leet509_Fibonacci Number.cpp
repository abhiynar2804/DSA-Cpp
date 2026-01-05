//leet509_Fibonacci Number

//recursive
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        return fib(n-1) + fib(n-2);
    }
};

//iterative
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        int n1 = 0, n2 = 1;
        for(int i = 2; i <= n; i++){
            int ans = n2;
            n2 = n1+n2;
            n1 = ans;
        }
        return n2;
    }
};
