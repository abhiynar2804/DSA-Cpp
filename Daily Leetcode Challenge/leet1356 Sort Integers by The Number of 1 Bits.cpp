//1356. Sort Integers by The Number of 1 Bits
//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/
//Date: 25-02-2026

//Custom Sort with Comparator
//Time Complexity: O(n log n)
class Solution {
public:
    static int findWeight(int num) {
        int mask = 1;
        int weight = 0;
        
        while (num > 0) {
            if ((num & mask) > 0) {
                weight++;
                num ^= mask;
            }
            
            mask <<= 1;
        }
        
        return weight;
    }
    
    static bool compare(int a, int b) {
        if (findWeight(a) == findWeight(b)) {
            return a < b;
        }
        
        return findWeight(a) < findWeight(b);
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};


//Custom Sort with Lambda Function
//Time Complexity: O(n log n)
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end() , [] (int a, int b){
        int countA=__builtin_popcount(a);
        int countB=__builtin_popcount(b);
        if(countA==countB) return a<b;
        return countA<countB;
        });
        return arr;
    }
};