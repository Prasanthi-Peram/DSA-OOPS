#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* previous;
    node *next;

    node(int a){
        data=a;
        previous=NULL;
        next=NULL;
    }
};
int length(node *head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
node *mergeRecursive(node *&head1, node *&head2){
    
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    node *result;
    if (head1->data < head2->data) {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}
//Merging two sorted linked lists
node *merge(node *&head1,node *&head2){
    node *p1=head1;
    node *p2=head2;
    node *dummyNode=new node(-1);
    node *p3=dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }

    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
}
//Code to create an intersection
void intersect(node *&head1,node *&head2,int pos){
    node *temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node *temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
//Find intersection point of 2linked lists. Time complexity code1==O(m+n)
//Find length of both
int intersection(node *&head1 ,node *&head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    node *ptr1;
    node *ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL) return -1;
        d--;
    }
    while(ptr1!=NULL&& ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
//Append last k nodes to start of linked list
node *append(node *&head,int k){
    //node *newTail=l-kth position
    //node *newHead=l-k+1th position
    //Point tail to head and new tail to null
    node *newHead;
    node *newTail;
    node *tail=head;
    int l=length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
            newTail=tail;
        }
        if(count==l-k+1){
            newHead=tail;   
        }
        tail=tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}
void Delete(node *&head,int pos){
    node *temp=head;
    int count=1;

    if(pos==1){
        node *todelete=head;
        head=head->next;
        head->previous=NULL;
        delete todelete;
    }

    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->previous->next=temp->next;
    temp->next->previous=temp->previous;

    delete temp;
}

void insertAthead(node *&head, int val){
    node *n= new node(val);
    n->next=head;
    if(head!=NULL){
        head->previous=n;
    }
   head=n;
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
    n->previous=temp;
    n->next=NULL;
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
    node *head1=NULL;
    node *head2=NULL;
    int arr1[]={1,4,5,7};
    int arr2[]={2,3,6};

    for(int i=0;i<4;i++){
        insertAttail(head1,arr1[i]);
    }
    for(int i=0;i<3;i++){
        insertAttail(head2,arr2[i]);
    }

    //intersect(head1,head2,3);

    //cout<<intersection(head1,head2)<<endl;
    /*Delete(head,6);
    display(head); 
    Delete(head,1);*/
    display(head1);
    display(head2);
    //node *newnode1=merge(head1,head2);
    node *newnode2 =mergeRecursive(head1,head2);
    //display(newnode1);
    display(newnode2);
    return 0;
}

//Doubly linked list. It can be used to tranverse in both directions
