#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node*next;
    Node(int val){
        data=val;
        next=nullptr;
    }
    Node(int val,Node*link){
        data=val;
        next=link;
    }
};
Node* insertbeginning(Node * head,int val){
    if(head == NULL){
        return new Node(val,nullptr);
    }
    Node *newNode=new Node(val,head);
    return newNode;
}
Node* insertending(Node *head,int val){
    if(head==NULL){
        return new Node(val,nullptr);
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *newNode=new Node(val,nullptr);
    temp->next=newNode;
    return head;
}
Node *insertatpos(Node *head,int pos,int val){
    if(head==NULL){
        if(pos==1){
            return new Node(val,head);
        }
        else{
            cout<<"Can't enter at that position as list is empty";
            return NULL;
        }
    }
    if(pos==1){
        return new Node(val,head);
    }
    Node*temp=head;int count=0;
    while(temp!=NULL){
        count++;
        if(count==pos-1){
            Node *newNode=new Node(val,temp->next);
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
    }
    cout<<"Position out of bounds\n";
    return head;
}
Node *deletehead(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node *temp=head;
    head=head->next;
    delete(temp);
    return head;
}
Node *deletetail(Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    Node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;
    return head;
}
Node *deletepos(Node*head,int pos){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        if(pos==1){
            delete(head);
            return NULL;
        }
        else{
            return NULL;
        }
    }
    if(pos==1){
        Node*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node*temp=head,*prev=NULL;int count=0;
    while(temp!=NULL){
        count++;
        if(count==pos){
            prev->next=temp->next;
            delete(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int find_length(Node *head){
    if(head==NULL){
        return 0;
    }
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
int main(){
    Node *head=NULL;
    head=insertbeginning(head,10);
    head=insertending(head,20);
    head=insertatpos(head,3,30);
    cout<<find_length(head)<<endl;
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
