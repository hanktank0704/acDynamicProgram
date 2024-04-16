#include <iostream>
using namespace std;
int n, k;
int a[101];
int d[101][10001];
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    d[0][0] = 1;
    //d[i][j] : i 번째까지의 동전만 사용하면서 j원만큼 표현하는 방법의 가지수
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            //d[i][j] = d[i-1][j- x]
            for(int x=0; x<=j; x+=a[i]){        //
                d[i][j] += d[i-1][j - x];
            }
        }
    }
    //d[2][4] = 1111, 112, 22
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=k; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << d[n][k] << endl;
    return 0;
}