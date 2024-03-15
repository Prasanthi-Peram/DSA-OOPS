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

//Searching in a linked list;

void search(node *head,int e){
    node *temp=head;
    while(temp!=NULL){
        if(temp->data==e){
            cout<<"Found"<<endl;
            break;
            return;
        }
        temp=temp->next;
    }
    cout<<"Not found"<<endl;
}


//Deletion in a linked list
void deletion(node *&head, int val){  
}

int main(){
    node *head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    search(head,1);
    search(head,6);
    return 0;
}

