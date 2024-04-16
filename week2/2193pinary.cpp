#include <iostream>
using namespace std;
int n;
long long d[91][2];
int main(){
    cin >> n;
    d[1][0] = 0;        // 1, 10
    d[1][1] = 1;
    d[2][0] = 1;
    d[2][1] = 0;
    for(int i=3; i<=n; i++){
        // d[i][j]: length of i, end with j
        // d[i][0] = d[i-1][1];
        // d[i][1] = d[i-1][0];
        d[i][0] = d[i-1][1] + d[i-1][0];
        d[i][1] = d[i-1][0];
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<2; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << d[n][0] + d[n][1] << endl;
}
// 10000, 10010, 10100
// 10001, 10101