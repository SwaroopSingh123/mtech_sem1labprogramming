#include<iostream>
#include<stdio.h>
using namespace std;
int nodes=0;
template <class T>
class node{
  public:
  T val;
  node<T> *next;
  node<T> *prev;
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
    newnode->prev=NULL;
    int position=0;
    cout<<"after which position to insert";
    cin>>position;
    if(position==1){
        if(head==NULL){
            head=newnode;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        nodes++;
    }
    else{
        if(position>nodes+1)cout<<"inivalid demand";
        else if(position==nodes+1){
            while(ptr->next!=NULL)ptr=ptr->next;
            ptr->next=newnode;
            newnode->prev=ptr;
            nodes++;
            }
        else{
            while(ptr->next!=NULL && position!=1){
                p=ptr;
                ptr=ptr->next;
                position--;
            }           
        p->next=newnode;
        newnode->prev=p;
        newnode->next=ptr;
        nodes++;
    }
    }
}
void deleteval(){
    int position=0;
    cout<<"which position to delete";
    cin>>position;
    if(position>nodes)cout<<"underflow";
    else{
        if(position==1){
            if(head->next==NULL)head=NULL;
            else{
                p=head;
                head=head->next;
                free(p);
            }
            nodes--;
        }
        else{
            p=q=head;
            while(p->next!=NULL && position!=1){
                q=p;
                p=p->next;
                position--;
            }
            if(p->next==NULL){
            q->next=NULL;
            free(p);
            }
            else{
                q->next=p->next;
                p->next->prev=q;
                free(p);
            }
            nodes--;
        }
        }
    }

void search(T searchval){
int reveal=0;
    if(head==NULL)cout<<"not presemt in L.L";
    else{
        q=head;
        while(q!=NULL){
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
        if(reveal==0)cout<<"not present in L.L";
    }
}
void show(){
     node<T> *trace=head;
    while(trace!=NULL)
    {
        cout<<trace->val<<" ";
        trace=trace->next;
    }
}
};
int main(){
    int  result=0,ans=0;
    int value=0;
    Linked_list<int> myname;
    while(true)
    {
    cout<<"which operation u want to perform \n"<<"1.insert\n"<<"3.delete\n"<<"2.search\n"<<"4.show L.L\n";
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
           myname.deleteval();
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