//13. Roman to Integer
//https://leetcode.com/problems/roman-to-integer/
//Date: 29-01-2026

class Solution {
public:
   void convert(char val, int &value) {
        vector<pair<char, int>> chart {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (auto &p : chart) {
            if (p.first == val) {
                value = p.second;
                return;
            }
        }
    }


    int romanToInt(string s) {
        int ans = 0;
        int value = 0;
        int prev;
        for(int i = s.length() - 1; i >= 0; i--){
            prev = value;
            convert(s[i], value);
            if( value >= prev ){
                ans = ans + value;
            }else{
                ans = ans - value;
            }
        }
       return ans;
    }
};