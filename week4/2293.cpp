#include <iostream>
using namespace std;
int n;
int k;
int a[101];
int d[10001];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    // how to express i value with coins
    d[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j - a[i] >= 0){
                d[j] += d[j - a[i]];
            }
        }
    }
    // for(int i=1; i<=k; i++){
    //     for(int j=1; j<=n; j++){
    //         if(i >= a[j]){
    //             d[i] += d[i - a[j]];
    //         }
    //     }
    // }
    for(int i=1; i<=k; i++){
        cout << d[i] << " ";
    }
    cout << endl;
    cout << d[k];
    return 0;
}
// 10
// 1*10, 11111111 2, 111111 22, 11111 5