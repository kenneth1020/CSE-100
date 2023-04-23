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

int linearSearch(int arr[], int size_array, int key)
{
    for (int i = 0; i <size_array; i++)
    {
        if(arr[i] == key)
        {
            return i;
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
    int arr[size_array];//creating size of the array

    //searching for the key
    cout << "Please, enter in number you are searching for." << endl;
    int key;
    cin>>key;

    //ask user for all n = number into the array
    cout << "array of " <<size_array<< ". Please input all number of your array." << endl;
    //reading in a for loop for all user input
    arrayInput(arr, size_array);



    int index =linearSearch(arr, size_array, key);

    cout << index << endl;

    //clean up compiler
    delete[] arr;
}//end of main
