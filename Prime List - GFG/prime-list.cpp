//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    Node *primeList(Node *head){
            
        //store all prime numbers
        vector<int>prime;
        for(int i=2;i<=1e4+100;i++)
        {
            bool flag=true;
            for(int j=2;j<=sqrt(i);j++)
            {
                if(i%j==0)
                    flag=false;
            }
            if(flag)
                prime.push_back(i);
        }
        sort(prime.begin(),prime.end());
        Node* ptr=head;
        while(ptr!=NULL)
        {
            int temp=ptr->val;
            int pos=lower_bound(prime.begin(),prime.end(),temp)-prime.begin();
            if(prime[pos]!=temp)
            {
                int left;
                if(pos==0)
                    left=-1e7;
                else
                    left=prime[pos-1];
                    
                int right=prime[pos];
                if(temp-left<=right-temp)
                    ptr->val=left;
                else
                    ptr->val=right;
            }
                
            ptr=ptr->next;
        }
        
        return head;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends