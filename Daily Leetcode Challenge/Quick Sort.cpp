//Quick Sort
//https://www.geeksforgeeks.org/problems/quick-sort/1
//Date: 24-02-2026


// C++ program for implementation of Quick Sort
//without using partition function
class Solution {
  public:
    void quickSort(vector<int>& arr, int start, int end) {
        if(start >= end) return;
        int pivot = end;
        int i = start - 1;
        int j = start;
        
        while(j < pivot){
            if(arr[j] < arr[pivot]){
                ++i;
                swap(arr[i], arr[j]);
            }
            j++;
        }
        
        i++;
        swap(arr[i], arr[pivot]);
        
        quickSort(arr, start, i - 1);
        quickSort(arr, i + 1, end);
        
    }

  public:
    int partition(vector<int>& arr, int start, int end) {
        
    }
};


//with partition function
class Solution {
  public:
    void quickSort(vector<int>& arr, int start, int end) {
        if(start >= end) return;
        int pivot = partition(arr, start, end);
        
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
        
    }

  public:
    int partition(vector<int>& arr, int start, int end) {
        int pivot = arr[end];
        int i = start - 1;
        
        for(int j = start; j < end; j++){
            if(arr[j] < pivot){
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        
        i++;
        swap(arr[i], arr[end]);
        
        return i;
    }
};