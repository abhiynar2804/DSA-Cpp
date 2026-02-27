//47. Permutations II
//https://leetcode.com/problems/permutations-ii/description/

//Backtracking
class Solution {
public:
    void solve(int index,vector<int>& nums, vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_map<int,bool> visited;
        for(int i=index;i<nums.size();i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[i],nums[index]);
            solve(index+1,nums,ans);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};