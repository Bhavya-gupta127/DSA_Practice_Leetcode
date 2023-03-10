//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detectcycle(int i,vector<int>&vis,vector<int>adj[])
    {
        queue<pair<int,int>>q;
        q.push({i,-1});
        vis[i]=1;
        while(!q.empty())
        {
            int prev=q.front().second;
            int cur=q.front().first;
            q.pop();
            for(int j=0;j<adj[cur].size();j++)
            {
                if(vis[adj[cur][j]]==1 && adj[cur][j]!=prev)
                    return true;
                if(vis[adj[cur][j]]!=1)
                    q.push({adj[cur][j],cur});
                vis[adj[cur][j]]=1;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]!=1)
                if(detectcycle(i,vis,adj))
                    return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends