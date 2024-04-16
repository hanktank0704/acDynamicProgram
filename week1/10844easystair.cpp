#include<iostream>
using namespace std;
int d[101][10] ={0,};     //length, the ending number
int n;
int mod = 1000000000;
int main(){
    cin >> n;
    for(int i=0; i<10; i++){
        d[1][i] = 1;
    }
    d[1][0] = 0;
    for(int i=2; i<=n; i++){
        for(int j=1; j<9; j++){
            d[i][j] = d[i-1][j-1] + d[i-1][j+1];
            d[i][j] = d[i][j] % mod;
        }
        d[i][9] = d[i-1][8] % mod;
        d[i][0] = d[i-1][1] % mod;
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<10; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int sum=0;
    for(int i=0; i<10; i++){
        sum += d[n][i];
        sum %= mod;
    }
    cout << sum % mod<< endl;
}
// 123456789
// 123
// 12
// 32
