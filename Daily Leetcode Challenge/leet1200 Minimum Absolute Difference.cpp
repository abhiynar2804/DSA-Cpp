//1200. Minimum Absolute Difference
//https://leetcode.com/problems/minimum-absolute-difference/
//Date - 26-01-2026

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> arr2;
        int diff = 0;
        // for(int i=0;i<arr.size();i++){
        //     for(int j = i+1;j<arr.size();j++){
        //         if(diff == 0 || arr[j] - arr[i] <= diff){
        //             diff = arr[j] - arr[i];
        //         }
        //     }
        // }

        for (int i = 1; i < arr.size(); i++)
             if (diff == 0 || arr[i] - arr[i - 1] < diff)
                diff = arr[i] - arr[i - 1];

        for (int i = 1; i < arr.size(); i++)
             if (arr[i] - arr[i - 1] == diff)
                arr2.push_back({arr[i - 1], arr[i]});


        return arr2;
    }
};
