#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string keys[15], text;
int pos[15][15], n, x, h, p;
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
	p = keys[1].size();
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