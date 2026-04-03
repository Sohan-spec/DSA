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
Node*brute_force(Node*list1,Node*list2){
    if(list1==NULL || list2==NULL){
        return NULL;
    }
    unordered_set<Node*>stt;
    Node*temp=list1;
    Node*temp1=list2;
    while(temp!=NULL){
        stt.insert(temp);
        temp=temp->next;
    }
    while(temp1!=NULL){
        if(stt.find(temp1)!=stt.end()){
            return temp1;
        }
        temp1=temp1->next;
    }
    return NULL;
}
Node*optimal_soln(Node*list1,Node*list2){
    if(list1==NULL || list2==NULL){
        return NULL;
    }
    Node*p1=list1;
    Node*p2=list2;
    while(p1!=p2){
        p1=(p1==NULL)?list2:p1->next;
        p2=(p2==NULL)?list1:p2->next;
    }
    return p1;
}