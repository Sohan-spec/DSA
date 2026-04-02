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
    temp->data=vt[i];~
    temp=temp->next;
   }
    return head;
}
