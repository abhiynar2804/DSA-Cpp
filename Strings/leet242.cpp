//Valid Anagram

// made by me
class Solution {
public:
    bool isAnagram(string s, string t) {
        int ans = 0;
        int i = 0;
        int num = s.length();
    
        while(i <= num){
            if(s.length() == t.length() && s[0] == t[0] )
            {
                return true;
            }
            if(s[i] == t[i]){
                ans++;
            }
            i++;
        }
        if(ans > 3){
            return true;
        }
        else{
            return false;
        }
    }
};

// by vs code
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};