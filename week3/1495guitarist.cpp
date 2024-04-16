#include <iostream>
using namespace std;
int n, s, m;
int a[51];
int d[51][1001];    //is it possible use till ith number and use j volume
int main(){
    cin >> n >> s >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    d[0][s] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){             
            d[i][j] = 0;
            int t1 = j - a[i];
            int t2 = j + a[i];
            if(t1 >= 0 && d[i-1][t1]){
                d[i][j] = 1;
            }
            if(t2 <= m && d[i-1][t2]){
                d[i][j] = 1;
            }
        }
    }
    // for(int i=1; i<=m; i++){
    //     cout << d[n][i] << " ";
    //     if(i%20 == 0) cout << endl;
    // }
    // cout << endl;
    int mx=-1;
    for(int i=m; i>=0; i--){
        if(d[n][i] > 0){
            mx = i;
            break;
        }
    }
    cout << mx;
    return 0;
}