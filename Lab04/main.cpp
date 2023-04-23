#include <iostream>
#include <climits>
using namespace std;
int max_cross_subarray(int* arr,int low,int mid,int high){

    int leftSum,rightSum;
    leftSum = INT_MIN;
    int sum =0;

    for(int i=mid; i < low;i++){
        sum =sum+arr[i];
        if (sum >leftSum){
            leftSum =sum;
        }
    }
    rightSum = INT_MIN;
    sum=0;

    for(int j=mid+1; j <high; j++){
        sum=sum+arr[j];
        if(sum>rightSum){
            rightSum=sum;
        }
    }

return(leftSum+rightSum);
}

int max_subarray(int* arr,int low,int high){
int leftSum, rightSum, crossSum;

if(high==low){
    return arr[low];
    }
int mid = (low+high)/2;

leftSum = max_subarray(arr,low,mid);
rightSum = max_subarray(arr,mid+1,high);
crossSum = max_cross_subarray(arr,low,mid,high);


if (leftSum >= rightSum  &&leftSum >= crossSum){
    return leftSum;
}
if (rightSum >= leftSum  &&rightSum >= crossSum){
    return rightSum;
}
if (crossSum >= rightSum  &&crossSum >= leftSum){
    return crossSum;
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

    int maxSum = max_subarray(arr, 0 , n-1);

    cout<<maxSum;

    return 0;
}
