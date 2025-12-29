#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int firstOccurence(const vector<int>& v, int target) {
    int start = 0;
    int end = v.size() - 1;

    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (v[mid] == target) {
            ans = mid;
            end = mid - 1; // continue searching in the left half
        }
        else if (v[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    

    return ans;
}

int lastOccurence(const vector<int>& v, int target) {
    int start = 0;
    int end = v.size() - 1;

    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (v[mid] == target) {
            ans = mid;
            start = mid + 1; // continue searching in the right half
        }
        else if (v[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    

    return ans;
}

int main() {
//   vector<int> v{1,2,3,4,5,6};

//   if(binary_search (v.begin(), v.end(), 3)) {
//     cout << "Found" << endl;
//   }
//   else {
//     cout << "Not Found" << endl;
//   }

    
    vector<int> v{2,3,4,4,4,4,4,6,7,9};

    // find the first occurrence of element
    // int target = 4;
    // int indexOfFirstOCc = firstOccurence(v, target);

    // cout << "First Occurrence of " << target << " is at index: " << indexOfFirstOCc << endl;

    // find the last occurrence of element
    int target = 4;
    int indexOfLastOcc = lastOccurence(v, target);

    cout << "Last Occurrence of " << target << " is at index: " << indexOfLastOcc << endl;
  
  return 0;
}