//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    
    public:
    static bool cmp(pair<int,int>a,pair<int,int>b)
    {
        if(__builtin_popcount(a.first)==__builtin_popcount(b.first))
            return a.second<b.second;
        return __builtin_popcount(a.first)>__builtin_popcount(b.first);
    }
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int,int>>binary;
        
        for(int i=0;i<n;i++)
            binary.push_back({arr[i],i});
        
        sort(binary.begin(),binary.end(),cmp);
        for(int i=0;i<n;i++)
            arr[i]=binary[i].first;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends