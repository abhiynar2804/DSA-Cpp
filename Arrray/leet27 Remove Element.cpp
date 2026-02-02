//27. Remove Element

//Greedy Approach
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        vector<int> temp(n, 0);

        int a = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == val){
                a = a + 1;
            }
            else{
                temp[i-a] = nums[i];
            }
        }

        for(int i=0; i<n; i++){
           nums[i] = temp[i];
        }

        return n-a;
    }
};