//14. Longest Common Prefix

// by me not working
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[1[1]] + strs[1[2]];
        int ans1;
        int count = strs.length();
        for(int i=0; i < count; i++){
            if(ans == strs[i[1]] + strs[i[2]]){
                ans1++;
            }
        }
        if(ans1 == count){
            return ans;
        }
        else{
            return "";
        }
    }
};

//by vs code
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            while(strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if(prefix.empty()) return "";
            }
        }
        return prefix;
    }
};  