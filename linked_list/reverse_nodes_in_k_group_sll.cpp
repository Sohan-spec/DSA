#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int v)
    {
        data = v;
        next = NULL;
    }
    Node(int v, Node *n)
    {
        data = v;
        next = n;
    }
};
Node*findkthnode(Node*head,int k){
    int count=1;
    Node*temp=head;
    while(temp!=NULL && count<k){
        temp=temp->next;
        count++;
    }
    if(count==k)return temp;
    return NULL;
}
Node*reverse_ll(Node*head){
    Node*temp=head;
    Node*prev=NULL;
    while(temp!=NULL){
        Node*nextnode=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextnode;
    }
    return prev;
}
Node*optimal_soln(Node*head,int k){
    if(head==NULL){
        return NULL;
    }
    Node*temp=head;
    Node*prev=NULL;
    while(temp!=NULL){
        Node*kthnode=findkthnode(temp,k);
        if(kthnode==NULL){
            if(prev)prev->next=temp;
            break;
        }
        Node*nextnode=kthnode->next;
        kthnode->next=NULL;
        Node*newhead=reverse_ll(temp);
        if(temp==head){
            head=newhead;
        }
        else{
            prev->next=newhead;
        }
        prev=temp;
        temp=nextnode;
    }
    return head;
}
