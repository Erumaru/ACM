#include <iostream>

using namespace std;


int data[100], n;

int main ()
{
	srand(17);
	int n = 10;
	for (int i = 0; i < n; i ++) data[i] = rand() % n;
	for (int i = 0; i < n; i ++) cout << data[i] << " ";
	cout << endl;
	for (int i = 1; i < n; i ++) data[i] += data[i - 1];
	for (int i = 0; i < n; i ++) cout << data[i] << " ";
}