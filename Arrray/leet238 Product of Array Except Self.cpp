//238. Product of Array Except Self


//approach 1: Using Division (Not recommended if nums contains zeroes)
//work on non-zero elements only
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n); 
        int ans = 1;

        for(int i = 0; i < n; i++){
            ans = ans * nums[i];
        }

        for(int i = 0; i < n; i++){
            answer[i] = ans / nums[i]; 
        }

        return answer; 
    }
};


//approach 2: Handling Zeroes
//work on zero and non-zero elements but not on multiple zeroes
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);  
        bool zero = false;

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zero = true;
            }else{
                if(i == 0){
                    ans = nums[i];
                }else{
                 ans = ans * nums[i];
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(zero == true){
                if(nums[i] == 0){
                    answer[i] = ans;
                }else{
                    answer[i] = 0;
                }
            }else{
                answer[i] = ans / nums[i]; 
            }
        }

        return answer;  
    }
};


//approach 3: Handling Multiple Zeroes
//work on multiple zeroes also
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);  
        int zeroCount = 0; 
        int ans = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zeroCount++;
            }else{
                ans *= nums[i];
            }
        }

        for(int i = 0; i < n; i++){
            if(zeroCount > 1){
                answer[i] = 0;
            }else if(zeroCount == 1){
                answer[i] = (nums[i] == 0) ? ans : 0;
            }else{
                answer[i] = ans / nums[i];
            }
        }

        return answer;  
    }
};

