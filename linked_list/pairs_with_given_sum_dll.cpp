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
vector<vector<int>>brute_force(Node*head,int sum){
    if(head==NULL){
        return {};
    }
    Node*temp=head;
    vector<int>arr;
    while(temp!=NULL){
        arr.emplace_back(temp->data);
        temp=temp->next;
    }
    set<pair<int,int>>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==sum){
                int a=arr[i];
                int b=arr[j];
                ans.insert({min(a,b),max(a,b)});
            }
        }
    }
    vector<vector<int>>final_ans;
    for(auto i:ans){
        final_ans.push_back({i.first,i.second});
    }
    return final_ans;
}
vector<vector<int>>optimal_soln(Node*head,int sum){
    vector<vector<int>>ans;
    if(head==NULL){
        return ans;
    }
    Node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node*left=head;
    Node*right=tail;
    while(left!=NULL && right!=NULL && left!=right && right->next!=left){
        int currsum=left->data+right->data;
        if(currsum==sum){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;
        }
        else if(currsum>sum){
            right=right->prev;
        }
        else{
            left=left->next;
        }
    }
    return ans;
}
