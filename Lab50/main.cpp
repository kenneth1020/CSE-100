#include <iostream>

using namespace std;

void maxHeapify(int* arr, int n, int i){
int largest = i;
int l = 2*i+1;
int r = 2*i+2;
if ( l < n && arr[l] > arr[largest]){
    largest = l;
    }
if(r < n && arr[r] > arr[largest]){
    largest =r;
            }
if(largest != i){
    swap(arr[i], largest);
    maxHeapify(arr, n, largest);
                }

}//end of maxHeapify

void build_heap(int* arr, int n){
for (int i = (n / 2 - 1); i >= 0; i--)
        maxHeapify(arr, i, n);
}//end of max_heap

void heapSort(int* arr,int n)
{
    build_heap(arr, n);
    for(int i = n-1; i > 0; i-- ){
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main()
{

    int n;
    cin>>n;
    int*arr=new int[n+1];
    for(int i=0; i < n;i++){
        cin>>arr[i];
    }

    heapSort(arr, n);

    for (int i = 1; i <= n; i++){
            cout<< arr[i] <<";";
    }


    return 0;
}
