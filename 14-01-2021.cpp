#include<bits/stdc++.h>
using namespace std;
void sortByColor(vector<int>&v)
{
	int n = v.size();
	int l = 0, r = n - 1, i = 0;
	while (i <= r)
	{
		if (v[i] == 0)swap(v[i++], v[l++]);
		else if (v[i] == 2)swap(v[i], v[r--]);
		else i++;
	}
}
int rempveElementFromAnArray(vector<int>&v, int k)
{
	int n = v.size();
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] != k)v[j++] = v[i];
	}
	for (int i = j; i < n; i++)v.pop_back();
	return j;

}
int removeDuplicatesInPlace(vector<int>&v)
{
	int n = v.size();
	int j = 0, occ = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (v[i] == v[i + 1] && occ <= 2)
		{
			v[j++] = v[i];
			occ++;
		}
		else if (v[i] != v[i + 1] && occ > 2)occ = 1;
		else if (v[i] != v[i + 1] && occ <= 2)
		{
			v[j++] = v[i];
			occ = 1;
		}
	}
	if (occ <= 2)v[j++] = v[n - 1];
	int ans = j;
	for (int i = j; i < n; i++)v.pop_back();
	return ans;
}
void input(vector<int>&v, int n)
{
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}
}
void merge2SortedArrays(vector<int>&a, vector<int>&b)
{
	int A = a.size(), B = b.size();
	int i = 0, j = 0;
	vector<int>ans;
	while (i < A || j < B)
	{
		if (i == A)ans.push_back(b[j++]);
		else if (j == B)ans.push_back(a[i++]);
		else if (a[i] <= b[j])ans.push_back(a[i++]);
		else if (b[j] <= a[i])ans.push_back(b[j++]);
	}
	a = ans;

}
int containerContainingMostWater(vector<int>&v)
{
	int n = v.size();
	int s = 0, e = n - 1, water, maxWater = 0;
	while (s < e)
	{
		water = min(v[s], v[e]) * (e - s);
		maxWater = max(maxWater, water);
		if (v[e] < v[s])e--;
		else if (v[e] > v[s])s++;
		else {s++; e--;}
	}
	return maxWater;
}
int array3Pointers(vector<int>&a, vector<int>&b, vector<int>&c)
{
	int A = a.size(), B = b.size(), C = c.size();
	int ia = 0, ib = 0, ic = 0, ans = INT_MAX;
	while (ia < A || ib < B || ic < C)
	{
		int tempAns = max(abs(a[ia] - b[ib]), max(abs(b[ib] - c[ic]), abs(c[ic] - a[ia])));
		ans = min(ans, tempAns);
		if (ans == 0)break;


		if (abs(a[ia] - b[ib]) == tempAns)
		{
			if (a[ia] - b[ib] < 0) {if (ia < A - 1)ia++; else break;}
			else {if (ib < B - 1)ib++; else break;}
		}


		else if (abs(b[ib] - c[ic]) == tempAns)
		{
			if (b[ib] - c[ic] < 0) {if (ib < B - 1)ib++; else break;}
			else {if (ic < C - 1)ic++; else break;}
		}


		else if (abs(c[ic] - a[ia]) == tempAns)
		{
			if (c[ic] - a[ia] < 0) {if (ic < C - 1)ic++; else break;}
			else {if (ia < A - 1)ia++; else break;}
		}

	}
	return ans;
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