//205. Isomorphic Strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        char mapping_s_to_t[256] = {0};
        char mapping_t_to_s[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (mapping_s_to_t[c1] == 0 && mapping_t_to_s[c2] == 0) {
                mapping_s_to_t[c1] = c2;
                mapping_t_to_s[c2] = c1;
            } else if (mapping_s_to_t[c1] != c2 || mapping_t_to_s[c2] != c1) {
                return false;
            }
        }

        return true;
    }
};