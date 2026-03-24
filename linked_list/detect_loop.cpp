#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int v){
        data=v;
    }
    Node(int v,Node* n){
        data=v;
        next=n;
    }
};
bool brute_force(Node*head){
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return false;
    }
    Node*temp=head;
    set<Node*>stt;
    while(temp!=NULL){
        if(stt.find(temp)!=stt.end()){
            return true;
        }
        stt.insert(temp);
        temp=temp->next;
    }
    return false;
}
bool optimal_soln(Node*head){
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return false;
    }
    Node*fast=head;
    Node*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
int main()
{
    //too lazy to write, write it yourself
}