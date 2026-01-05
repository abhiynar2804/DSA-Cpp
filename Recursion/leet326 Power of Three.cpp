//326 Power of Three

//Recursive Solution
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        if(n == 1) return true;
        if(n % 3 != 0) return false;
        return isPowerOfThree(n / 3);
    }
};

//Iterative Solution
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while (n>0) {
            if(n==1) return true;
            if(n%3!=0) return false;
            n/=3;
        }
        return false;
    }
};