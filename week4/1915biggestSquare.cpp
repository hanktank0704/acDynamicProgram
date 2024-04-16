#include <iostream>
using namespace std;
int n,m;
char b[1001][1001];
int a[1001][1001];
int d[1001][1001];
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> b[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(b[i][j] == '1') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            d[i][j] = d[i-1][j-1];
            d[i][j] = max(d[i][j-1], d[i][j]);
            d[i][j] = max(d[i-1][j], d[i][j]);
            // if(a[i][j] == 1){
            //     d[i][j] = 1;
            // }
            // 3, 1
            int index = 1;
            int x = d[i][j] + 1;
            for(int k=0; k<x; k++){
                if(a[i - k][j] != 1){
                    index = 0;
                    break;
                }
            }
            for(int k=0; k<x; k++){
                if(a[i][j - k] != 1){
                    index = 0;
                    break;
                }
            }
            if(index == 1){
                d[i][j] = max(d[i][j], d[i-1][j-1] + 1);
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << d[n][m] * d[n][m];
    return 0;
}