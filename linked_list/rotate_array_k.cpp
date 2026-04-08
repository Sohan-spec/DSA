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
Node*rotate_ll(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*actualhead=head;
    Node*temp=head;
    Node*prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    temp->next=actualhead;
    return temp;
}
Node *brute_force(Node *head, int k)
{
    if (head == NULL || head->next==NULL ||k==0)
    {
        return head ;
    }
    Node*temp=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    k=k%count;
    for(int i=0;i<k;i++){
    head=rotate_ll(head);
    }
    return head;
}
Node*optimal_soln(Node*head,int k){
    if(head==NULL ||head->next==NULL || k==0){
        return head;
    }
    Node*temp=head;
    int count=1;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    temp->next=head;
    k=k%count;
    int steps=count-k;
    Node*newtail=temp;
    while(steps--){
        newtail=newtail->next;
    }
    Node*newhead=newtail->next;
    newtail->next=NULL;
    return newhead;
}