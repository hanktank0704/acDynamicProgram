#include <iostream>
using namespace std;
int mod = 10007;
int n;
int d[1001][10];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        //d[i][j]: length i, ends with j
        for(int j=0; j<=9; j++){
            if(i==1) d[i][j] = 1;
            for(int k=0; k<=j; k++){
                d[i][j] += d[i-1][k];
                d[i][j] = d[i][j] % mod;
            }
        }
    }
    // for(int j=1; j<=n; j++){
    //     for(int i=0; i<=9; i++){
    //         cout << d[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for(int i=0; i<=9; i++){
        ans += d[n][i];
        ans %= mod;
    }
    cout << ans;
    return 0;
}