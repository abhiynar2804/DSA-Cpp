//Print all subarrays of an array

//recursive approach
#include <iostream>
using namespace std;
#include <vector>

void printSubarrays(vector<int>& arr, int start, int end, int n) {
    if(start == n) return;
    
    while(end < n) {
        for(int i = start; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        end++;
    }
    printSubarrays(arr, start + 1, start + 1, n);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int start = 0;
    int end = start;
    int n = arr.size();

    printSubarrays(arr, start, end, n);

    return 0;
}