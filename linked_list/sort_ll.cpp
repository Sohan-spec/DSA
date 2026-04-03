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
    if(head->next==NULL){
        return head;
    }
    vector<int>vt;
    Node*temp=head;
    while(temp!=NULL){
        vt.emplace_back(temp->data);
        temp=temp->next;
    }
    sort(vt.begin(),vt.end());
    temp=head;
   for(int i=0;i<vt.size();i++){
    temp->data=vt[i];
    temp=temp->next;
   }
    return head;
} 
Node*findmiddle(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*fast=head->next; // cos we want the middle to stop at the first middle in even cases and not the second even
    Node*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node*merge2(Node*lefthead,Node*righthead){
    Node*dummynode=new Node(-1);
    Node*temp=dummynode;
    while(lefthead!=NULL && righthead!=NULL){
        if(lefthead->data < righthead->data){
            temp->next=lefthead;
            temp=lefthead;
            lefthead=lefthead->next;
        }
        else{
            temp->next=righthead;
            temp=righthead;
            righthead=righthead->next;
        }
    }
    if(lefthead)temp->next=lefthead;
    else temp->next=righthead;

    return dummynode->next;
}
Node* mergesort(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*middle=findmiddle(head);
    Node* lefthead=head;
    Node*righthead=middle->next;
    middle->next=NULL;
    lefthead=mergesort(lefthead);
    righthead=mergesort(righthead);
    return merge2(lefthead,righthead);
}
