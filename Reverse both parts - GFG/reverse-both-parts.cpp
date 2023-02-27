//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    Node *reverseList(Node * head)
    {
        // 1 2 3 4 NULL 
        // 
        Node * newhead=NULL;
        while(head!=NULL)
        {
            Node* temp=head->next;
            head->next=newhead;
            newhead=head;
            head=temp;
        }
        return newhead;
    }
    Node *reverse(Node *head, int k)
    {
        //split the linked list into two parts of size k and n-k reverse both and join
        
        //split
        Node * l1=head;
        Node * ptr=head;
        while(ptr!=NULL && k>1)
        {
            ptr=ptr->next;
            k--;
        }
        Node * l2=ptr->next;
        ptr->next=NULL;
        
        //reverse
        l1=reverseList(l1);
        l2=reverseList(l2);
        
        //join
        head=l1;
        while(l1->next!=NULL)
            l1=l1->next;
        l1->next=l2;
        return head;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends