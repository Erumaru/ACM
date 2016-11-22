#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string text, keys[15];
int pos[15][15], n, x, p, cnt[256];
vector <char> g[15];

int cmp (int i, int j)
{
	return keys[x][i] < keys[x][j];
}

string get(string text, int h)
{
	int cur = 0;
	for (int i = 0; i < text.size(); i ++)
	{
		g[cur].push_back(text[i]);
		cur = (cur + 1) % p;
	}

	for (int i = 0; i < p; i ++)
	{
		for (int j = 0; j < g[i].size(); j ++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < p; i ++) reverse(g[i].begin(), g[i].end());

	text = "";
	for (int i = 0; i < p; i ++)
	{
		cur = pos[h][i];
		while (!g[cur].empty()) 
		{
			text += g[cur].back();
			g[cur].pop_back();
		}
	}

	return text;
}

int main ()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> keys[i];
	for (int i = 1; i <= n; i ++)
	{
		cout << keys[i] << "\n";
	}
	cin >> text;
	p = 100;
	for (int i = 1; i <= n; i ++)
	{
		memset(cnt, 0, sizeof cnt);
		string newString = "";
		for (int j = 0; j < keys[i].size(); j ++)
		{
			if (cnt[keys[i][j]]) continue;
			newString += keys[i][j];
			cnt[keys[i][j]] ++;
 		}
 		p = min(p, (int)newString.size());
 		keys[i] = newString;
	}

	for (int i = 1; i <= n; i ++) keys[i].resize(p);
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < p; j ++)
		{
			pos[i][j] = j;
		}
	}

	for (int i = 1; i <= n; i ++)
	{
		x = i;
		sort(pos[i], pos[i] + p, cmp);
	}

	for (int i = 1; i <= n; i ++)
	{
		text = get(text, i);
		cout << i << ":\n";
		cout << text << "\n";
	}

}