#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int a){
        data=a;
        next=NULL;
    }
};

void makecycle(node *&head,int pos){
    node *temp=head;
    node *startNode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}
/*
Dist moved by fast ptr=m+n+l*j
Dist moved by fast ptr=m+n+l*i
Dist travelled by fast ptr=2*distance moved by slow ptr
m+n=l*(j-2*i)-n
*/
//Detection of cycle and removal in linked list: Floyd's algorithm or Hare and tortoise algorithm
//The next of two nodes is pointing to the same object
//Fast and slow pointer, what if there are more cycles??
bool detectcycle(node *&head){
    node *slow=head;
    node *fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) return true;
    } 
    return false;
}

/*Removal of cycle
-Move hare to the head move both one by one if next of both is same, we can determine the start of cycle..point slow pointer to NULL
 */
void removecycle(node *&head){
    node *slow=head;
    node *fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

//Reversing k nodes in a linked list using iteration and recursion
node *kreverse(node *&head,int k){
    //We reverse the first k nodes using iteration and then the rest of the linked list is processed using recursion
    //head->next= returned->next, reverse head and previous
    node *prevptr=NULL;
    node *currptr=head;
    node *nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
    head->next=kreverse(nextptr,k);//Local variables of prevptr are created 
    }
    return prevptr;//This return statement returns the prevptr of the initial k nodes
}

//Reversing a linked list: Iterative
node* reverse(node *&head){
    node *previous=NULL; //Declaration and intialization of three pointers
    node *current=head;
    node *nxt;
    while(current!=NULL){
        nxt=current->next;//Assignment of values
        current->next=previous;

        previous=current;
        current=nxt;//Move the pointers
    }
    return previous;
}
//Reversing a linked list: Recursive
node* reverseRecursive(node *&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newhead;
}

// Deletion of a particular node can be done by position/value:
void Delete(Node *&head, int position)
{

    if (position == 1)
    {
        Node *temp = head;
        head = head->nxt;

        temp->nxt = NULL;
        delete temp;
    }

    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->nxt;
            cnt++;
        }

        prev->nxt = curr->nxt;
        curr->nxt = NULL;

        delete curr;
    }
}

//deletion in a linked list
void deletion(node *&head,int val){
    if(head==NULL) return;
    if(head->next==NULL){
        //deletion at head a seperate function can be written 
    }
    if (head->data == val) {
        // Special case: deletion of the head node
        node *todelete = head;
        head = head->next;
        delete todelete;
        return;
    }

    node *temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
//Insertion at tail
void insertattail(node *&head,int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
        return ;
    }
    node *temp=head;
    while(temp->next!=NULL){
    
        temp=temp->next;
    }
    temp->next=n;
}

void display(node *head){
    
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node *head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    insertattail(head,7);

    makecycle(head,3);
    cout<<detectcycle(head)<<endl;
    removecycle(head);
    cout<<detectcycle(head)<<endl;


    display(head);
    /*int k=2;
    node *newhead=kreverse(head,k);
    display(newhead);
    */

    //node* newhead= reverse(head);
    //node *newRhead=reverseRecursive(head);
    //display(newhead);
    //display(newRhead);
    return 0;
}
