//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int overlap(vector<pair<int,int>>v, int n){
        map<int,int>mp;
        for(auto &i:v)
        {
            mp[i.first]++;
            mp[i.second+1]--;
        }
        int ans=0,res=0;
        for(auto &i:mp)
        {
            ans+=i.second;
            res=max(res,ans);
        }
        return res;
    }
        //Write your code here
        //  {{1, 8}, {2, 5}, {5, 6}, {3, 7},{9,10}}
        
        // 1 8
        // 2 5
        // 3 7
        // 5 6
        // int ans=0;
        // sort(v.begin(),v.end()
        // // ,
        // // []
        // // (pair<int,int>&a, pair<int,int>&b)
        // //     {
        // //         if(a.first==b.first) 
        // //             return b.second>a.second;
        // //         return a.first<b.first;
                
        // //     }
        // );
        // for(int i=0;i<v.size();i++)
        // {
        //     int end=v[i].second;
        //     int low=i+1,high=n-1,mid;
        //     while(low<=high)
        //     {
        //         mid=low+(high-low)/2;
        //         if(v[mid].first<=end)
        //         {
        //             ans=max(ans,mid-i);
        //             low=mid+1;
        //         }
        //         else
        //             high=mid-1;
            
        //     }
        // }
        // return ans+1;
    
    // }
};

// 2 12
// 5 19
// 7 19
// 13 13
// 14 23
// 15 24





//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<pair<int,int>>intervals;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        intervals.push_back({a, b});
	    }
	    Solution ob;
	    int ans = ob.overlap(intervals, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends