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
//Circular linked list
//Put even elements after odd elements
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

void insertAthead(node *&head,int val){
    node *n=new node(val);
    node *temp=head;
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void insertAttail(node *&head,int val){
    if(head==NULL){
        insertAthead(head,val);
        return;
    }
    node *n=new node(val);
    node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void deleteAthead(node *&head){
    node *temp=head;
    
    while(temp->next!=head){
        temp=temp->next;
    }

    node *todelete=head;
    temp->next=head->next;
    head=head->next;

    delete todelete;
}
void deletion(node *&head,int pos){
    if(pos==1){
        deleteAthead(head);
        return;
    }
    node *temp=head;
    int count=1;
    
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }

    node *todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}

void display(node *head){
    node *temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

int main(){
    node *head=NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<4;i++) insertAttail(head,arr[i]);
    display(head);
    //deletion(head,3);
    evenAfterodd(head);
    display(head);

    return 0;
}