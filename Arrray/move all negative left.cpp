#include <iostream>
using namespace std;
#include <vector>

int main()
{
    // move all negative numbers to the left side of the array
    vector<int> arr = {12, -7, 5, -3, 9, -1, 4, -6};
    int n = arr.size();

    int start = 0, end = n - 1;

    while (start < end)
    {
        if (arr[start] < 0)
        {
            start++;
        }
        else if (arr[end] >= 0)
        {
            end--;
        }
        else
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    cout << "Array after moving negative numbers to the left:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
