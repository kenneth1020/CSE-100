#include<stdio.h>
#include<limits.h>
#include <iostream>

using namespace std;


int cutRod(int *p, int n, int* r, int* s){
  if(n == 0) return 0;

  if(r[n] >= 0) return r[n];

  int q = INT_MIN;
  for(int i = 1; i <= n; i++){
    int ri = p[i] + cutRod(p, n-i,r,s);
    if (ri > q){
      q = ri;
      s[n-1] = i;
    }
  }

  r[n] = q;

  return q;
}
/*
int MCRA(int* arr, int sizes, int* r, int* s){
int q;
if(r[sizes]>=0)
    return r[sizes];
if(sizes==0)
    int q=0;
else
    int q = INT_MAX;
    for(int i = 1;i < sizes;i++){
        int b= arr[i] + MCRA(arr,sizes-1,r,s);
        q = max(q ,b);
    }
r[sizes] =q;
return q;
}
*/
void printCuts(int* s, int sizes){
 if(s[sizes]==INT_MAX){
    return printCuts(s, sizes-1);
 }
 while (sizes > 0)
   {
       cout << s[sizes] << " ";
       sizes -=s[sizes];
   }
}
int main()
{
    int sizes;
    cin >> sizes;
    int* arr = new int[sizes+1];
    int* r = new int[sizes+1];
    int* s = new int[sizes+1];

    for(int i=1; i<=sizes; i++){
    cin >> arr[i];
    r[i] = INT_MIN;
    s[i] = INT_MIN;
    }

    int maxcut = cutRod(arr, sizes, r ,s);
    cout<<maxcut<<endl;

    // while loop to print array s;
   // cout<< MCRA(arr, sizes, r, s)<<" ";
   // printCuts(s, sizes);
  int length = sizes-1;
   while (length > 0)
   {
       cout << s[length] << " ";
       length -=s[length];
   }

    cout<<"-1"<<endl;
 /*   for(int j = 0; j <sizes; j++){
        cout<<s[j]<<"     "<<j<<endl;
    }
*/
    return 0;
}
