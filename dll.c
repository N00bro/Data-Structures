#include<iostream>
using namespace std;
#include<conio.h>
#include<process.h>
struct node
{
int info;
node *llink,*rlink;
}*np,*p,*rlink,*t;
struct head
{
int c;
node *st;
}f;
node *create(int data)
{
np=new node;
np->info=data;
return np;
}
void main()
{
f.c=0;
f.st=NULL;
int pos,d,ch;
char x;
do
	{
	clrscr();
	cout<<"1.insert\n2.delete\n3.search\n4.display\n\nEnter your choice\n";
	cin>>ch;
	switch(ch)
		{
		case 1:
		cout<<"enter info\n";
		cin>>d;
		cout<<"enter position\n";
		cin>>pos;
		p=create(d);
		if(pos==1)
			{
			p->llink=NULL;
			p->rlink=f.st;
			f.st=p;
			f.c++;
			}
		else
			{
			int i=1;
			t=f.st;
			while(i<pos-1)
				{
				t=t->rlink;
				i++;
				}
			p->llink=t;
			p->rlink=t->rlink;
			t->rlink->llink=p;
			t->rlink=p;
			f.c++;
			}
		break;
		case 2:
		int n,i=1,pos;
		cout<<"\nenter no. to be deleted\n";
		cin>>n;
		t=f.st;
		if(t->info==n)
			{
			f.st=t->rlink;
			f.c--;
			}
		else
			{
			while((i<=f.c)&&(t->info!=n))
				{
				t=t->rlink;
				i++;
				}
			if(t->info==n)
				{
				pos=i;
				p=t;
				}
			else
				{
				cout<<"\ninfo no found";
				break;
				}
			i=1;
			t=f.st;
			while(i<pos-1)
				{
				t=t->rlink;
				i++;
				}
			np=t;
			t->rlink=p->rlink;
			t->llink=np;
			f.c--;
			}
		getch();
		break;
		case 3:
		i=1;
		int fd=0;
		cout<<"\nenter no. to be searched\n";
		cin>>n;
		t=f.st;
		while(i<=f.c)
			{
			if(t->info==n)
				{
				cout<<"\nNo. found at position "<<i;
				fd=1;
				}
			i++;
			t=t->rlink;
			}
		if(fd==0)
		cout<<"\no.not found";
		break;
		case 4:
		t=f.st;
		i=1;
		while(i<=f.c)
			{
			cout<<t->info<<"<->";
			t=t->rlink;
			i++;
			}
		break;
		default:
		cout<<"\nWrong option";
		}
	cout<<"\n\ny to continue\n";
	cin>>x;
	}while(x=='y'||x=='Y');
getch();
}
