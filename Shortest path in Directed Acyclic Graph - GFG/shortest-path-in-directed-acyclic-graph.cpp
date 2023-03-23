//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
  public:
    void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&ans,int dis)
    {
        ans[node]=min(ans[node],dis);
        for(auto &i:adj[node])
        {
            dfs(i.first,adj,ans,dis+i.second);
        }
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(N);
        for(auto &i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>ans(N,INT_MAX);
        dfs(0,adj,ans,0);
        for(int i=0;i<N;i++)
        {
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends