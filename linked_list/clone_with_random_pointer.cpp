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
struct ListNode{
    int data;
    ListNode*next;
    ListNode*random;
    ListNode(int val){
        data=val;
        next=NULL;
        random=NULL;
    }
};
Node*deep_copy_of_ll(Node*head){ // i did this just for testing
    if(head==NULL){
        return NULL;
    }
    Node*res=new Node(head->data,NULL);
    Node*currnew=res;
    Node*temp=head->next;
    while(temp!=NULL){
        currnew->next=new Node(temp->data,NULL);
        currnew=currnew->next;
        temp=temp->next;
    }
    return res;
}
ListNode*brute_force(ListNode*head){
    if(head==NULL){
        return NULL;
    }
    ListNode*temp=head;
    unordered_map<ListNode*,ListNode*>mpp;
    while(temp!=NULL){
        ListNode*newnode=new ListNode(temp->data);
        mpp[temp]=newnode;
        temp=temp->next;    
    }
    temp=head;
    while(temp!=NULL){
        ListNode*copynode=mpp[temp];
        copynode->next=mpp[temp->next];
        copynode->random=mpp[temp->random];
        temp=temp->next;
    }
    return mpp[head];
}
ListNode*optimal_soln(ListNode*head){
    if(head==NULL){
        return NULL;
    }
    ListNode*temp=head;
    while(temp!=NULL){ //this part is adding the dummy nodes in b/w 2 nodes
        ListNode*newnode=new ListNode(temp->data);
        newnode->next=temp->next;
        temp->next=newnode;
        temp=temp->next->next;
    }
    temp=head;
    while(temp!=NULL){ //this is to connect the random of the dummy nodes to the random of the actual nodes
        temp->next->random=temp->random?temp->random->next:NULL;
        temp=temp->next->next;
    }
    temp=head;
    ListNode*res=new ListNode(-1);
    ListNode*newhead=res;
    while(temp!=NULL){
        res->next=temp->next;
        res=res->next;
        temp->next=temp->next->next;
        temp=temp->next;
    }
    return newhead->next;
}