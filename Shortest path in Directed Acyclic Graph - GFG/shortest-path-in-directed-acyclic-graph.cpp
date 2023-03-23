//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
  public:
    // void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&ans,int dis)
    // {
    //     ans[node]=min(ans[node],dis);
    //     for(auto &i:adj[node])
    //         dfs(i.first,adj,ans,dis+i.second);
    // }
    //  vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    //     vector<vector<pair<int,int>>>adj(N);
    //     for(auto &i:edges)
    //         adj[i[0]].push_back({i[1],i[2]});
    //     vector<int>ans(N,INT_MAX);
    //     dfs(0,adj,ans,0);
    //     for(int i=0;i<N;i++)
    //     {
    //         if(ans[i]==INT_MAX)
    //             ans[i]=-1;
    //     }
    //     return ans;
    // }
    void dfs(int node,vector<vector<pair<int,int>>>&adj,stack<int>&st,vector<int>&vis)
    {
        if(vis[node]==1)
            return;
        vis[node]=1;
        for(auto &i:adj[node])
        {
            if(vis[i.first]!=1)
                dfs(i.first,adj,st,vis);
        }
        st.push(node);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         
        vector<vector<pair<int,int>>>adj(N);
        for(auto &i:edges)
            adj[i[0]].push_back({i[1],i[2]});
        stack<int>st;
        vector<int>vis(N,0);
        for(int i=0;i<N;i++)
            dfs(0,adj,st,vis);
        vector<int>ans(N,1e7);
         
        // while(!st.empty())
        // {
        //     cout<<st.top()<<" ";
        //     st.pop();
        // }
        
        ans[0]=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            for(auto &i:adj[node])
                ans[i.first]=min(ans[i.first],ans[node]+i.second);
        }
        for(auto &i:ans)
            if(i==1e7) i=-1;
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