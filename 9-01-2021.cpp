#include<bits/stdc++.h>
using namespace std;
int PairWithGivenDifference(vector<int>v, int b)
{
	sort(v.begin(), v.end());
	int n = v.size();
	int l = n - 2, r = n - 1;
	while (l >= 0 && r >= 0)
	{
		int diff = v[r] - v[l];
		if (diff == b)return 1;
		else if (b < diff)r--;
		else if (b > diff)l--;

	}
	return 0;
}
string zigzagString(string s, int f)
{
	if (f == 1)return s;
	int dir = -1, cf = 0, n = s.size();
	char a[f][n];
	memset(a, '.', sizeof(a));
	for (int i = 0; i < n; i++)
	{
		if (cf >= f) {cf = f - 2; dir = 1;}
		if (cf < 0) {cf = 1; dir = -1;}
		if (dir == -1 && cf < f) {a[cf][i] = s[i]; cf++;}
		else if (dir == 1 && cf >= 0) {a[cf][i] = s[i]; cf--;}
	}
	string ans = "";
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < n; j++) {if (a[i][j] != '.')ans = ans + a[i][j];}
	}
	return ans;
}
string convertIntegerToRoman(int num)
{
	unordered_map<int, string>m;
	string ans = "";
	m[1] = "I"; m[5] = "V"; m[10] = "X"; m[50] = "L"; m[100] = "C"; m[500] = "D"; m[1000] = "M";
	m[4] = "IV"; m[40] = "XL"; m[400] = "CD"; m[9] = "IX"; m[90] = "XC"; m[900] = "CM";
	int dict[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	for (int i = 0; i < 13; i++)
	{
		int temp = num / dict[i];
		for (int j = 1; j <= temp; j++)ans += m[dict[i]];
		num = num % dict[i];
	}
	return ans;
}

int convertRomanToInteger(string str)
{
	int n = str.size();
	unordered_map<char, int>m;
	char prev = '#';
	m['#'] = 0; m['I'] = 1; m['V'] = 5; m['X'] = 10; m['L'] = 50; m['C'] = 100; m['D'] = 500; m['M'] = 1000;
	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		char c = str[i];
		if (m[c] >= m[prev])ans += m[c];
		else if (m[c] < m[prev])ans -= m[c];
		prev = c;
	}
	return ans;
}
string addBinaryString(string a, string b)
{
	string ans = "", temp = "";
	int c = 0;
	if (a.size() > b.size())
	{
		for (int i = 0; i < (a.size() - b.size()); i++)temp.push_back('0');
		temp = temp + b;
		b = temp;
	}
	else if (a.size() < b.size())
	{
		for (int i = 0; i < (b.size() - a.size()); i++)temp.push_back('0');
		temp = temp + a;
		a = temp;
	}
	for (int i = a.size() - 1; i >= 0; i--)
	{
		int A = a[i] - 48, B = b[i] - 48;
		if (A + B + c == 3)     {ans.push_back(48 + 1); c = 1;}
		else if (A + B + c == 2) {ans.push_back(48); c = 1;}
		else if (A + B + c == 1) {ans.push_back(48 + 1); c = 0;}
		else if (A + B + c == 0) {ans.push_back(48); c = 0;}
	}
	if (c)ans.push_back(48 + 1);
	reverse(ans.begin(), ans.end());
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
	string S = zigzagString(s, 3);
	cout << S << endl;
	return 0;

}
/*
 string ans = "";
   if (a.size() > b.size())
	{
		for (int i = 0; i < (a.size() - b.size()); i++)b.push_back('0');
	}
	else if (a.size() < b.size())
	{
		for (int i = 0; i < (b.size() - a.size()); i++)a.push_back('0');
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int c = 0;

	for (int i = 0; i < a.size(); i++)
	{
		int A = a[i] - 48, B = b[i] - 48;
		if (A + B + c == 3)     {ans.push_back(48 + 1); c = 1;}
		else if (A + B + c == 2) {ans.push_back(48); c = 1;}
		else if (A + B + c == 1) {ans.push_back(48 + 1); c = 0;}
		else if (A + B + c == 0) {ans.push_back(48); c = 0;}
	}
	if (c)ans.push_back(48 + 1);
	reverse(ans.begin(), ans.end());
	return ans;1001110001111010101001110*/