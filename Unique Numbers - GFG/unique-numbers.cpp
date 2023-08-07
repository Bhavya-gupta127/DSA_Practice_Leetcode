//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> uniqueNumbers(int l,int r)
    {
        // Write Your Code here
        //maths 
        vector<int>ans;
        for(int i=l;i<=r;i++)
        {
            string s=to_string(i);
            unordered_set<int>st;
            bool flag=true;
            for(auto &i:s)
            {
                if(st.find(i)!=st.end())
                    flag=false;
                st.insert(i);
                
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l,r ;
        cin >> l >> r;
		Solution ob;
		vector<int> numbers = ob.uniqueNumbers(l,r);
		
		for(int num : numbers){
		   cout<<num<<" ";
		}
		cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends