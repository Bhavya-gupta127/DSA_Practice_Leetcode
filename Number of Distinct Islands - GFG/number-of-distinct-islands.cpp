//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,vector<pair<int,int>>&v,int s,int e)
    {
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || vis[i][j]==1 ||grid[i][j]==0) 
            return ;
        vis[i][j]=1;
        v.push_back({s-i,e-j});
        vector<int>delrow={0,0,1,-1};
        vector<int>delcol={1,-1,0,0};
        for(int x=0;x<4;x++)
        {
            int r=i+delrow[x];
            int c=j+delcol[x];
            dfs(r,c,vis,grid,v,s,e);
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {

        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        set<vector<pair<int,int>>>myset;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(vis[i][j]!=1)
                {
                    vector<pair<int,int>>v;
                    dfs(i,j,vis,grid,v,i,j);
                    if(myset.find(v)==myset.end() && !v.empty())
                        myset.insert(v);
                }
            }
        }
        
        
        return myset.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends