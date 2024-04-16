#include <iostream>
using namespace std;
int n;
int a[1001];
int d[1001];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            for(int x=1; x<=i/j; x++){
                if(i >= j*x && d[i] < d[i- j*x] + a[j]*x){
                    d[i] = d[i-j*x] + a[j]*x;
                }
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //         cout << d[i] << " ";
    // }
    // cout << endl;
    cout << d[n];

} 