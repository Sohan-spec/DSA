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
Node* reverse_ll(Node*slow){
    Node*temp=slow;
    Node*prev=NULL;
    while(temp!=NULL){
        Node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
bool ispalindrome(Node*head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node*temp=head;
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*sec_head=reverse_ll(slow->next);
    Node*copy=sec_head;
    while(sec_head!=NULL){
        if(temp->data != sec_head->data){
            reverse_ll(copy);
            return false;
        }
        temp=temp->next;
        sec_head=sec_head->next;
    }
    reverse_ll(copy); // this is to not alter the given data
    return true;
}