//for coding ninja
bool isPossible(vector<int>& arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;   // edge case

    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}



// for geeksforgeeks
class Solution {
  public:
  
    bool isPossible(vector<int> &arr, int n, int k, int mid)
    {
        int studentCount = 1;
        int pageSum = 0;

        for (int i = 0; i < n; i++)
        {
            if (pageSum + arr[i] <= mid)
            {
                pageSum += arr[i];
            }
            else
            {
                studentCount++;
                if (studentCount > k || arr[i] > mid)
                {
                    return false;
                }
                pageSum = arr[i];
            }
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if (k > n) return -1;   // important edge case

        int s = 0;
        int sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        int e = sum;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (isPossible(arr, n, k, mid))
            {
                ans = mid;
                e = mid - 1;  // try smaller answer
            }
            else
            {
                s = mid + 1;  // increase pages
            }
        }
        return ans;
    }
};
