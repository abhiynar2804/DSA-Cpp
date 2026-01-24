//22. Generate Parentheses

class Solution {
public:
    void solve(vector<string> &ans,string output, int n, int open, int close){
        // if(output.length() == n*2) return;
        //base case
        if(open == 0 && close == 0) {
            ans.push_back(output);
            return;
        }

        //incluse open
        if(open > 0){
            output.push_back('(');
            solve(ans, output, n, open - 1, close);
            //backTrack
            output.pop_back();
        }

        //include close
        if(close > open){
            output.push_back(')');
            solve(ans, output, n, open, close - 1);
            //backtrack
            output.pop_back();
        }

        // while(output.length() == n*2){
        //     if(open == close){
        //         ans.push_back("(");
        //         open--;
        //     }else{
        //         ans.push_back(")");
        //         close--;
        //     }
        // }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;
        string output = "";
        solve(ans, output, n, open, close);
        return ans;
    }
};


//shorter code for better time and space complexity
class Solution {
public:
    void solve(vector<string>& ans, string output, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(output);
            return;
        }

        if (open > 0) {
            solve(ans, output + "(", open - 1, close);
        }

        if (close > open) {
            solve(ans, output + ")", open, close - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", n, n);
        return ans;
    }
};
