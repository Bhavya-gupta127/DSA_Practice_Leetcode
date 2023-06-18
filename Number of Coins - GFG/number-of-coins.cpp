//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:

	int solve(int i,int coins[], int M, int V,vector<vector<int>>&dp)
	{
	    if(V==0)
	        return 0;
	    if(i>=M || V<0)
	        return 1e9;
	    if(dp[i][V]!=-1)
	        return dp[i][V];
        int pick=1e9,notpick=1e9;
        pick=solve(i,coins,M,V-coins[i],dp)+1;
        notpick=solve(i+1,coins,M,V,dp);
        return dp[i][V]=min(pick,notpick);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	    int ans= solve(0,coins,M,V,dp);
	    return ans==1e9?-1:ans;
	  
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends