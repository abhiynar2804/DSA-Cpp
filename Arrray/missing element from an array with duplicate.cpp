#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 4, 5, 6, 8, 9};
    int n = arr.size();

    int duplicate = -1;

    // Find duplicate (sorted array → adjacent duplicate)
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            duplicate = arr[i];
            break;
        }
    }

    // Expected sum of 1..9
    int expectedSum = 9 * 10 / 2;  

    // Actual sum of array
    int actualSum = 0;
    for (int x : arr) actualSum += x;

    // Missing = expected - (actual - duplicate)
    int missing = expectedSum - (actualSum - duplicate);

    cout << "Duplicate: " << duplicate << endl;
    cout << "Missing: " << missing << endl;

    // Print final corrected sequence (1..9)
    cout << "(";
    for (int i = 1; i <= 9; i++) {
        cout << i;
        if (i != 9) cout << ",";
    }
    cout << ")";

    return 0;
}
