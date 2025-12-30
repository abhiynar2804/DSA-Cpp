//179. Largest Number

class Solution {
public:
    static bool cc(string a, string b) {
        return (a + b) > (b + a);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        // convert int to string
        for (int x : nums) {
            arr.push_back(to_string(x));
        }

        // sort using custom comparator
        sort(arr.begin(), arr.end(), cc);

        // if the largest is "0", answer is "0"
        if (arr[0] == "0") return "0";

        // build result
        string result = "";
        for (string s : arr) {
            result += s;
        }

        return result;
    }
};


//second approach

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        
        // convert int to string
        for (int x : nums) {
            arr.push_back(to_string(x));
        }
        
        // sort using custom comparator
        sort(arr.begin(), arr.end(), [](string a, string b) {
            return (a + b) > (b + a);
        });
        
        // if the largest is "0", answer is "0"
        if (arr[0] == "0") return "0";
        
        // build result
        string result = "";
        for (string s : arr) {
            result += s;
        }
        
        return result;
    }
};

