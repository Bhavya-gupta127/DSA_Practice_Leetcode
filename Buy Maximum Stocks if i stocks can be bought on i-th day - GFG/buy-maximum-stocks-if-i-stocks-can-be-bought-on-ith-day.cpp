//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //krite your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({price[i],i+1});
            // cout<<price[i]<<" "<<i+1<<" "<<price[i]*(i+1)<<"\n";
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int p=v[i].first;
            int q=v[i].second;
            // cout<<p<<" "<<q<<" "<<p*q<<" "<<k<<"\n";
            if(p*q<=k)
            {
                ans+=q;
                k-=p*q;
            }
            else
            {
                // 10*5 >40
                // 40/10=>4
                ans+=k/p;
                k-=p*(k/p);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends