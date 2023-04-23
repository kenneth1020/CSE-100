#include <iostream>
#include <vector>
using namespace std;
//lab07
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
    //first loop here
    for(int i = 0; i < n;i++)
    {
        C[i]=0;
    }
    //second loop here
    for(int j=0; j < n; j++){
            C[A[j][c]] ++;
    }
    //third loop here
    for(int i=1; i < n; i++){
        C[i] = C[i] + C[i-1];
    }

    //last for looop
    vector<vector<int>> newB;
    for(int i = 0; i < n; i++){
    vector<int> row;
     for(int j = 0; j <= c; j++)
        {
            row.push_back(0);
        }
    newB.push_back(row);
    }

    for(int j = n-1; j>=0; j--){
        newB[C[A[j][c]]] = A[j];
        C[A[j][c]]--;
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


int main()
{
      int n;
    cin>>n;
    vector<vector <int>> Sequence;
    for(int i=0; i < n;i++){
        vector<int> row;
        for(int j = 0; j < 10;j++){
            int value;
            cin>>value;
            row.push_back(value);
        }
        Sequence.push_back(row);
    }

    vector<vector<int>> sorted = radix_sort(Sequence,n);

    print(Sequence,n);
 return 0;
}
