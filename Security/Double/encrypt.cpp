#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string text, keys[15];
int pos[15][15], n, x, p;
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
	cin >> text;
	p = keys[1].size();
	
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