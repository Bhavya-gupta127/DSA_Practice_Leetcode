//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int solve(int row,int col,vector<vector<int>>&colors,vector<vector<int>>&dp)
    {
        if(row>=colors.size() || col>2)
            return 0;
        int pink=1e9;
        int black=1e9;
        int yellow=1e9;
        if(dp[row][col+1]!=-1)
            return dp[row][col+1];
        if(col!=0)
            pink=solve(row+1,0,colors,dp)+colors[row][0];
        if(col!=1)
            black=solve(row+1,1,colors,dp)+colors[row][1];
        if(col!=2)
            yellow=solve(row+1,2,colors,dp)+colors[row][2];
        return dp[row][col+1] = min({pink,black,yellow});
        
    }
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.'
        vector<vector<int>>dp(colors.size(),vector<int>(4,-1));
        return solve(0,-1,colors,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends