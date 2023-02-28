//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        vector<int>prefix(n);
        prefix[0]=a[0];
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+a[i];
            
        vector<int>ans;
        ans.push_back(0);
        if(n==1)
            return ans;
        ans.push_back(a[1]-a[0]);
        for(int i=2;i<n;i++)
        {
            int mid=ceil((double)i/2);
            int temp=prefix[i]-prefix[mid]-prefix[mid-1];
            if(i%2==1)
                temp+=a[mid];
            ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends