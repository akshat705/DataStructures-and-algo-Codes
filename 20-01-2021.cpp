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
int isColourful(int num)
{
	string s = to_string(num);
	unordered_map<string, int>m;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		string temp = "", hash = to_string(i); temp.push_back(s[i]);

		m[temp + hash] = s[i] - 48;
		for (int j = i + 1; j < n; j++)
		{
			string temp2 = temp;
			temp2.push_back(s[j]);
			m[temp2 + hash] = m[temp + hash] * (s[j] - 48);
			temp = temp2;
		}
	}
	unordered_map<int, int>count;
	for (auto x : m)
	{
		if (count.find(x.second) != count.end())return 0;
		count[x.second] = 1;
	}
	return 1;
}
void print(vector<int>&v)
{
	for (auto x : v)cout << x << " ";
	cout << endl;
}
int findMax(string &s, int idx)
{
	int maxi = idx;
	for (int i = idx; i < s.size(); i++)
	{
		if (s[i] > s[maxi])maxi = i;
	}
	return maxi;
}
string maximalString(string &s, int b)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (b)
		{
			int idx = findMax(s, i);
			if (i != idx) {swap(s[i], s[idx]); b--;}
		}
		else break;
	}
	return s;
}
void grayCodeHelper(string s, int i, vector<string>&ans)
{
	ans.push_back(s);
	string temp;
	for (int k = i; k >= 0; k--)
	{
		temp = s;
		if (s[k] == '0')temp[k] = '1';
		else if (s[k] == '1')temp[k] = '0';
		grayCodeHelper(temp, k - 1, ans);
	}
}
void nBitGrayCodes(int n)
{
	vector<string>ans;
	string s = "";
	int t = n;
	while (t--)s.push_back('0');
	grayCodeHelper(s, n - 1, ans);
	for (auto x : ans)cout << x << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int b;
	cin >> b;
	cout << isColourful(b);
	return 0;

}