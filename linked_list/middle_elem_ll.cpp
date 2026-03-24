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
Node* brute_force(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int middle=(count/2)+1;
    temp=head;
    count=0;
    while(temp!=NULL){
        count++;
        if(count==middle){
            return temp;
        }
        temp=temp->next;
    }
    return head;
}
Node* tortoise_and_hare_algo(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*fast=head;
    Node*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main()
{
    //too lazy to fill the main func
}