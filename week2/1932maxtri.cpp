#include <iostream>
using namespace std;
int n;
int a[501][501];
int d[501][501];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> a[i][j];
        }
    }
    d[1][1] = a[1][1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            //d[i][j] : maximum sum of ith line, jth elment
            d[i][j] = max(d[i-1][j], d[i-1][j-1]) + a[i][j];
        }
        d[i][1] = d[i-1][1] + a[i][1];
        d[i][i] = d[i-1][i-1] + a[i][i];
    }
    int max=0;
    for(auto i : d[n]){
        if(max < i) max = i;
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=i; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << max << endl;
    return 0;
}