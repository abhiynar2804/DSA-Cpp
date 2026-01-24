//17. Letter Combinations of a Phone Number

class Solution {
public:
    void covertor(string digits){
        vector<string> cv = {
                cv[2] = "abc";
                cv[3] = "def";
                cv[4] = "ghi";
                cv[5] = "jkl";
                cv[6] = "mno";
                cv[7] = "pqrs";
                cv[8] = "tuv";
                cv[9] = "wxyz"; }
    }

    void solve(vector<string>& ans, string output, string digits, int idx){
        if(idx >= digits.length()){
            ans.push_back(output);
            return;
        }

        output.push_back(covertor(digits[idx]));
        solve(ans, output, )
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int idx = 0;
        string output = "";
        solve(ans, output, digits, idx);
        return ans;
    }
};



//working code
class Solution {
public:
    // keypad mapping
    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void solve(vector<string>& ans, string& output, string& digits, int idx) {
        if (idx == digits.length()) {
            ans.push_back(output);
            return;
        }

        int digit = digits[idx] - '0';
        string letters = mp[digit];

        for (char ch : letters) {
            output.push_back(ch);
            solve(ans, output, digits, idx + 1);
            output.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        string output = "";
        solve(ans, output, digits, 0);
        return ans;
    }
};
