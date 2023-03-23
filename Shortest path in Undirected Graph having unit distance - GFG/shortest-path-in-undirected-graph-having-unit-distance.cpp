//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        //normal bfs starting from src
        vector<vector<int>>adj(N);
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>dist(N,1e7);
        vector<int>vis(N,0);
        queue<int>q;
        
        q.push(src);
        vis[src]=1;
        int n=0;
        while(!q.empty())
        {
            int s=q.size();
            for(int k=0;k<s;k++)
            {
                int node=q.front();
                q.pop();
                dist[node]=min(dist[node],n);
                for(auto &i:adj[node])
                {
                    // dist[i]=min(dist[i],n);
                    if(vis[i]!=1)
                    {
                        vis[i]=1;
                        q.push(i);
                        
                    }
                }
                
            }
            n++;
        }
        for(auto &i:dist)
            if(i==1e7) i=-1;
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends