//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
         if (s.empty() || k == 0) return -1;  
    if (unordered_set<char>(s.begin(), s.end()).size() < k) return -1;
        int l=0;
        unordered_map<char,int>sub;
        int maxlen=0;
        for(int r=0;r<s.size();r++){
            sub[s[r]]++;
            while(sub.size()>k){
                sub[s[l]]--;
                if(sub[s[l]]==0)
                sub.erase(s[l]);
                l++;
            }maxlen=max(maxlen,r-l+1);
        }
        return maxlen > 0 ? maxlen : -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends