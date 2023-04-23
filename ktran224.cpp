#include <iostream>

using namespace std;

//using the book algorithm and reversing the sign in comparing the key to arr[j-1]. Changing the equation from lowest order to highest order.
void insertionSort(int arr[], int n){
    int key, i, j; //creating the variable key = the number we are comparing. I and J are increments comparing the through the array
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i;
        while(j > 0 && key > arr[j-1])
        {
            arr[j]=arr[j-1];
            j= j -1;
        }
        arr[j]=key;
    }
}
//print out array
void printArray(int arr[], int n)
{
    //array print out sorted array
     for (int i = 0; i < n; i++)
    {
     cout << arr[i] << ";" ; //print number with ";"
    }
    cout << endl;//making them seperate
}//end of printArray

//module reading user input
void arrayInput(int arr[], int n)
{
    int temp; //making temp to read user input for number into the array
     for (int i = 0; i < n; i++)
        {
            cout << "You have: " << n-i << " -number left to input." << endl;
            cin>>temp; //reading user input
            arr[i] = temp;
        }//end of for loop
        return;
}//end of arrayInput

//start of main
int main()
{
    int n; //creating the n = size of the array
    //asking user for array sizes
    cout << "Please, enter in size of your array" << endl;

    cin>>n; //reading user input for n
    int arr[n];
    //end of answer to your question

    //ask user for all n = number into the array
    cout << "array of " <<n << ". Please input all number of your array." << endl;
    //reading in a for loop for all user input
    arrayInput(arr, n);

    //sending user custom array to sorting program
    insertionSort(arr, n);
    //sending sorted array into printing
    printArray(arr, n);

    //clean up compiler
    delete[] arr;
}//end of main
