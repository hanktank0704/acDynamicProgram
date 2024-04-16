#include <iostream>
using namespace std;
int t, n;
int a[100001][3];
int d[100001][3];
int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=1; j<=n; j++){
            cin >> a[j][1];
        }
        for(int j=1; j<=n; j++){
            cin >> a[j][2];
        }
        for(int i=1; i<=n; i++){
            //d[i][j] : using ith column jth row sticker what is maximum return of sticker value
            for(int j=1; j<=2; j++){
                d[i][j] = max(d[i-1][3 - j] + a[i][j], max(d[i-1][1],d[i-1][2]));
            }
        }
        cout << max(d[n][1], d[n][2]) << endl;
    }
    return 0;
}