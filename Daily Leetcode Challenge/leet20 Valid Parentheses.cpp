//20. Valid Parentheses
//https://leetcode.com/problems/valid-parentheses/
//Date: 30-01-2026

//first attempt
//failed for some test cases like "([)]" or "{[(})]"
class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 != 0) return false;

        int i = 0;
        int sqr = 0;
        int brc = 0;
        int cbr = 0;

        while(i < s.length()){
            if(s[i] == '[' || s[i] == ']'){
                sqr++;
                i++;
            }if(s[i] == '(' || s[i] == ')'){
                brc++;
                i++;
            }if(s[i] == '{' || s[i] == '}'){
                cbr++;
                i++;
            }
        }

        if(sqr%2 == 0 && brc%2 == 0 && cbr%2 == 0) return true;
        return false;
    }
};

//second attempt
//using stack to check for valid parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char c = st.top();
                if((c == '(' && s[i] == ')') || (c == '[' && s[i] == ']') || (c == '{' && s[i] == '}')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};