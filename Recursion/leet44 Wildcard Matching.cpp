//44. Wildcard Matching

//brute force approach
//becouse of time limit exceeded, it will not pass all test cases
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == p) return true;

        if (s.length() != p.length()) {
            if (p == "*") return true;
            return false;
        }

        int ans = p.find("?");

        if (ans >= 0) {
            p.replace(ans, 1, 1, s[ans]);
            if (s == p) return true;
            return isMatch(s, p);   
        }

        return false;
    }
};


//Recursive Approach
//this question not pass all test cases due to time limit exceeded
//DP approach is better for this question
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p[0] == '*') {
            return isMatch(s, p.substr(1)) || (!s.empty() && isMatch(s.substr(1), p));
        } else {
            bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '?'));
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
        return false;
    }
};

//greedy solution
//it will pass all test cases
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIdx = -1;
        int match = 0;

        while (i < s.size()) {
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }else if (j < p.size() && p[j] == '*') {
                starIdx = j;
                match = i;
                j++;
            }else if (starIdx != -1) {
                j = starIdx + 1;
                match++;
                i = match;
            }else return false;
            
        }

        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};


