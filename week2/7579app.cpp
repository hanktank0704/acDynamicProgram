#include <iostream>
using namespace std;
int n,m;
int a[101];
int b[101];
int d[101][10001];
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }
    //d[n][c] : i 번쨰 까지 종료를 할 떄, j비용으로 확보한 메모리 바이트
    //d[i][j] = max(d[i-1][j - b[i]] + a[i], d[i-1][j] )
    // i를 포함한경우: d[i-1][j - b[i]] + a[i]
    // i를 포함하지 않은 경우: d[i-1][j]
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n * 100; j++){
            d[i][j] = d[i-1][j];
            if(j >= b[i]){
                d[i][j] = max(d[i-1][j - b[i]] + a[i], d[i-1][j] );
            }
        }
    }
    //d[n][c] : i 번쨰 까지 종료를 할 떄, j비용으로 확보한 메모리 바이트
    for(int i=0; i<= n*100; i++){
        if(d[n][i] >= m){
            cout << i ;
            break;
        }
    }
    return 0;
}