//49. Group Anagrams

//by vs code
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};


//by chatgpt

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        // pair<sorted_string, original_string>
        vector<pair<string, string>> v;

        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());   // sorted version
            v.push_back({s, strs[i]});
        }

        // sort pairs by sorted_string
        sort(v.begin(), v.end());

        vector<vector<string>> res;
        vector<string> temp;

        for (int i = 0; i < n; i++) {
            // start of new group
            if (i == 0 || v[i].first != v[i - 1].first) {
                if (!temp.empty()) {
                    res.push_back(temp);
                    temp.clear();
                }
            }
            temp.push_back(v[i].second);
        }

        // last group
        if (!temp.empty()) {
            res.push_back(temp);
        }

        return res;
    }
};
