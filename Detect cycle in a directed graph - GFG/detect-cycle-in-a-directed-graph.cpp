//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<int>adj[])
    {
        if(pathvis[node]==1)
            return true;
        if(vis[node]==1)
            return false;
        vis[node]=1;
        pathvis[node]=1;
        for(auto i:adj[node])
        {
            if(dfs(i,vis,pathvis,adj))
                return true;
        }
        pathvis[node]=0;    
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,vis,pathvis,adj))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends