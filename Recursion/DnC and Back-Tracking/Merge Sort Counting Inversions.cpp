//HackerRank Problem: Merge Sort: Counting Inversions
//Link: https://www.hackerrank.com/challenges/ctci-merge-sort/problem

//Solution:
//TC O(n squared) SC O(1)
long countInversions(vector<int> arr) {
    int count = 0;
    for (int i = 0; i<arr.size(); i++) {
        for (int j=i; j<arr.size(); j++) {
            count = arr[i] > arr[j] ? count + 1 : count;
        }
    }
    return count;
}

//Optimal Solution:
//TC O(n log n) SC O(n)
long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long invCount = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            invCount += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return invCount;
}

long mergeSortAndCount(vector<int>& arr, int left, int right) {
    long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

long countInversions(vector<int> arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}
