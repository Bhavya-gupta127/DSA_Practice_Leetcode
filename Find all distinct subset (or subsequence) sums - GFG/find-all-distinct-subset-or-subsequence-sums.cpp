//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void solve(int i,int sum,vector<int>&nums,set<int>&st,vector<vector<int>>&dp)
    {
        if(i==nums.size())
        {
            st.insert(sum);
            return;
        }
        if(dp[i][sum]!=-1) return;
        dp[i][sum]=1;
        solve(i+1,sum+nums[i],nums,st,dp);
        solve(i+1,sum,nums,st,dp);
    }
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    set<int>st;
	    vector<vector<int>>dp(nums.size(),vector<int>(1e4+10,-1));
	    solve(0,0,nums,st,dp);
	    vector<int>res(st.begin(),st.end());
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends