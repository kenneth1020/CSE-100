#include <iostream>
#include <stdlib.h>
using namespace std;

int partitions(int* arr, int p , int r){
int x = arr[r];
int i = p-1;
    for(int j = p; j <= r-1; j++)
        if (arr[j] <= x){
        i++
        swap(arr[i], arr[j]);
        }
    swap(arr[i+1], arr[r]);
    return (i+1);
}


int rpartition(int* arr, int p, int r){
int i = rand()%(r-p)+p;
swap(arr[i],arr[r]);
return partitions (arr, p ,r);
}

void rquicksort(int* arr, int p, int r){
  if(p < r){
    int q = rpartition(arr, p, r);
    rquicksort(arr, p, q-1);
    rquicksort(arr, q+1, r);
  }
}



int main()
{

    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0; i <n;i++){
        cin>>arr[i];
    }

    rquickSort(arr, 0, n-1)

     for (int i = 0; i < n; i++){
              cout<<arr[i]<<";";
     }


    return 0;
}
