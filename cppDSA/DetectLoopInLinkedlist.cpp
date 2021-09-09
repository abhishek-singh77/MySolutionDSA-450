//Initial template code for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


 // } Driver Code Ends
//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(!head) return false;
        
        //using two pointers and moving one pointer(slow) by one node and 
        //another pointer(fast) by two nodes in each iteration.
        Node* fast = head->next;
        Node* slow = head;
        
        while( fast != slow)
        {
            //if the node pointed by first pointer(fast) or the node 
            //next to it is null, we return false.
            if( !fast || !fast->next ) 
            return false;
            
            fast=fast->next->next;
            slow=slow->next;
        }
        //if we reach here it means both the pointers fast and slow point to 
        //same node which shows the presence of loop so we return true.
        return true;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}
  // } Driver Code Ends
