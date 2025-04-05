//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
   int mergeAndCount(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    int count = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
            count += (mid - left + 1); // Count inversions
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; ++i) {
        arr[i] = temp[i - low];
    }

    return count;
}

int mergeSortAndCount(vector<int>& arr, int low, int high) {
    int count = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;
        count += mergeSortAndCount(arr, low, mid);
        count += mergeSortAndCount(arr, mid + 1, high);
        count += mergeAndCount(arr, low, mid, high);
    }
    return count;
}

int inversionCount(vector<int> &arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends