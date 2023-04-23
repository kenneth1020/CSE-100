#include <iostream>
#include <list>
#include <vector>

using namespace std;

void print_hash_table(list<int>* hash_table, int m){
  // TODO: print hash table, follow the format
  for (int i = 0; i < m; i++){
    cout << i << " : " ;
    for( auto x: hash_table[i])
    {
        cout << "->" << x;
        cout << endl;
    }
  }
}

int hash_function(int key, int m){
  return key % m;
}

void insert_key(list<int>* hash_table, int key, int m){
  int idx = hash_function(key, m);
  hash_table[idx].push_front(key);
}

void delete_key(list<int>* hash_table, int key, int m){
  int idx = hash_function(key, m);
  // delete from list: hash_table[idx]
    list <int> :: iterator i;
  for (i = hash_table[idx].begin(); i != hash_table[idx].end(); i++)
  if (*i == key){
    break;
  }
  if ( i != hash_table[idx].end()){
  hash_table[idx].erase(i);
  }
}

void search_key(list<int>* hash_table, int key, int m){
    list<int> l =hash_table[hash_function(key, m)];
    list<int>::iterator x;
    int index=0;
    if(l.empty())
    cout<<key<<":NOT_FOUND"<<endl;//list empty means not found
    else{
        for (x=l.begin(); x!=l.end(); ++x)//search list
        {
            if(*x==key)
            {
            cout<<key<<":Found_At "<< hash_function(key, m) <<","<<index<<endl;
            return;
            }
        index++;
        }
    cout<<key<<":NOT_FOUND"<<endl;
    }
}



int main(){
  int m = 0;
  cin>>m;
  list<int>* hash_table = new list<int>[m];

  while(true){

    char c;
    cin>>c;

    if(c == 'e'){
      break;
    } else if(c == 'o'){
       print_hash_table(hash_table, m);
    } else if(c == 'i'){
       int key;
       cin>>key;
       insert_key(hash_table, key, m);
    } else if(c == 'd'){
        int dkey;
       cin>>dkey;
      delete_key(hash_table, dkey, m);
    } else if(c == 's'){
        int skey;
       cin>>skey;
    search_key(hash_table, skey, m);
    }

  }//end of while loop

  return 0;
}//end of main
