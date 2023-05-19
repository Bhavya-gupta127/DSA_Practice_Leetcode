//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Hereset<
        set<char>myset;
        for(auto i:a)
            myset.insert(i);
        char swapfrom='#',swapwith='#';
        for(int i=0;i<a.size() && !myset.empty();i++)
        {
            if(a[i]>*myset.begin())
            {
                swapfrom=a[i];
                swapwith=*myset.begin();
                break;
            }
            if(a[i]==*myset.begin())
                myset.erase(*myset.begin());
        }
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==swapfrom)
                a[i]=swapwith;
            else if(a[i]==swapwith)
                a[i]=swapfrom;
        }
        return a;
        
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends