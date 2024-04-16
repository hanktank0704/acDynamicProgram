#include <iostream>
using namespace std;
int n, m, k;
int a,b,c;
int v[100001][4];
int d[301][301];        
int r[301][301];
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for(int i=1; i<=k; i++){
        cin >> v[i][1] >> v[i][2] >> v[i][3];
        a=v[i][1];
        b=v[i][2];
        c=v[i][3];
        r[a][b] = max(r[a][b], c);
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            d[i][j] = -1;
        }
    }
    d[1][1] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            //end i, visited m cities
            //d[i][j] = d[i-1][j-1] + price[i]
            for(int x=1; x<=i; x++){
                if(r[x][i] != 0){ // x=1, i=2, j=1
                    if(d[x][j-1] != -1){
                        d[i][j] = max(d[i][j], d[x][j-1] + r[x][i]);
                    }
                    // d21 = d10 + r12
                }
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << r[i][j] << " ";
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
    int mx=0;
    for(int i=1; i<=m; i++){
        mx = max(mx, d[n][i]);
    }
    cout << mx <<endl;
    return 0;
}