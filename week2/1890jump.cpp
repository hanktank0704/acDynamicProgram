#include <iostream>
using namespace std;
int n;
int a[101][101];
long long d[101][101];
int main(){
    cin >> n; 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    d[1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<n; k++){
                if(a[k][j] == i-k){
                    d[i][j] += d[k][j];
                }
                if(a[i][k] == j-k){
                    d[i][j] += d[i][k];
                }
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << d[n][n];
    return 0;
}