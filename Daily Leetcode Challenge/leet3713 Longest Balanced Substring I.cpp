//3713. Longest Balanced Substring I
//https://leetcode.com/problems/longest-balanced-substring-i/
//Date: 12-02-2026

//first try -
class Solution {
public:
    bool checkBalanced(vector<int>& freq) {
        int common = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(common == 0)
                common = freq[i];
            else if(freq[i] != common)
                return false;
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxL = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if(checkBalanced(freq)) {
                    maxL = max(maxL, j - i + 1);
                }
            }
        }
        return maxL;        
    }
};


//second try
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;
        vector<int> cnt(26);
        for (int i = 0; i < n; i++) {
            fill(cnt.begin(), cnt.end(), 0);
            for (int j = i; j < n; j++) {
                bool flag = true;
                int c = s[j] - 'a';
                cnt[c]++;
                for (auto x : cnt) {
                    if (x > 0 && x != cnt[c]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};