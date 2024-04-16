#include <iostream>
using namespace std;
int t, k;
int a[101][2];
int d[101][10001];      
int main(){
    cin >> t >> k;
    for(int i=1; i<=k; i++){
        cin >> a[i][0] >> a[i][1];
    }
    //d[i][j] : d[i-1][j - a[i][0] * x]
    // x <= a[i][1]
    // 11: 10 1, 5 5 1, 
    // 20: 
    d[0][0] = 1;
    for(int i=1; i<=k; i++){
        for(int j=0; j<=t; j++){
            // i 번째의 동전까지만 사용하는 경우, j만큼의 액수를 표현하는 방법 가지수
            for(int x=0; x<= a[i][1]; x++){
                if(j >= a[i][0] * x){
                    d[i][j] += d[i-1][j - a[i][0] * x];
                }
            }
        }
    }
    // for(int i=1; i<=k; i++){
    //     for(int j=1; j<=t; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << d[k][t] << endl;
    return 0;
}