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
void print(vector<int>&v)
{
	for (auto x : v)cout << x << " ";
	cout << endl;
}
int redundantBraces(string s)
{
	stack<char>st;
	for (auto c : s)
	{
		if (c != ')')st.push(c);
		else if (c == ')')
		{
			if (st.top() == '(')return 1;
			while (st.top() != '(')st.pop();
			st.pop();
		}
	}
	return 0;
}
string simplifyDirectoryPath(string s)
{
	vector<string>v;
	string temp = "";
	int n = s.size();
	for (int i = 1; i < n; i++)
	{
		char x = s[i];
		if (x != '/')temp.push_back(x);
		else if (x == '/') {if (temp.size() > 0)v.push_back(temp); temp = "";}
	}
	for (auto str : v)cout << str << "--";
	cout << endl;
	stack<string>stk;
	for (auto x : v)
	{
		if (x != ".." && x != ".")stk.push(x);
		else if (x == ".." && !stk.empty())stk.pop();
	}
	v.clear();
	while (!stk.empty())
	{
		string x = stk.top();
		v.push_back(x);
		stk.pop();
	}
	reverse(v.begin(), v.end());
	s = "/";
	for (auto x : v) {s = s + x; s = s + "/";}
	if (s.size() > 1)s.pop_back();
	return s;
}
vector<int> nearestGreaterToRight(vector<int>&v)
{
	stack<int>stk;
	vector<int>ans;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		while (!stk.empty() && stk.top() <= v[i])stk.pop();
		if (stk.empty())ans.push_back(0);
		else ans.push_back(stk.top());
		stk.push(v[i]);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
vector<int> nearestSmallerToRight(vector<int>&v)
{
	stack<int>stk;
	vector<int>ans;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		while (!stk.empty() && v[stk.top()] >= v[i])stk.pop();
		if (stk.empty())ans.push_back(-1);
		else ans.push_back(stk.top());
		stk.push(i);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
vector<int> nearestGreaterToLeft(vector<int>&v)
{
	stack<int>stk;
	vector<int>ans;
	for (int i = 0; i < v.size(); i++)
	{
		while (!stk.empty() && stk.top() <= v[i])stk.pop();
		if (stk.empty())ans.push_back(0);
		else ans.push_back(stk.top());
		stk.push(v[i]);
	}
	return ans;
}
vector<int> nearestSmallerToLeft(vector<int>&v)
{
	stack<int>stk;
	vector<int>ans;
	for (int i = 0; i < v.size(); i++)
	{
		while (!stk.empty() && v[stk.top()] >= v[i])stk.pop();
		if (stk.empty())ans.push_back(-1);
		else ans.push_back(stk.top());
		stk.push(i);
	}
	return ans;
}
int maxAreaOfHistogram(vector<int>&v)
{
	vector<int>left = nearestSmallerToLeft(v);
	vector<int>right = nearestSmallerToRight(v);
	int ans = 0;
	for (int i = 0; i < v.size(); i++)ans = max(ans, (right[i] - left[i] - 1) * v[i]);
	return ans;
}
#define N 1000000007
int MAXSPPROD(vector<int>&v)
{
	vector<int>left = nearestGreaterToLeft(v);
	vector<int>right = nearestGreaterToRight(v);
	int maxm = INT_MIN;
	int ans = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		int curr = ((left[i] % N) * (right[i] % N)) % N;
		if (maxm < curr) {maxm = curr; ans = v[i];}
	}
	return maxm;
}
int rainWaterTrapping(vector<int>&v)
{
	vector<int>left, right;
	int maxm = 0;
	for (int i = 0; i < v.size(); i++)
	{
		left.push_back(maxm);
		maxm = max(maxm, v[i]);
	}
	maxm = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		right.push_back(maxm);
		maxm = max(maxm, v[i]);
	}

	reverse(right.begin(), right.end());

	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int water = min(left[i], right[i]) - v[i];
		if (water > 0)ans += water;
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
	int s;
	cin >> s;
	vector<int>v, ans;
	input(v, s);
	/*ans = nearestGreaterToLeft(v);
	print(ans);
	ans.clear();
	ans = nearestGreaterToRight(v);
	print(ans);

	cout << MAXSPPROD(v);
	cout << endl;*/
	cout << rainWaterTrapping(v);

	return 0;

}