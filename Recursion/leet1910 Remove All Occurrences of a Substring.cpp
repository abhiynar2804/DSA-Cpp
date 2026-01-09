//1910. Remove All Occurrences of a Substring

//recursive approach
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        if(pos == string::npos) return s;

        s.erase(pos, part.length());
        return removeOccurrences(s, part);
    }
};

//already solved when doing arrays
//approach: keep finding the substring and erasing it until it is no longer found
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);

        while (pos != string::npos) {
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }
};