#include <iostream>
using namespace std;
int n, k;
int a[101][2];
int d[100001];  //i무게로 담을 수있는 최가합
int main(){
    cin >> n >>k;
    for(int i=1; i<=n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    for(int i=1; i<=n; i++){
        // j 무게로 담을 수있는 최대가치합
        // d[i] =  d[i-a[j][0]] + a[j][0]
        for(int j=k; j>=1; j--){
            if(j >= a[i][0]){
                d[j] = max(d[j], d[j - a[i][0]] + a[i][1]);
            }
            // if(i >= a[j][0]){
            //     d[i] = max(d[i], d[i-a[j][0]] + a[j][0]);
            // }
        }
    }
    // for(int i=1; i<=k; i++){
    //     for(int j=1; j<=n; j++){
    //         if(d)
    //     }
    // }

    // for(int i=1; i<=k; i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    cout << d[k];

    return 0;
}