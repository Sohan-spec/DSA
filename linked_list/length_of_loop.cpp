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
int cycle_length(Node*slow,Node*fast){
    int count=1;
    fast=fast->next;
    while(slow!=fast){
        count++;
        fast=fast->next;
    }
    return count;
}
int optimal_soln(Node* head){
    if(head==NULL){
        return 0;
    }
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return cycle_length(slow,fast);
        }
    }
    return 0;
}