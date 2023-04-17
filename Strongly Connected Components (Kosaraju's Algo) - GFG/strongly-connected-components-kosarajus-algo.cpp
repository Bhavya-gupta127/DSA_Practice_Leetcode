//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	private:
	void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st)
	{
	    vis[node]=1;
	    for(auto i:adj[node])
	    {
	        if(vis[i]!=1)   
	            dfs(i,adj,vis,st);
	    }
	    st.push(node);
	}
	private:
	void dfs3(int node,vector<vector<int>>&adjT,vector<int>&vis)
	{
	    vis[node]=1;
	    for(auto i:adjT[node])
	    {
	        if(vis[i]!=1)   
	            dfs3(i,adjT,vis);
	    }
	}
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //sort edges acc to time
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(vis[i]!=1)
                dfs(i,adj,vis,st);
        }

        // reverse graph
        vector<vector<int>>adjT(V);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                adjT[it].push_back(i);
            }
            vis[i]=0;
        }
        
        //count scc
        int ans=0;
        while(!st.empty())
        {
            int i=st.top();
            st.pop();
            if(vis[i]!=1)
            {
                ans++;
                dfs3(i,adjT,vis);
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends