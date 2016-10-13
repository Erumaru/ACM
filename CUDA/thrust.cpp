#include <thrust/scan.h>
#include "gputimer.h"
#include <cstdio>

using namespace std;

int data[100], n;

int main ()
{
	GpuTimer timer;
	n = 10;
	timer.Start();
	for (int i = 0; i < n; i ++) data[i] = rand() % 10;
	for (int i = 0; i < n; i ++) cout << data[i] << " ";
	cout << endl;
	thrust::inclusive_scan(data, data + n, data);
	timer.Stop();
	for (int i = 0; i < n; i ++) cout << data[i] << " "; 
	printf("Time: %.12f\n", timer.Elapsed());
}