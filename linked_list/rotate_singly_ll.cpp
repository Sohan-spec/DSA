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
Node* reverse_ll(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*temp=head;
    Node*prev=NULL;
    while(temp!=NULL){
        Node *front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}