#include <iostream>
using namespace std;
int mod = 9901;
int n;
int d[100001][3];  
int main(){
    cin >> n;
    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;
    for(int i=2; i<=n; i++){
        //d[i][j]: using until ith jth cage, how many ways to put lions in
        //d[i][0]: not using both a[i][0] a[i][1]
        //d[i][1]: only using a[i][0]
        //d[i][2]: only using a[i][1]
        d[i][0]= d[i-1][0] + d[i-1][1] + d[i-1][2];
        d[i][1]= d[i-1][0] + d[i-1][2];
        d[i][2]= d[i-1][0] + d[i-1][1];
        for(int j=0; j<3; j++){
            d[i][j] %= mod;
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<=2; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = (d[n][0] + d[n][1]  + d[n][2])%mod;
    cout << ans << endl;

    return 0;
}