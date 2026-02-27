//40. Combination Sum II
//https://leetcode.com/problems/combination-sum-ii/description/

//Backtracking
//Time complexity: O(2^t) where t is the target value. In the worst case, we can have 2^t combinations to explore.
//Space complexity: O(t) for the recursion stack and the temporary list used to store the current combination.
class Solution {
public:

    void backTracker(vector<int>& candidates, int target, vector<int>& sum, vector<vector<int>>& ans, int index){
        
        if(target == 0){
            ans.push_back(sum);
            return;
        }
        if(target < 0) return;

        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i] == candidates[i - 1]) continue;
            sum.push_back(candidates[i]);
            backTracker(candidates, target-candidates[i], sum, ans, i + 1);
            sum.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> sum;
        backTracker(candidates, target, sum, ans, 0);
        return ans;
    }
};