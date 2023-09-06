//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int mod=1e9+7;
	    int solve(int i,string s,vector<int>&dp)
	    {
	        if(i>=s.size()) return 1;
	        if(s[i]=='0') return 0;
	        if(dp[i]!=-1) return dp[i];
	        long long pick1=0,pick2=0;
	        pick1=solve(i+1,s,dp);
	        if(i!=s.size()-1 && (s[i]=='1' || (s[i]=='2'  &&  s[i+1]<='6')))
	            pick2=solve(i+2,s,dp);
	        return dp[i]=(pick1+pick2)%mod;
	    }
		int CountWays(string str){
		    vector<int>dp(str.size(),-1);
		    int ans= solve(0,str,dp);
		  //  for(auto i:dp)
		  //      cout<<i<<" ";
	        return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends