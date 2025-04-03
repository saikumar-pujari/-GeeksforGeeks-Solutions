//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        unordered_map<int,int>pmap;
        int sum=0,maxlen=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0)maxlen=i+1;
            if(pmap.find(sum)!=pmap.end()){
                maxlen=max(maxlen,i-pmap[sum]);
                
            }else{
                pmap[sum]=i;
            }
        }return maxlen;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends