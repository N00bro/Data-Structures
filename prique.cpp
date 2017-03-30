#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data,pri;
    struct node* next;
}*p;
node* start=NULL;
int main()
{
    int n,ch;


    char c;
    do{
            cout<<"1.INSERT\n2.DELETE\n3.SHOW"<<endl;
            cout<<"Enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {

case 1:
    cout<<"Enter the number of elements in queue"<<endl;
    cin>>n;
     node* newnode;
    for(int i=0;i<n;i++)
    {
        newnode=new node;
        cout<<"Enter the data"<<endl;
        cin>>newnode->data;
        cout<<"Enter the priority"<<endl;
        cin>>newnode->pri;
        if(start==NULL||newnode->pri<start->pri)
        {
            newnode->next=start;
            start=newnode;
        }
        else
        {
            p=start;
            while(p->next!=NULL && (p->next->pri)<=(newnode->pri))
                p=p->next;
            newnode->next=p->next;
            p->next=newnode;
        }

    }
    break;
case 2:
    struct node*ptr;
if(start==NULL)
{
    cout<<"Underflow";
}
else
{
    ptr=start;
    cout<<"Element deleted"<<endl;
    start=start->next;
    free(ptr);
    n--;
}
break;
case 3:
            struct node* t;
            t=start;
    for(int i=0;i<n;i++)
            {
            cout<<t->data<<"-";
            cout<<t->pri<<"-->";
            t=t->next;
            }
            break;
    return 0;
}
cout<<"Enter y to continue"<<endl;
cin>>c;
}while(c=='Y'||c=='y');
}
