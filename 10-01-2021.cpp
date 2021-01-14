#include<bits/stdc++.h>
using namespace std;
void input(vector<int>&v, int n)
{
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}
}
int diffk(vector<int>&v, int k)
{
	int n = v.size();
	int s = 0, e = 1;
	k = abs(k);
	while (e < n && s < e)
	{
		if (v[e] - v[s] == k)return 1;
		else if (v[e] - v[s] < k)e++;
		else s++;
	}
	return 0;
}
int pairWithGivenDifference(vector<int>&v, int d)
{
	unordered_map<int, int>m;
	for (auto x : v)
	{
		if (m.find(x + d) == m.end() && m.find(x - d) == m.end())
		{
			m.insert(make_pair(x, 1));
		}
		else return 1;
	}
	return 0;
}

int threeSum(vector<int>&v, int k)
{
	int n = v.size();
	sort(v.begin(), v.end());
	int ans = INT_MAX, minDiff = INT_MAX;
	for (int i = 0; i < n - 2; i++)
	{
		int s = i + 1, e = n - 1;
		while (s < e)
		{
			int ourSum = v[i] + v[s] + v[e];
			if (minDiff > abs(ourSum - k)) {ans = ourSum; minDiff = abs(ourSum - k);}
			if (ourSum - k == 0)return ourSum;
			else if (ourSum - k < 0)s++;
			else e--;
		}
	}

	return ans;
}
vector<vector<int>> threeSumZero(vector<int>&v)
{
	int n = v.size();
	sort(v.begin(), v.end());
	vector<int>a;
	vector<vector<int>>ans;

	for (int i = 0; i < n - 2; i++)
	{
		int s = i + 1, e = n - 1;
		while (s < e)
		{
			int ourSum = v[i] + v[s] + v[e];
			if (ourSum  == 0)
			{
				vector<int>temp{v[i], v[s], v[e]};
				if (ans.size() == 0)ans.push_back(temp);
				else if (temp != ans[ans.size() - 1])ans.push_back(temp);
				s++; e--;
			}
			else if (ourSum < 0)s++;
			else e--;
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
	int n;
	cin >> n;
	vector<int>v;
	input(v, n);
	vector<vector<int>>ans = threeSumZero(v);
	for (auto vec : ans)
	{
		for (auto x : vec)cout << x << " ";
		cout << endl;
	}

	return 0;

}





/*
 int i=0,j=1;
    while(i<a.size() && j<a.size())
    {
        if(i!=j && a[j]-a[i]==k)
        {
            return 1;
        }
        else if(a[j]-a[i]<k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return 0;

   ''''''''''''''''''''''''''''''''''''''''''''''''''
   int n = v.size();
    int s=0,e=1;
    k=abs(k);
    while(e<n&&s<e)
    {
        if(v[e]-v[s]==k)return 1;
        else if(v[e]-v[s]<k)e++;
        else s++;
    }
    return 0;