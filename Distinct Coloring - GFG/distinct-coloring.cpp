//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int solve(int i,int prev,vector<vector<int>>&v,vector<vector<long long>>&dp)
    {
        //r=0 g=1 b=2 
        if(i>=v.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        long long int r=LONG_MAX-1,g=LONG_MAX-1,b=LONG_MAX-1;
        if(prev!=0)
            r=solve(i+1,0,v,dp)+v[i][0];
        if(prev!=1)
            g=solve(i+1,1,v,dp)+v[i][1];
        if(prev!=2)
            b=solve(i+1,2,v,dp)+v[i][2];
        return dp[i][prev+1]=min({r,g,b});
        
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here
        vector<vector<int>>v;
        for(int i=0;i<N;i++)
            v.push_back({r[i],g[i],b[i]});
        vector<vector<long long>>dp(N,vector<long long>(4,-1));
        return solve(0,-1,v,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends