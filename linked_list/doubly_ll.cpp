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
Node* array_to_ll(vector<int>&arr){
    if(arr.empty())return NULL;
    Node*head=NULL;
    head=new Node(arr[0]);
    Node *prev=head;
    for(int i=1;i<arr.size();i++){
        Node *newNode=new Node(arr[i],NULL,prev);
        prev->next=newNode;
        prev=newNode;
    }
    return head;
}
Node *deletehead(Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    Node*temp=head;
    head=temp->next;
    head->prev=NULL;
    delete(temp);
    return head;
}
Node*deletetail(Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    delete(temp);
    return head;
}
Node *deletekelem(Node*head,int k){
    if(head==NULL){
        return NULL;
    }
    if(k<=0){
        return head;
    }
    if(k==1){
        return deletehead(head);
    }
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        count++;
        if(count==k){
            temp->prev->next=temp->next;
            if(temp->next!=NULL){
            temp->next->prev=temp->prev;
            }
            delete(temp);
            return head;
        }
        temp=temp->next;
    }
    return head;
}
void deletenode(Node *node){ //in this case like the node won't be equal to head, so we needn't worry about prev being null but it can be the last node though
    Node *front=node->next;
    Node* back=node->prev;
    if(front==NULL){
        back->next=nullptr;
        delete(node);
        return;
    }
    back->next=front;
    front->prev=back;
    delete(node);
}
Node *inserthead(Node*head,int val){
    Node* newNode=new Node(val,head,nullptr);
    if(head!=NULL){
        head->prev=newNode;
    }
    return newNode;
}
Node*inserttail(Node *head,int val){
    if(head==NULL){
        return inserthead(head,val);
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node*newNode=new Node(val,NULL,temp);
    temp->next=newNode;
    return head;
}
Node *insertatpos(Node*head,int pos,int val){
    if(head==NULL){
        if(pos==1){
          return new Node(val,nullptr,nullptr);  
        }
        return NULL;
    }
    if(pos==1){
        return inserthead(head,val);
    }
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        count++;
        if(count==pos-1){
            Node *newNode=new Node(val,temp->next,temp);
            if(temp->next!=NULL){
            temp->next->prev=newNode;
            }
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
void printreversedll(Node *head){
    if(head==NULL){
        cout<<"list is empty";
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}
void brute_reverse_dll(Node*head){
    if(head==NULL){
        return;
    }
    stack<int>st;
    Node*temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node * optimal_reverse_dll(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*current=head;
    Node*last=NULL;
    while(current!=NULL){
        last=current->prev;
        current->prev=current->next;
        current->next=last;
        current=current->prev;
    }
    if(last!=NULL){
        head=last->prev;
    }
    return head;
}
int main()
{
    vector<int>arr={1,3,2,4};
    Node*head=NULL;
    head=array_to_ll(arr);
    head=optimal_reverse_dll(head);
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}