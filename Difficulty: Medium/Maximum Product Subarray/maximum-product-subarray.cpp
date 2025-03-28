//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
         int n = arr.size();
    int pro1 = 1, pro2 = 1, maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        pro1 *= arr[i];
        pro2 *= arr[n - i - 1]; // Reverse traversal

        maxi = max({maxi, pro1, pro2});

        if (pro1 == 0) pro1 = 1; // Reset if zero is encountered
        if (pro2 == 0) pro2 = 1; // Reset for reverse pass
    }
    return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends