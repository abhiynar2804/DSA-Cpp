//258. Add Digits

//recursive approach
class Solution {
public:
    int addDigits(int num) {
        if (num < 10)
            return num;

        int sum = digitSum(num);

        return addDigits(sum);
    }

    int digitSum(int num) {
        if (num == 0)
            return 0;

        return (num % 10) + digitSum(num / 10);
    }
};


// math trick approach
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
