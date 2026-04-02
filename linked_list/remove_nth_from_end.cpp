#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int v){
        data=v;
        next=NULL;
    }
    Node(int v,Node* n){
        data=v;
        next=n;
    }
};
Node *self_soln(Node*head,int n){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        if(n==1){
            delete(head);
            return NULL;
        }
        else{
            cout<<"The list doesn't have the elements";
            return head;
        }
    }
    int size=0;
    Node*temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    if(n>size){
        cout<<"Not in list bounds";
        return head;
    }
    int pos=size-n+1;
     if(pos==1){
        temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    int count=0;
    temp=head;
    Node*prev=NULL;
    while(temp!=NULL){
        count++;
        if(count==pos){
            prev->next=temp->next;
            delete(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* optimal_soln(Node*head,int n){
    Node*fast=head;
    Node*slow=head;
    for(int i=0;i<n;i++){
        if(fast==NULL)return head;
        fast=fast->next;
    }
    if(fast==NULL){
        Node*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node*temp=slow->next;
    slow->next=slow->next->next;
    delete temp;
    return head;
}