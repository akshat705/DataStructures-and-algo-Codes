#include<bits/stdc++.h>
using namespace std;
int static dp[1001][1001];
#define N 1000000007
bool isPalindrome2(string s)
{
	int f = 0, e = s.size() - 1;
	while (e - s >= 2)
	{
		if (s[f] == s[e]) {f++; e--;}
		else return false;
	}
	return true;
}
int convertToPalindrone(string s)
{
	if (isPalindrome2(s))return 0;
	int ans = 0;
	int f = 0, r = s.size() - 1;
	while (f < r)
	{
		if ((s[f] == s[r]) && (r - f == 1 || r - f == 0 || r - f == 2)) {return ans;}
		else {ans++; r--;}
	}
	return ans;
}
int nstrstr(string s, string k)
{
	int code = 0, q = k.size(), p = s.size(), Nt = INT_MAX;
	if (q == 0)return -1;
	if (p == 0)return -1;
	for (auto x : k)
	{
		int n = x;
		code = (code % Nt + (n * n) % Nt) % Nt;
	}
	int i = 0, j = 0, temp = 0;
	while (i < p)
	{
		int t = s[i];
		if (i < q) {temp = temp + t * t; i++;}
		else
		{
			temp = temp - s[j] * s[j]; j++;
			temp = temp + t * t; i++;
		}
		if (temp == code)
		{
			bool flag = 1;
			for (int x = 0; x < p; x++)
			{
				if (s[j + x] != k[x]) {flag = 0;}
			}
			if (flag == 1)return j;
		}
	}
	return -1;
}
bool isDigit(char c)
{
	if (c >= 48 && c <= 57)return 1;
	return 0;
}
int isNumber(string s)
{
	int e = 0, d = 0;
	for (int i = 0; i < n; i++)
	{
		if (!isDigit(s[i]) || s[i] != 'e' || s[i] != '.')return 0;
		else if (s[i] == '.' && e == 1 || s[i] == '.' && d == 1 || s[i] == 'e' && e == 1 || s[i] == 'e'&&)return 0;
		else if (s[i] == '.')d = 1;
		else if (s[i] == 'e')e = 1;
	}
	return 1;
}
int isNumber2(string s)
{
	string p = "", n = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'e')
		{
			p = s.substr(0, i);
			n = s.substr(i + 1, s.size() - i - 1);
		}
		bool flag = 1;
		int i = 0;
		if (p.size() > 0 && p[0] == '-')i++;
		while (i < p.size())
		{
			if (!isNumber(s[i]) || s[i] != '.')return 0;
			i++;
		}

	}
}
void insertDigit(int &n, char d)
{
	int m = (((n % INT_MAX) * (10 % INT_MAX)) % INT_MAX + (d - 48) % INT_MAX) % INT_MAX;
	if (m < n)n = INT_MAX;
	else n = m;
}
int newAtoi(string s)
{
	bool sign = 1;
	int i = 0;
	if (s[0] == '-') {i = 1; sign = 0;}
	if (s[0] == '+')i = 1;
	int ans = 0;
	while (i < s.size() && s[i] >= 48 && s[i] <= 57)
	{
		insertDigit(ans, s[i]);
		if (ans == INT_MAX)
		{
			if (sign == 1)return ans;
			else return INT_MIN;
		}
		i++;
	}
	if (sign == 0)ans = ans * (-1);
	return ans;
}
int compareVErsions(string a, string b)
{
	int n = a.size(), m = b.size();
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		string temp1 = "", temp2 = "";
		while (1)
		{
			if (i == n)break;
			if (a[i] == '.') {i++; break;}
			else temp1.push_back(a[i++]);
		}
		while (1)
		{
			if (j == m)break;
			if (b[j] == '.') {j++; break;}
			else temp2.push_back(b[j++]);
		}
		if (temp1.size() > temp2.size())return 1;
		else if (temp1.size() < temp2.size())return -1;
		else
		{
			if (stoll(temp1) < stoll(temp2))return -1;
			else if (stoll(temp1) > stoll(temp2))return 1;
		}
	}
	return 1;
}
string nextSeq(string s)
{
	char c = s[0];
	int count = 1;
	string ans = "";
	for (int i = 1; i < s.size(); i++)
	{
		if (c == s[i]) {count++;}
		else
		{
			ans += to_string(count);
			ans.push_back(c);
			c = s[i]; count = 1;
		}
	}
	ans += to_string(count);
	ans.push_back(c);
	return ans;

}
string findPrefix(string a, string b)
{
	int n = min(a.size(), b.size());
	string ans = "";
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])ans.push_back(a[i]);
		else break;
	}
	return ans;
}
void removeConsecutive(string s , int b)
{
	int n = s.size(), count = 0;
	char c = '#';
	string ans = "";
	for (int i = 0; i < n; i++)
	{
		if (s[i] == c)count++;
		else
		{
			count = count % b;
			for (int j = 0; j < count; j++)ans.push_back(c);
			count = 1; c = s[i];
		}
	}
	count = count % b;
	for (int j = 0; j < count; j++)ans.push_back(c);
	cout << ans;
}
bool isVowel(char c)
{
	if (c == 65 + 32 || c == 69 + 32 || c == 73 + 32 || c == 79 + 32 || c == 85 + 32)return true;
	return false;
}
int countseq(string s)
{
	int n = s.size();
	int v = 0, c = 0;
	vector<int>count(n);
	for (int i = n - 1; i >= 0; i--)
	{
		if (isVowel(s[i])) {count[i] = c; v++;}
		else {count[i] = v; c++;}
	}
	int ans = 0;
	for (auto x : count)ans = (x % N + ans % N) % N;
	return ans;
}
bool ischar(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))return true;
	return false;
}
bool isPalindrome(string s)
{
	int l = 0, r = s.size() - 1;
	while (l < r)
	{
		if (ischar(s[l]) && ischar(s[r]))
		{
			char a = tolower(s[l]), b = tolower(s[r]);
			if (a != b)return false;
			else {l++; r--;}
		}
		else if (!ischar(s[l]))l++;
		else if (!ischar(s[r]))r--;
	}
	return true;
}
void rainwater(vector<int>&v)
{
	int n = v.size();
	vector<int>lm, rm;
	int m = 0;

	for (auto x : v)
	{
		lm.push_back(m);
		m = max(m, x);
	}
	m = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		rm.push_back(m);
		m = max(m, v[i]);
	}
	reverse(rm.begin(), rm.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int t = min(rm[i], lm[i]) - v[i];
		if (t >= 0)ans += t;
	}
	cout << ans << endl;

}
vector<int> stockSpan(vector<int>&v)
{
	int n = v.size();
	vector<int>ans;
	stack<int>s;
	for (int i = 0; i < n; i++)
	{
		if (s.empty())ans.push_back(1);
		else if (v[s.top()] > v[i])ans.push_back(i - s.top());
		else if (v[s.top()] <= v[i])
		{
			while (!s.empty() && v[s.top()] <= v[i])s.pop();
			if (s.empty())ans.push_back(i + 1);
			else ans.push_back(i - s.top());
		}
		s.push(i);
	}
	return ans;
}
int mincost(vector<int> v, int s, int e)
{
	if (s >= e)return 0;
	if (dp[s][e] != -1)return dp[s][e];
	int ans = INT_MAX;
	for (int k = s; k <= e - 1; k++)
	{
		int ls = mincost(v, s, k);
		int rs = mincost(v, k + 1, e);
		int tempans = ls + rs + (v[s - 1] * v[k] * v[e]);
		//cout << tempans << endl;
		ans = min(ans, tempans);
	}
	return dp[s][e] = ans;
}
int solve(vector<int> &a, int B) {
	int n = a.size();
	int s = 0, e = n - 1;
	int res = n;
	while (s <= e)
	{
		int m = (s + (e - s) / 2);
		if (a[m] <= B) {s = m + 1;}
		else if (a[m] > B) {res = m; e = m - 1;}
	}
	return res;
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>v;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		int b;
		cin >> b;
		cout << solve(v, b) << endl;

	}

	//cout << compareVErsions("11.25", "11.15");
	int t;
	cin >> t;
	while (t--)
	{

		string s;
		cin >> s;
		cout << convertToPalindrone(s) << endl;
	}
	char c = ' ';
	int n = c;
	cout << n; * /




	return 0;


}
