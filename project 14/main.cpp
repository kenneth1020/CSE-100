#include <bits/stdc++.h>

using namespace std;
char pointer = 'A';
struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct MinHeapSearching {
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode* root, string str, char letter){
    if (!root){
        return;
    }
    if (root->data != '$' ){
        //cout << root->data << ": ";
        cout<< str << endl;
    }
    printCodes(root->left, str + "0", letter);
    printCodes(root->right, str + "1",letter);
}

void HuffmanCodes(char letter, int freq[], int n){
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, MinHeapSearching> minHeap;
    for (int i = 0; i < n; ++i){
        minHeap.push(new MinHeapNode(letter++, freq[i]));
    }
    while (minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "", letter);

}

int main(){
    int n;
    cin >> n;
    int freq[n];
    for(int i = 0; i < n; i++){
        cin >> freq[i];
    }
    //int n = 6;
   // int freq[] = { 5, 3, 6, 7, 1, 18};
    char letter ='A';
    HuffmanCodes(letter, freq, n);
    return 0;
}
