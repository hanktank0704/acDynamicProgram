#include <iostream>
using namespace std;
int n;
int a[10001] ={0,};
int d[10001][4] = {0,};  // d[i][0]: not drink a[i] one
                        // d[i][1]: drink a[i] and not drink a[i-1]
                        // d[i][2]: drink a[i] and a[i-1]
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    d[0][0] = 0;
    d[1][1] = a[1];
    d[1][2] = 0;
    for(int i=2; i<=n; i++){
        d[i][0] = max(max(d[i-1][0], d[i-1][1]), d[i-1][2]); // not drink i,
        d[i][1] = d[i-1][0] + a[i];     // drink i, not i-1: 
        d[i][2] = d[i-2][0] + a[i] + a[i-1];
        // for(int j=0; j<3; j++){
        //     d[i][j] = max(max(d[i-1][0] + a[i], d[i-1][1] + a[i]), d[i-1][2]);
        // }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<3; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int mx=0;
    for(int i=0; i<3; i++){
        if(mx < d[n][i]) mx = d[n][i];
    }
    cout << mx << endl;
    return 0;
}