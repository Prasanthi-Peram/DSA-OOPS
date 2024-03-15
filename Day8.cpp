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
//Even positioned elements after odd-positioned elements
//Revise master's theorem

/*Stack: Stores a list of items in which an item can be added to or removed from the list only at one end
LIFO= last in first out mechanism*/

void insertAthead(node *&head, int val){
    node *n= new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    else{
        n->next=head;
        head=n;
    }
}

void insertAttail(node *&head,int val){

    if(head==NULL){
        insertAthead(head,val);
        return;
    }
    node *n=new node(val);
    node *temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
}

void display(node *&head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void evenAfterodd(node *&head){
    node *odd=head;
    node *even=head->next;
    node *evenStart=even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenStart;
    if(odd->next!=NULL){
        even->next=NULL;

    }
}


int main(){
    node *head=NULL;
    int arr[]={1,9,10,11,13,16};
    for(int i=0;i<4;i++) insertAttail(head,arr[i]);
    display(head);
    //deletion(head,3);
    evenAfterodd(head);
    display(head);

    return 0;
}