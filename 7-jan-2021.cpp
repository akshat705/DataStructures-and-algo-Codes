#include<bits/stdc++.h>
using namespace std;
string convertIntegerToRoman(int num)
{
	unordered_map<int, string>m;
	string ans = "";
	m[1] = "I"; m[5] = "V"; m[10] = "X"; m[50] = "L"; m[100] = "C"; m[500] = "D"; m[1000] = "M";
	m[4] = "IV"; m[40] = "XL"; m[400] = "CD"; m[9] = "IX"; m[90] = "XC"; m[900] = "CM";
	int dict[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	for (int i = 0; i < dict.size(); i++)
	{
		int temp = num / dict[i];
		for (int j = 1; j <= temp; j++)ans += m[dict[i]];
	}
	return ans;
}


void wizardOfOrz(int n)
{
	string start = "987654321", addon = "0123456789";
	string ans = "";
	if (n <= 9)ans = start.substr(0, n);
	else
	{
		n = n - 9;
		ans = start;
		int numberOfAddon = n / 10;
		int looseAddon = n % 10;
		for (int i = 0; i < numberOfAddon; i++)ans = ans + addon;
		ans = ans + addon.substr(0, looseAddon);
	}
	cout << ans << endl;
}

int lastWordLength(string s)
{
	int n = s.size();
	if (n == 0)return 0;
	int i = n - 1;
	while (s[i] == ' ')i--;
	if (i == -1)return 0;
	for (int j = i; j >= 0; j--)
	{
		if (s[i] == ' ')return n - i - 1;
	}
	return i + 1;
}
bool isPalindrome(string str, int s, int e)
{
	if (s > e)return false;
	while (e - s >= 1)
	{
		if (str[s] == str[e]) {s++; e--;}
		else return false;
	}
	return true;
}
bool convertToPalindrome2(string str)
{
	int s = 0, e = str.size() - 1;
	if (isPalindrome(str, 0, e))return true;
	while (s <= e)
	{
		if (str[s] == str[e]) {s++; e--;}
		else
		{
			if (isPalindrome(str, s + 1, e))return true;
			else if (isPalindrome(str, s, e - 1))return true;
			else return false;
		}
	}
	return false;
}
int minParanthesis(string str)
{
	stack<char>s;
	int ans = 0;
	for (auto x : str)
	{
		if (x == '(')s.push(x);
		else if (x == ')')
		{
			if (s.empty())ans++;
			else s.pop();
		}
	}
	ans += s.size();
	return ans;
}

/*int convertToPalindrome(string s)
{
	if (isPalindrome(s))return 0;
	int ans = 0;
	int f = 0, r = s.size() - 1;
	while (f < r)
	{
		if ((s[f] == s[r]) && (r - f == 1 || r - f == 0 || r - f == 2)) {return ans;}
		else {ans++; r--;}
	}
	return ans;
}*/
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
	cout << convertIntegerToRoman(s) << endl;
	return 0;

}