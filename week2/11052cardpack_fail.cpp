#include <iostream>
using namespace std;
int n;
int a[1001];
int d[1001][1001];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            //total money while using untill ith card and number of card is j
            //so ugly help
            for(int k=1; k<=n; k++){
                for(int x=0; x<=j/k; x++){
                    if(i>=k && j >= k*x && d[i][j] < d[i-k][j-k * x] + a[k] * x){
                        d[i][j] = d[i-k][j-k] + a[k]*x;
                    }
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

}