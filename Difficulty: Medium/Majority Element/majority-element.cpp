//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int val=0;
        int n=arr.size();
        int num=0;
        for(int i=0;i<n;i++){
            if(val==0){
                num=arr[i];
                val++;
            }else if(arr[i]==num){
                val++;
            }else{
                val--;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==num)
            count++;
        }if(count>n/2)return num;
        else return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends