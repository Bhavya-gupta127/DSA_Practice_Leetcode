//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int mod=1e9+7;
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i>=grid.size() || j>=grid[i].size() || i<0 || j<0 || grid[i][j]==0)
            return 0;
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        grid[i][j]=0;
        ans+=solve(i+1,j,grid,dp)%mod;
        ans+=solve(i,j+1,grid,dp)%mod;
        grid[i][j]=1;
        return dp[i][j]=ans;
    }
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,grid,dp)%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends