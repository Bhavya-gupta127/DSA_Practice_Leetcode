//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
    vector<int>rank,parent;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findUpar(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)
            return;
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])
            parent[ulp_v]=ulp_u;
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int adjnode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjnode}});
            }
        }
        sort(edges.begin(),edges.end());
        
        DisjointSet ds(V);
        int ans=0;
        for(auto i:edges)
        {
            int wt=i.first;
            int u=i.second.first;
            int v=i.second.second;
            if(ds.findUpar(u)!=ds.findUpar(v)) // if not connected
            {
                ans+=wt;
                ds.unionByRank(u,v);
            }
            
        }
        return ans;
        
        
        // // prims code
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // pq.push({0,0});
        // vector<int>vis(V,0);
        // int sum=0;
        // while(!pq.empty())
        // {
        //     int wt=pq.top().first;
        //     int node=pq.top().second;
        //     pq.pop();
        //     if(vis[node]==1) continue;
        //     vis[node]=1;
        //     sum+=wt;
        //     for(auto i:adj[node])
        //     {
        //         if(vis[i[0]]!=1)
        //             pq.push({i[1],i[0]});
        //     }
        // }
        // return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends