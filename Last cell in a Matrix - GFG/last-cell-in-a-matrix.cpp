//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> solve(int i, int j, int direc,vector<vector<int>>&matrix)
    {
        // 0 -> right
        // 1->down
        // 2->left 
        // 3->up
        // cout<<i<<" "<<j<<"\n";
        if(i>=matrix.size() || j>=matrix[0].size())
        {
            if(direc==0)
                return {i,j-1};
            else if(direc==1)
                return {i-1,j};
            else if(direc==2)
                return {i,j+1};
            else if(direc==3)
                return {i+1,j};
        }

        if(matrix[i][j]==1)
        {
            matrix[i][j]=0;
            direc=(direc+1)%4;
        }

        pair<int,int>ans;
        if(direc==0)
            ans=solve(i,j+1,direc,matrix);
        else if(direc==1)
            ans=solve(i+1,j,direc,matrix);
        else if(direc==2)
            ans=solve(i,j-1,direc,matrix);
        else if(direc==3)
            ans=solve(i-1,j,direc,matrix);
        return ans;
    }
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        return solve(0,0,0,matrix);
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends