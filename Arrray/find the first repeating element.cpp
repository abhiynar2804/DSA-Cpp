class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i<n; i++){
            bool isReapeated = false;
            for(int j = i+1; j<n; j++){
                if(arr[i] == arr[j]){
                    isReapeated = true;
                    return i+1;
                }
            }
        }
        return -1;
    }
};