//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        // 4 2
        // 3 2 1 4
        
        // 1 2 3 4 
        // | | | |
        // B B F F
        // 3
        
        // 1 2 3 4
        // | | | |
        // F F B B
        
        sort(candies,candies+N);
        int mn=0,mx=0;
        int i=0,j=N;
        while(i<j)
        {
            mn+=candies[i];
            i++;
            j=j-K;
        }
        i=N-1;
        j=-1;
        while(i>j)
        {
            mx+=candies[i];
            i--;
            j=j+K;
        }
        return {mn,mx};
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends