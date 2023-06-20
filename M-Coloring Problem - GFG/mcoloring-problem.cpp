//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int i,int node,vector<int>&colors,vector<vector<int>>&adj)
    {
        for(auto nextnode:adj[node])
            if(colors[nextnode]==i)
                return false;
        return true;
    }
    bool solve(int node,int n,vector<vector<int>>&adj,vector<int>&colors,int m)
    {
        if(node==n)
            return true;
        for(int i=1;i<=m;i++)
        {
            if(isSafe(i,node,colors,adj))
            {
                colors[node]=i;
                if(solve(node+1,n,adj,colors,m))
                    return true;
                colors[node]=-1;
            }
        }
        return false;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j])
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>colors(n,-1);
        return solve(0,n,adj,colors,m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends