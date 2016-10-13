#include <iostream>
#include <cuda.h>

using namespace std;

const int SIZE = 120;
#define NUM_THREADS 1000000
#define ARRAY_SIZE  100

#define BLOCK_WIDTH 1000

__global__ void cudaPrefix(int * numberArray, int * data int texSize)
{
    __shared__  int tempArray[SIZE * 2];
    int id = blockIdx.x  * blockDim.x + threadIdx.x;
    int threadId = threadIdx.x;
    int offset = 1, temp;
    int ai = threadId;
    int bi = threadId + texSize / 2;
    int i;

    tempArray[ai] = data[id];
    tempArray[bi] = data[id + texSize / 2];

    for (i = texSize >> 1; i > 0; i >>= 1)
    {
        __syncthreads();
        if(threadId < i)
        {
            ai = offset * (2 * threadId + 1) - 1;  
            bi = offset * (2 * threadId + 2) - 1;  
            tempArray[bi] += tempArray[ai];
        }
        offset <<=  1;
    }

    if(threadId == 0)
        tempArray[texSize - 1] = 0;


    for (i = 1; i < texSize; i <<= 1) 
    {  
        offset >>= 1;  
         __syncthreads();  
        if (threadId < i)                       
        {  
            ai = offset*(2 * threadId + 1) - 1;  
            bi = offset*(2 * threadId + 2) - 1;  
            temp = tempArray[ai];  
            tempArray[ai] = tempArray[bi];  
            tempArray[bi] += temp;
        }
    }

    __syncthreads();  

    numberArray[id] = tempArray[threadId];
    numberArray[id + texSize / 2]  = tempArray[threadId + texSize / 2];
}

int data[100], n;

int main ()
{
    const int ARRAY_BYTES = ARRAY_SIZE * sizeof(int);
    int n = 10;
    for (int i = 0; i < n; i ++) data[i] = rand() % 10;
    for (int i = 0; i < n; i ++) cout << data[i] << " ";


    int * d_array;
    cudaMalloc((void **) &d_array, ARRAY_BYTES);
    cudaMemset((void *) d_array, 0, ARRAY_BYTES);
    cudaMemcpy(d_array, data, ARRAY_BYTES, cudaMemcpyHostToDevice);
    cout << endl;
    cudaPrefix<<<NUM_THREADS/BLOCK_WIDTH, BLOCK_WIDTH>>>(d_array, data, n);

    cudaMemcpy(data, d_array, ARRAY_BYTES, cudaMemcpyDeviceToHost);

    for (int i = 0; i < n; i ++) cout << data[i] << " ";
}