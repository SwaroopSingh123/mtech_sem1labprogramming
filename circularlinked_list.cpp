#include<iostream>
#include<stdio.h>
using namespace std;
int nodes=0;
template <class T>
class node{
  public:
  T val;
  node<T> *next;
};

//creating a class linkedlist
template <class T>
class Linked_list{
public:
node<T> *p=NULL;
node<T> *q=NULL;
node<T> *head=NULL;

void insert(T insertval)
{
    node<T> *ptr=head;
    node<T> *newnode=new node<T>;
    newnode->val=insertval;
    newnode->next=NULL;
    int position=0;
    cout<<"at which position to insert starts from 1 ,,,starting from head\n";
    cin>>position;
    if(position==1){
        if(head==NULL){
            head=newnode;
            newnode->next=head;
        }
        else{
            newnode->next=head;
            p=head;
            while(p->next!=head)p=p->next;
            p->next=newnode;
            head=newnode;
            }
        nodes++;
    }
    else{
        if (position==nodes+1){
        while(ptr->next!=head)ptr=ptr->next;
        ptr->next=newnode;
        newnode->next=head;
        nodes++;
        }
        else if(position>nodes+1)cout<<"invalid demand of position";
        else{
            while(ptr->next!=head && position!=1){
                p=ptr;
                ptr=ptr->next;
                position--;
            }
            p->next=newnode;
            newnode->next=ptr;
            nodes++;
        }
    }
}
void delete_(){
    int position=0;
    q=head;
    cout<<"which position to delete";
    cin>>position;
    if(position>nodes)cout<<"invalid";
    else{
        if(position==1){
            if(head->next==head)head=NULL;
            else{
                p=head;
                while(p->next!=head)p=p->next;
                q=head;
                head=head->next;
                free(q);
                p->next=head;
            }
        }
        else{
            while(position!=1 && q->next!=head)
            {
                p=q;
                q=q->next;
            }
            if(q->next==head){
                p->next=head;
                free(q);
            }
            else{
                p->next=q->next;
                free(q);
            }
        }
    }
}
void search(T searchval){
int reveal=0;
    if(head==NULL)cout<<"not presemt in L.L";
    else{
        q=head;
        while(q->next!=head){
            if(q->val==searchval)
            {
                reveal=1;
                cout<<"yes it is present";
                break;
            }
            else{
            q=q->next;
            }
        }
        if(q->val==searchval && reveal!=1)
           {
                reveal=1;
                cout<<"yes it is present";
            }
        if(reveal==0)cout<<"not present in L.L";
    }
}
void show(){
    node<T> *trace=head;
    if(trace==NULL)cout<<"empty";
    else{
    while(trace->next!=head)
    {
        cout<<trace->val<<" ";
        trace=trace->next;
    }
    cout<<trace->val;
    }
}
};
int main(){
    int  result=0,ans=0;
    int value=0;
    Linked_list<int> myname;
    while(true)
    {
    cout<<"which operation u want to perform :\n"<<"1.insert\n"<<"2.search\n"<<"3.delete\n"<<"4.show LinkedList\n";
    cin>>result;
    switch(result){
        case 1:
          cout<<"the val u want to insert in single L.L";
          cin>>value;
          myname.insert(value);
          break;
        case 2:
          cout<<"enter the value u wnat to search";
          cin>>value;
          myname.search(value);
          break;
        case 3:
           myname.delete_();
           cout<<"\n";
        case 4:
           myname.show();
           break;
        default:
           ans=1;
    }
    cout<<"\n";
    if(ans==1)break;
    }
    return 1;
}