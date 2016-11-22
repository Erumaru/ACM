#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sz(n) int(n.size())
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

int n;
string s, t;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	t = "";   
    cin >> n;
    cin >> s;
    s += "123";
    for (int i = 0; i < n; i ++)
    {
    	if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o')
    	{
    		bool ok = false;
    		int j = i + 3;
    		for (j = i + 3; j < n; j += 2)
    		{
    			if (s[j] != 'g' || s[j + 1] != 'o') break;
    		}
    		i = j - 1;
    		t += "***";
    	}
    	else t += s[i];
    }          

    cout << t << "\n";  
}

