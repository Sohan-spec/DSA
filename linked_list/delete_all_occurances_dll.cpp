#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node*prev;

    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
    Node(int val,Node*n,Node*p){
        data=val;
        next=n;
        prev=p;
    }
};
Node*optimal_soln(Node*head,int key){
    if(head==NULL){
        return NULL;    
    }
    while(head!=NULL && head->data==key){
        Node*temp=head;
        head=head->next;
        if(head!=NULL)head->prev=NULL;
        delete temp;
    }
    Node*temp=head;
    while(temp!=NULL){
        Node*nextnode=temp->next;
        if(temp->data==key){
            if(temp->prev!=NULL){
                temp->prev->next=temp->next;
            }
            if(temp->next!=NULL){
                temp->next->prev=temp->prev;
            }
            delete temp;
            temp=nextnode;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}