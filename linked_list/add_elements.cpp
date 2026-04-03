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
Node*optimal_soln(Node*list1,Node*list2){
    Node*dummy=new Node(-1);
    Node*temp=dummy;
    int carry=0;
    while(list1!=NULL || list2!=NULL || carry){
        int sum=0;
        if(list1!=NULL){
            sum+=list1->data;
            list1=list1->next;
        }
        if(list2!=NULL){
            sum+=list2->data;
            list2=list2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node*newnode=new Node(sum%10);
        temp->next=newnode;
        temp=temp->next;
    }
    return dummy->next;
}