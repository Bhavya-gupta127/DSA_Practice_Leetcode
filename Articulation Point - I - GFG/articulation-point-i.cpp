//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    int timer=1;
    
    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,vector<int>&tin,vector<int>&low,vector<int>&mark)
    {
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto i:adj[node])
        {
            if(i==parent)
                continue;
            if(vis[i]==0)
            {
                dfs(i,node,adj,vis,tin,low,mark);
                low[node]=min(low[node],low[i]);
                if(low[i]>=tin[node] && parent!=-1)
                    mark[node]=1;
                child++;
            }
            else
            {
                low[node]=min(low[node],tin[i]);
            }
        }
        if(parent==-1 && child>1)
            mark[node]=1;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>tin(V),low(V),vis(V,0),mark(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]!=1)
                dfs(i,-1,adj,vis,tin,low,mark);
        }
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(mark[i]==1)
                ans.push_back(i);
        }
        if(ans.empty())
            return {-1};
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends