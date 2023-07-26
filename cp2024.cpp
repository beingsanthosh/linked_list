//linked list:it is a non contigious block of memory that are connected by the pointers
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// 	int a=10;
// 	int *ptr=&a;
// 	int **ptr1=&ptr;
// 	cout<<ptr<<" ";
// 	cout<<*ptr<<" ";
// 	cout<<ptr1<<" ";
// 	cout<<*ptr1<<" ";
// }
//structure is a userdefined datatype.it can be constructed by using struct key word
//struct<struct_name>
//{
//	
//}//we can access using dot operator
// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
// 	int data;
// 	Node* next;
// 	Node(int d)
// 	{
// 		data=d;
// 		next=NULL;
// 	}
// };
// //.(operator) is used to acces the methods of an object
// //->(operator) is used to acces the data of object through pointer
// int main()
// {
// 	Node *head=new Node(20);
// 	head->next=new Node(30);
// 	head->next->next=new Node(40);
// 	while(head!=NULL)
// 	{
// 		cout<<head->data;
// 		head=head->next;
// 	}
// }
#include<bits/stdc++.h>
using namespace std;
struct Node{
		int data;
		Node* next;
		Node(int d)
		{
			data=d;
			next=NULL;
		}
};
class Linkedlist{
	Node* head;
	Node* tail;
public:
	Linkedlist()
	{
		head=NULL;
		tail=NULL;
	}
	void insertatend(int data)
	{
		Node *newnode=new Node(data);
		if(head==NULL)
		{
			head=newnode;
			tail=head;
		}
		 else
		{
			tail->next=newnode;
			tail=tail->next;
		// 	Node *current=head;
		// 	while(current->next!=NULL)
		// 	{
		// 		current=current->next;
		// 	}
		// 	current->next=newnode;
		 }
	}
	void insertatbegin(int data)
	{
		Node *newnode=new Node(data);
		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			newnode->next=head;
			head=newnode;
		}
	}
	void deletedata(int dat)
	{
		Node *current=head;
		if(head==NULL)
		{
			cout<<"list is empty";
		}
		else if(head->data==dat)
		{
			head=head->next;
			free(current);
		}
		else
		{
			while(current->next!=NULL and current->next->data!=dat)
			{
				current=current->next;
			}
			if(current->next==NULL)
			{
				cout<<"data would not been found";
			}
			else
			{
				Node *temp=current->next;
				current->next=current->next->next;
				free(temp);
			}
		}	
	}
	void insertatK(int val,int k)
	{
		Node *newnode=new Node(val);
		if(head==NULL)
		{
			cout<<"list is empty";
		}
		if(k==0)
		{
			newnode->next=head;
			head=newnode;
		}
		else
		{
			Node *current=head;
			while(current!=NULL and --k)
			{
				current=current->next;
			}
			if(k==0)
			{
				newnode->next=current->next;
				current->next=newnode;
			}
			else
			{
				cout<<"position doesnot exist";
			}
		}
	}
	void reverseiterative()
	{
		Node *prev=NULL;
		Node *current=head;
		Node *nex=NULL;
		while(current!=NULL)
		{
			nex=current->next;
			current->next=prev;
			prev=current;
			current=nex;
		}
		head=prev;
	}
	Node *reversal(Node *previous,Node *current)
	{
		if(current!=NULL)
		{
			Node *head=reversal(current,current->next);
			current->next=previous;
			return head;
		}
		else
		{
			return previous;
		}
	}
	void reversalrecusive()
	{
		head=reversal(NULL,head);
	}
	Node *findkthele(int k)
	{
			Node *slow=head,*fast=head;
			while(fast!=NULL and --k)
			{
				fast=fast->next;
			}
			if(fast!=NULL)
			{
				while(fast!=NULL)
				{
					fast=fast->next;
					slow=slow->next;
				}
				return slow;
			}
			else
			{
				cout<<"doesnot exist";
			}
	}
	Node *findmid()
	{
		Node *slow=head,*fast=head;
		while(fast!=NULL and fast->next!=NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		}
		return slow;
	}
	void display()
	{
		if(head==NULL)
		{
			cout<<"list is empty";
		}
		else
		{
			Node* current=head;
			while(current!=NULL)
			{
				cout<<current->data<<"->";
				current=current->next;
			}
		}
		cout<<"NULL";
	}


};
int main()
{
	Linkedlist l1=Linkedlist();
	l1.insertatend(10);
	l1.insertatend(20);
	l1.insertatend(30);
	l1.insertatbegin(40);
	l1.insertatbegin(50);
	l1.insertatbegin(60);
	l1.deletedata(60);
	l1.deletedata(40);
	l1.deletedata(30);
	l1.insertatK(80,2);
	l1.reverseiterative();
	Node* mid=l1.findmid();
	cout<<(mid->data);
	Node *kth=l1.findkthele(3);
	cout<<(kth->data);
	l1.display();

}