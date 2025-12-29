//443. String Compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, left = 0;
        
        for (int read = 0; read < n; ++read) {
            if (read + 1 == n || chars[read] != chars[read + 1]) {
                chars[write++] = chars[read];
                int count = read - left + 1;
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[write++] = c;
                    }
                }
                left = read + 1;
            }
        }
        
        return write;   
    }
};