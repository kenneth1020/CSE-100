#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> A, int n){
    for (int i = 0; i < n; i++)
    {
    vector<int>::iterator v = A[i].begin();
    while( v != A[i].end()){
        cout << *v << ";";
        v++;
        }
    cout << endl;
    }
}

vector<vector<int>> counting_sort(vector<vector<int>> A, int c, int n){
  int C[10];
  // first for loop here...
  // ...
    for (i = 0; i < n; i++){
    C[arr[i][c]]++;
    }

  // second for loop here:
  for(int j=0; j < n; j++){
    C[A[j][c]] ++;
  }

  // third for loop here...
  // ...
    for (i = 1; i < 10; i++){
    C[i] += C[i-1];
    }
  // the last for loop...
  vector<vector<int>> newB;
  for(int i = 0; i < n; i++){
    vector<int> row;
    for(int j = 0; j <= d; j++){
      row.push_back(0);
    }
    newB.push_back(row);
  }

  for(int j = n-1; j>=0; j--){
    newB[C[A[j][c]]] = A[j]; // additional for loop to copy A[j]
    //update array C
  }

  //fourth loop
    for (i = 0; i < n; i++){
    A[i] = newB[i];
    }

  return newB;

}

vector<vector<int>> radix_sort(vector<vector<int>> A, int n){
  int d = 9;

  vector<vector<int>> B;
  for(int i = 0; i < n; i++){
    vector<int> row;
    for(int j = 0; j <= d; j++){
      row.push_back(A[i][j]);
    }
    B.push_back(row);
  }

  for(int i = d; i >= 0; i--){
    B = counting_sort(B, i, n);
  }

  return B;
}

int main (){
    int arraySize;
    cin >> arraySize;

    vector<vector<int>> Sequence;

    for (int i = 0; i < arraySize;i++){
        vector<int> row;
        for (int j = 0; j<10;j++){
            int value;
            cin>>value;
            row.push_back(value);
        }
        Sequence.push_back(row);
    }

    vector<vector<int>> sorted = radix_sort(Sequence, arraySize);

    //print out sorted array
    print(sorted, n);
    return 0;
}
