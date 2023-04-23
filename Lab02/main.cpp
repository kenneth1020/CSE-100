#include <iostream>

using namespace std;

//module reading user input
void arrayInput(int arr[], int n)
{
    int temp; //making temp to read user input for number into the array
     for (int i = 0; i < n; i++)
        {
            cin>>temp; //reading user input
            arr[i] = temp;
        }//end of for loop
        return;
}//end of arrayInput

int binarySearch(int arr[], int size_array, int key)
{
    //creating the variables low, high, and mid.
    //Low = to the lowest value of the array
    //High = the highest value at the end of the array
    //Mid = to the combination of high low and be the middle point of the array
    int low, high, mid;
    low = 0;
    high = size_array;
    while ( low <= high){
        //mid will always be the combination of low and high divide by two. Need in the while loop of we can find the number in the search
        mid = (high+low)/2;
        //if the middle is equal to the key then all the number is return the index of the found number of the array
        if(mid == key){
            return mid;
            }
        //if key is greater than mid we can assume the value of the number is bigger than mid+1
        //skipping all the number between low and mid.
        else if(key > mid){
            low = mid+1;
            }
        //if key is not greater than we assume all the higher number than mid is smaller
        //skipping all the number in the array between mid and high
        else{
            high=mid-1;
            }

    }

    return -1;
}

//start of main
int main()
{
    int size_array; //creating the n = size of the array
    //asking user for array sizes
    cout << "Please, enter in size of your array" << endl;

    cin>>size_array; //reading user input for n
    int arr[size_array];
    //end of answer to your question

    //ask user for all n = number into the array
    cout << "array of " <<size_array<< ". Please input all number of your array." << endl;
    //reading in a for loop for all user input
    arrayInput(arr, size_array);

    cout << "Please, enter in number you are searching for." << endl;
    int key;
    cin>>key;

    int index =binarySearch(arr, size_array, key);

    cout << index << endl;

    //clean up compiler
    delete[] arr;
}//end of main
