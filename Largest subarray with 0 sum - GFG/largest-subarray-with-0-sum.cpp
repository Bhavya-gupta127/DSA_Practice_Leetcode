//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        vector<int>prefix={0};

        for(int i=0;i<n;i++)
            prefix.push_back(prefix.back()+A[i]);

        map<int,int>mp;

        for(int i=0;i<=n;i++)
        {
            if(mp.count(prefix[i])==0)
                mp[prefix[i]]=i;    
        }
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            if(mp.count(prefix[i]))
                ans=max(ans,i-mp[prefix[i]]);
        }
        return ans;
        //  {15,-2,2,-8,1,7,10,23}
        // 0 15 13 15 7 8 15 25 48 
        // 0 1   2  3 4 5 6  7  8  
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends