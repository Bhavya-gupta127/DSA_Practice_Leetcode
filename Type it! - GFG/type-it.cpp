//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int common=0;
        for(int i=1;i<=s.size()/2;i++)
        {
            string s1=s.substr(0,i);
            string s2=s.substr(i,i);
            if(s1==s2)
                common=i;
        }
        return common==0?s.size():s.size()-common+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends