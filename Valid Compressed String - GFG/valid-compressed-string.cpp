//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        // if(T[0]>='0' && T[0]<='9')
        //     return 0;
        int i=0;
        int j=0;
        while(i<S.size() && j<T.size())
        {
            if(T[j]>='A' && T[j]<='Z')
            {
                if(T[j]!=S[i])
                    return 0;
                else
                {
                    j++;
                    i++;
                }
            }
            else
            {
                string skip;
                while(T[j]>='0' && T[j]<='9')
                    skip.push_back(T[j++]);
                i+=stoi(skip);
            }
        }
        if(i==S.size() && j==T.size())
            return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends