#include <iostream>
using namespace std;

const int m = 13;

int hashFunction(int key, int i){
     return ((key % m) + (i*(1+(key%11))%13 ));
}

void printTable (int* Table){
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

}

int main()
{
    int key;
    //create hash Table
    int Table[m];

    //Create Hash Table
    for(int i=0; i < m; i++) {
        Table[i]=-1;
    }
    //key insertions
    cin >> key;
    while (key != -1)
    {
        for (int i= 0; i<m; i++){
            int h = hashFunction(key, i);
            if(Table[h] == -1)
                break;
        }
        int k = hashFunction(key, m);
        Table [k] = key;
        cin >> key;
    }
    // ++++table printout++++
    printTable(Table);


    //After everything is inserted. And break after -1
    cout << "++++searching++++"<<endl;
    // KEY SEARCHING
  cin >> key;
  while(key != -2) {
    // 1. calculate hash function
    for (int i= 0; i<m; i++){
            int h = hashFunction(key, i);
            if(Table[h] == -2)
                break;
    }
    int h = hashFunction(key, m);
    // 2. search that key in your hash table, print either index or a message "NOT FOUND"
    if(Table[h] == key){
        cout << h<< endl;
    }
    else{
    cout << "NOT_FOUND" << endl;
    }
    cin >> key;
  }
  //after breaking from -2


    cout << "++++deleting++++"<< endl;
    //deleting the key
    cin >> key;
    while(key != -3) {
    // 1. calculate hash function
    for (int i= 0; i<m; i++){
            int h = hashFunction(key, i);
            if(Table[h] == -3)
                break;
    }
    // 2. delete a key from your hash table
    int h = hashFunction(key, m);

    if (Table[h] == key){
    Table[h] = NULL;
    }

    cin >> key;
  }
    // ++++table printout++++
    printTable(Table);

  return 0;
}
