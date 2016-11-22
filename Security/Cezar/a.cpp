#include <iostream>

using namespace std;

string text, current;

int main ()
{
	cin >> text;
	for (int i = 0; i < 26; i ++)
	{
		current = "";
		for (int j = 0; j < text.size(); j ++)
		{
			current += char((text[j] + i) % 26 + 'a');
		}
		cout << current << "\n\n";
	}
}