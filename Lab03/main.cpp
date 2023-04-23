#include <iostream>
#include <climits>
using namespace std;


//module reading user input
void arrayInput(int arr[], int n)
{
     for (int i = 0; i < n; i++)
        {
            cin>>arr[i]; //reading user input
        }//end of for loop
        return;
}//end of arrayInput

void Merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int arrL[n1];
    int arrR[n2];
    for(int i = 0; i < n1; i++)
    {
        arrL[i] = arr[p+i];
    }

    for(int j = 0; j < n2; j++)
    {
        arrR[j] = arr[q+j+1];
    }
    //arrL[n1+1]= INT_MAX;
    //arrR[n2+1]= INT_MAX;

    int i=0;
    int j=0;
    int k = p;
    while(i < n1 && j < n2)
    {
        if(arrL[i] < arrR[j])
        {
            arr[k]= arrL[i];
            i++;
        }
        else{
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = arrL[i];
        k++;
        i++;
    }
    while (j < n2){
        arr[k] = arrR[j];
        k++;
        j++;
    }
}

void Mergesort(int arr[], int p, int r)
{

    if(p < r)
    {
    int q = (p+r)/2;
    Mergesort(arr, p, q);
    Mergesort(arr, q+1, r);
    Merge(arr, p, q, r);
    }

}

//print out array
void printArray(int arr[], int n)
{
    //array print out sorted array
     for (int i = 0; i < n+1; i++)
    {
     cout << arr[i] << ";" ; //print number with ";"
    }
    cout << endl;//making them seperate
}//end of printArray

int main()
{
   //creating the array size and reading it
    int sizeArray=50;
    //reading user array size int
    //cin>>sizeArray;
    //creating the array depending on the user size
    int arr[50] = {50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,4,5,6,3,2,1};
    //int arr[sizeArray];
    //sending through a function to read the input
    //arrayInput(arr, sizeArray);
    int p = 0;
    int r = sizeArray;

    printArray(arr, r);

    Mergesort(arr, p, r);

    printArray(arr, sizeArray);

    return 0;

}
