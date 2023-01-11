//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int checkFreeEle(set<int>&s2, int n)
    {
        if(s2.find(n)==s2.end())
            return n;
        return checkFreeEle(s2,n+1);
    }
    
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        sort(arr.begin(),arr.end());
        // 1 1 2 3 4 5 5 6 7 8 8
        set<int>s1;
        set<int>s2(arr.begin(),arr.end());
        // auto* i=s2;        
        
        
        int i=1;
        long long ans=0;
       for(int i=0;i<N;i++)
       {
           if(s1.find(arr[i])==s1.end())
           {
               s1.insert(arr[i]);
           }
           else
           {
               int temp=checkFreeEle(s2,arr[i]);
               ans+=temp-arr[i];
               s1.insert(temp);
               s2.insert(temp);
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends