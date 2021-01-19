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
int balancedParanthesis(string s)
{
	stack<char>stk;
	for (auto c : s)
	{
		if (c == '(')stk.push('(');
		else if (c == ')')
		{
			if (stk.empty())return 0;
			stk.pop();
		}
	}
	if (stk.empty())return 1;
	return 0;
}
int evaluateExpression(vector<string>&exp)
{
	stack<int>stk;
	int n = exp.size();
	for (int i = 0; i < n; i++)
	{
		if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/")
		{
			int a = stk.top(); stk.pop();
			int b = stk.top(); stk.pop();
			int temp;
			if (exp[i] == "+")temp = a + b;
			else if (exp[i] == "-")temp = b - a;
			else if (exp[i] == "*")temp = a * b;
			else if (exp[i] == "/")temp = b / a;
			stk.push(temp);
		}
		else
		{
			int n = stoi(exp[i]);
			stk.push(n);
		}
	}
	return stk.top();
}
string firstNonRepeatingCharacterInStreamOfCharacters(string s)
{
	int n = s.size();
	int count[26] = {0};
	string ans = "";
	queue<char>q;
	for (auto c : s)
	{
		if (count[c - 'a'] == 0)q.push(c);
		count[c - 'a']++;
		while (!q.empty() && count[q.front() - 'a'] > 1)q.pop();
		if (q.empty())ans.push_back('#');
		else ans.push_back(q.front());
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
	string s;
	cin >> s;
	/*vector<int>v, ans;
	input(v, s);

	cout << endl;
	cout << rainWaterTrapping(v);*/
	cout << firstNonRepeatingCharacterInStreamOfCharacters(s) << endl;

	return 0;

}