#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    cout << 50 << "\n";
    int n = 100000 ;
    for (int i = 1; i <= n; i ++) cout << char(i % 26 + 'a');
    cout << endl;
}