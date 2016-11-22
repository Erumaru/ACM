#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string keys[15], text;
int pos[15][15], n, x, h, p, cnt[256];
vector <char> g[15];

bool cmp(int i, int j)
{
	return keys[x][i] < keys[x][j];
}

string get(string text, int q)
{
	int now = 0;
	for (int i = 0; i < p; i ++)
	{
		int cur = pos[q][i];
		for (int j = 0; j < h; j ++)
		{
			g[cur].push_back(text[now ++]);
		}
	}

	text = "";

	now = 0;
	for (int i = 0; i < h; i ++)
	{
		for (int j = 0; j < p; j ++)
		{
			text += g[j][i];
		}
	}

	for (int i = 0; i < p; i ++) g[i].clear();

	return text;
}

int main ()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> keys[i];
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

	h = text.size() / p;
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

	for (int i = n; i > 0; i --)
	{
		text = get(text, i);
		cout << i << ":\n";
		cout << text << "\n"; 	
	}
}