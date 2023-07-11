//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int i,int prev,int arr[],int n,vector<vector<int>>&dp)
	{
	    if(i>=n)
	        return 0;
	    if(dp[i][prev+1]!=-1)    
	        return dp[i][prev+1];
        int pick=0,notpick=0;
        
        if(arr[prev]<arr[i])
        {
            pick=solve(i+1,i,arr,n,dp)+arr[i];
            // cout<<prev<<" is less than "<<arr[i]<<" and if pick : "<<dp[i][0]<<"\n";
        }
        notpick=solve(i+1,prev,arr,n,dp);
        return dp[i][prev+1]=max(pick,notpick);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,arr,n,dp);
        // for(auto i:dp)
        //     cout<<i[0]<<" "<<i[1]<<"\n";
        // return 0;
	    // Your code goes here
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends