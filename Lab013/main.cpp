
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sys/time.h>
#include <climits>
using namespace std;
//using 377 to help print out the Print optimal parens
void POP(vector<vector<int>> s, int i, int j){
	if (i == j){
		cout << 'A' << i-1;
	}
	else{
	cout << "(";
	POP(s, i, s[i][j]);
	POP(s, s[i][j]+1,j);
	cout << ")";
	}
}

void MCO(int *p, int n){
    //creating two vectors to be the new tables refer to pg 375
    vector<vector<int>>m(n+1, vector<int>(n+1,0));
    vector<vector<int>>s(n+1, vector<int>(n+1, 0));

    //creating a variable to hold the optimal value
    int opt = 0;

    //using the Matrix Chain order pseudo code
    for(int L = 2; L <= n; L++){
        for(int i = 1; i <= n - L + 1; i++){
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    opt = q;
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << opt << endl;
    POP(s, 1, n);
    cout << endl;
}

int main(int argc,char **argv)
{
    int n;
    cin >> n;
    int p[n+1];
    for(int i = 0; i < n+1; i++){
        cin >> p[i];
    }
    MCO(p, n);
    return 0;
}
