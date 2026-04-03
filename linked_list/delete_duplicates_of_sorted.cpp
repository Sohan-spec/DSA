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
Node*brute_force(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*temp=head;
    Node*prev=NULL; //this ain't risky cos the first element can never be a duplicate
    unordered_set<int>stt;
    while(temp!=NULL){
        if(stt.find(temp->data)!=stt.end()){
            prev->next=temp->next;
            Node*deletenode=temp;
            temp=temp->next;
            delete deletenode;
        }
        else{
            stt.insert(temp->data);
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
Node*optimal_soln(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            Node*deletenode=temp->next;
            temp->next=temp->next->next;
            delete deletenode;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}