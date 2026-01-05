//344. Revwerse String

//recursive approach
class Solution {
private:
    void reverseHelper(vector<char>& s, int left, int right) {
        if (left >= right) {
            return;
        }
        swap(s[left], s[right]);
        reverseHelper(s, left + 1, right - 1);
    }
public:
    void reverseString(vector<char>& s) {
        reverseHelper(s, 0, s.size() - 1);
        return;
    }
};

//iterative approach
class Solution {
public:
    void reverseString(vector<char>& s) {
        int right = s.size()-1;
        int left =0;
        
        while(left<right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};