#include <iostream>
using namespace std;
int n, k;
int mod = 1000000000;
int d[201][201]; // sum is i, using j numbers
int main(){
    cin >> n >> k;
    d[0][0] = 1;
    d[0][1] = 1;
    for(int i=0; i<=k; i++){
        d[0][i] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            //d[i][j] = d[i-1][j-1], d[i-2][j-1], d[i-3][j-1]
            //d[i- ][j - 1]
            for(int x=0; x<=i; x++){
                d[i][j] += d[i-x][j-1];
                d[i][j] %= mod;
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=k; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << d[n][k]%mod;
}