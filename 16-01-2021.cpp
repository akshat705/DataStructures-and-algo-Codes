#include<bits/stdc++.h>
using namespace std;
/************************************/
//HELPER FUNCTIONS
void input(vector<int>&v, int n)
{
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}
}
int lengthLL(ListNode*head)
{
	ListNode*p = head;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}
ListNode* reverse(ListNode*head,int k)
{
	if(k==1||k==0)return head;
	ListNode*s=head,*q=NULL,*p=head,*r=head->next;
	while(k>1)
	{
		p->next=q;
		q=p;
		p=r;
		r=r->next;
		k--;
	}
	p->next=q;
	return p;

}
/****************************************/
//K REVERSED LINKEDLIST
ListNode* kReversedList(ListNode*head,int k)
{
	int n=lengthLL(head);
	ListNode*head1=head,*head2=head,*newHead=NULL;
	for(int i=0;i<k;i++)
	{
		head2=head2->next;
	}
	newHead=reverse(head1,k);
	n=n/k;
	n--;
	while(n--)
	{
		ListNode*temp=head2;
		for(int i=0;i<k;i++)
		{
			temp=temp->next;
		}
		head1->next=reverse(head2,k);
		head1=head2;
		head2=temp;
	}
return newHead;
}

/***********************************/
ListNode* reverseEvenPositions(ListNode*head)
{
	int n=lengthLL(head);
	ListNode*oddh=NULL,*oddt=NULL,*evenh=NULL,*event=NULL,*p=head;
	oddh=p;oddt=p;p=p->next;
	evenh=p;event=p;p=p->next;
	int e=1;
	for(int i=3;i<=n;i++)
	{
		if(i%2)
		{
			oddt->next=p;
			oddt=p;
			p=p->next;
			oddt->next=NULL;
		}
		else if(i%2==0)
		{
			event->next=p;
			event=p;
			p=p->next;
			event->next=NULL;
			e++;
		}
	}
	evenh=reverse(evenh,e);
	head=p;p=oddh;oddh=oddh->next;
	for(int i=2;i<=n;i++)
	{
		if(i%2)
		{
			p->next=oddh;
			p=oddh;
			oddh=oddh->next;
			p->next=NULL;
		}
		else if(i%2==0)
		{
			p->next=evenh;
			p=evenh;
			evenh=evenh->next;
			p->next=NULL;
		}
	}
	return head;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int A, B, C;
	cin >> A;
	vector<int>a, b, c;
	input(a, A);
	sortByColor(a);
	for (auto x : a)cout << x << " ";
	return 0;

}