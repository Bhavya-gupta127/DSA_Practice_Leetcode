//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        if(b.second!=a.second)
            return a.second<b.second;
        return a.first>b.first;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        //sort by ending time
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
            v.push_back({start[i],end[i]});
        sort(v.begin(),v.end(),cmp);
        int ans=1;
        int prevend=v[0].second;
        for(int i=1;i<n;i++)
        {
            if(v[i].first>prevend)
            {
                ans++;
                prevend=v[i].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends