#include <iostream>
using namespace std;

const int m = 13;

int hashFunction(int key, int i){
    return key % m;
}

int main() {
  int key;

  // Create Hash Table
  int Table[m];

  // Initialize Hash Table
  for(int i=0; i < m; i++) {
    Table[i]=-1;
  }

  // KEY INSERTION
  cin >> key;
  while(key != -1) {
    // 1. calculate hash function
    for(int i=0; i<m; i++) {
       int h = hashFunction(key,i);
       if(Table[h]==-1)
          break;
    }
    // 2. put it into your hash table
    int h = hashFunction(key, m);
    Table[h] = key;

    cin >> key;
  }

  // ++++table printout++++
  cout << "++++table printout++++"<<endl;
  for(int i = 0; i < m; i++){
    if(Table[i] >= 0){
      cout<<Table[i]<<endl;
    }
    else{
      cout<<endl;
    }
  }

  cout << "++++searching++++"<<endl;

  // KEY SEARCHING
  cin >> key;
  while(key != -2) {
    // 1. calculate hash function

    int h = hashFunction(key, i);
    // 2. search that key in your hash table, print either index or a message "NOT FOUND"

    cin >> key;
  }

  cout << "++++deleting++++"<< endl;
  // KEY DELETING
  cin >> key;
  while(key != -3) {
    // 1. calculate hash function
    int h = hashFunction(key, i);
    // 2. delete a key from your hash table
    cin >> key;
  }

  // ++++table printout++++
  cout << "++++table printout++++"<<endl;
  for(int i = 0; i < m; i++){
    if(Table[i] >= 0){
      cout<<Table[i]<<endl;
    }
    else{
      cout<<endl;
    }
  }

  return 0;

}

