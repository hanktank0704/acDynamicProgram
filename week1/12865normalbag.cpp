#include <iostream>
using namespace std;
int n, k;
int a[101][2];
int d[101][100001];  // i무게로 담을 수 있는 최대의 가치합
int d[100001];  //i무게로 담을 수있는 최가합
int main(){
    cin >> n >>k;
    for(int i=1; i<=n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    for(int i=1; i<=n; i++){
        // i 물건까지만을 사용하면서 j무게로 담을 수 있는 최대의 가치합
        // d[i][j] = max(d[i-1][j-a[i][0]] + a[i][1], d[i-1][j])
        // d[i] = 
        for(int j=0; j<=k; j++){
            d[i][j] = d[i-1][j];
            if(j>=a[i][0]){
                d[i][j] = max(d[i-1][j-a[i][0]] + a[i][1], d[i-1][j]);
            }
        }
    }
    cout << d[n][k];

    return 0;
}