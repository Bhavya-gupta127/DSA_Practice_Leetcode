//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    string to_binary(int n)
    {
        string s;
        while(n>0)
        {
            s+=to_string(n%2);
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int to_decimal(string s)
    {
        int n=0;
        long long temp=1;
        for(int i=s.size()-1;i>=0;i--)
        {
            n+=temp*(s[i]-'0');
            temp*=2;
        }
        return n;
    }
    int noConseBits(int n) {
        // code here
        string s=to_binary(n);
        for(int i=2;i<s.size();i++)
        {
            if(s[i]=='1' && s[i-1]=='1' && s[i-2]=='1')
                s[i]='0';
        }
        return to_decimal(s);
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends