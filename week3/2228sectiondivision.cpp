#include <iostream>
using namespace std;
// bj1912 sequentail sum
int n;
int m;
int a[101];
int b[101];
int d[101][51];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        b[i] = a[i] + b[i-1];
    }
    for(int i=1; i<=n; i++){
        // cout << b[i] << " ";
    }
    cout << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            d[i][j] = -123;
        }
    }
    for(int i=1; i<=n; i++){
        //d[i][j] :sum of using ith num, using j section
        //d[i][j] = max(adding a[i] new section, adding on used section)
        //d[i][j] = max(d[i-2][j-1] + a[i], ???, d[i-1][j] + a[i])
        for(int j=1; j<=m; j++){
            d[i][j] = -32769;
            if(i==1){
                d[i][j] = a[i];
            }
            if(i >= 2 && j >= 1){
                d[i][j] = max(d[i-1][j] + a[i], d[i][j]);
                for(int k = 1; k <= i-2; k++){
                    d[i][j] = max(d[k][j-1] + a[i], d[i][j]);
                    // (i-2) i
                    // d[i-1][j] + a[i]
                }
            }

            // if(j>=1 && i>=2){
            //     for(int k=1; k<=n; k++){
            //         d[i][j] = max(d[k-2][j] + b[n] - b[i-1], d[i][j] );
            //     }
            // }
        }
    }
    for(int j=1; j<=m; j++){
        for(int i=1; i<=n; i++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int mx=0;
    for(int i=1; i<=n; i++){
        mx = max(mx, d[i][m]);
    }
    cout << mx;
    return 0;
}