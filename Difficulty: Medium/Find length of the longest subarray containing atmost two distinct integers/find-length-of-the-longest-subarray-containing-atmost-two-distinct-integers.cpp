//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int r=0,l=0,maxlen=0;
        unordered_map<int,int>map;
        for(int r=0;r<arr.size();r++){
            map[arr[r]]++;
            while(map.size()>2){
                map[arr[l]]--;
                if(map[arr[l]]==0){
                    map.erase(arr[l]);
                }l++;
            }maxlen=max(maxlen,r-l+1);
        }return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends