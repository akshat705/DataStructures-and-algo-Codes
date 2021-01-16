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
void printList(ListNode*head)
{
	ListNode*p = head;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
/********************************************/
// REMOVE DUPLICATES FROM SORTED LIST 2
ListNode* removeDuplicatesFromSortedList2(ListNode*head)
{
	if (head == NULL || head->next == NULL)return head;
	ListNode*p = head, *r = head->next, *newHead = NULL, *last = NULL;
	int num = -1;
	while (r)
	{
		if (p->val != q->val && p->val != num)
		{
			if (newHead == NULL)
			{
				newHead = p;
				last = p;
				last->next = NULL;
				num = last->val;
			}
			else
			{
				last->next = p;
				last = p;
				last->next = NULL;
				num = last->val;
			}
		}
		else num = p->val;
		p = r;
		r = r->next;
	}
	if (p->val != num)
	{
		last->next = p;
		last = p;
		last->next = NULL;
	}
	return newHead;

}

/********************************************/
// REMOVE DUPLICATES FROM SORTED LIST
ListNode* removeDuplicatesFromSortedList(ListNode*head)
{
	if (head == NULL || head->next == NULL)return head;
	ListNode*p = head, *q = head->next, newHead = NULL, last = NULL;
	while (q)
	{
		if (newHead == NULL)
		{
			newHead = p;
			last = p;
			last->next = NULL;
		}
		else if (last->val != p->val)
		{
			last->next = p;
			last = p;
			last->next = NULL;
		}
		p = r;
		r = r->next;
	}
	return newHead;
}

/*****************************************/
//PALINDROME LIST
int palindromeList(ListNode*head)
{
	int n = lengthLL(head);
	if (n == 0 || n == 1)return 1;
	ListNode*q = NULL, *p = head, *r = head->next;
	for (int i = 0; i < n / 2; i++)
	{
		p->next = q;
		q = p;
		p = r;
		r = r->next;
	}
	if (n % 2)p = p->next;
	while (p)
	{
		if (p->val != q->val)return 0;
	}
	return 1;
}



/*****************************************/
//SORT BINARY LINKED LIST
ListNode* sortBinaryList(ListNode* head) {
	ListNode *p = head;
	int z = 0, o = 0;
	while (p != NULL)
	{
		if (p->data == 0)z++;
		else o++;
		p = p->next;
	}
	p = head;
	while (p != NULL)
	{
		if (z) {p->data = 0; z--;}
		else p->data = 1;
		p = p->next;
	}
	return head;

}


/******************************************/
// PARTITION LIST
ListNode* partitionList(ListNode* head, int x) {
	ListNode *head1 = NULL, *head2 = NULL, *last1 = NULL, *last2 = NULL, *p = head;
	if (head == NULL)return NULL;
	while (p)
	{
		if (p->val < x)
		{
			if (head1)
			{
				last1->next = p;
				last1 = p;
				p = p->next;
				last1->next = NULL;
			}
			else {head1 = p; last1 = p; p = p->next; last1->next = NULL;}
		}
		else if (p->val >= x)
		{
			if (head2)
			{
				last2->next = p;
				last2 = p;
				p = p->next;
				last2->next = NULL;
			}
			else {head2 = p; last2 = p; p = p->next; last2->next = NULL;}
		}

	}
	last1->next = head2;
	return head1;
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