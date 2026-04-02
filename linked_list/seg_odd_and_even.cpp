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
    if(head==NULL){
        return NULL;
    }
    vector<int>arr;
    Node*temp=head;
    while(temp!=NULL && temp->next!=NULL){
        arr.emplace_back(temp->data);
        temp=temp->next->next;
    }
    if(temp){
        arr.emplace_back(temp->data);
    }
    temp=head->next;
    while(temp!=NULL && temp->next!=NULL){
        arr.emplace_back(temp->data);
        temp=temp->next->next;
    }
    if(temp){
        arr.emplace_back(temp->data);
    }
    temp=head;
    for(int i=0;i<arr.size();i++){
        temp->data=arr[i];
        temp=temp->next;
    }
    return head;
}
Node*optimal_soln(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*odd=head;
    Node*even=head->next;
    Node*evenhead=head->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}