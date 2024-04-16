#include <iostream>
using namespace std;
int n;
int a[100001];
int d[100001];      // max sequential sum including ith number
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    d[1] = a[1];
    for(int i=2; i<=n; i++){
        d[i]=a[i];
        d[i] = max(d[i], d[i-1] + a[i]);
    }
    // for(int i=1; i<=n ;i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    int max=-100000001;
    for(int i=1; i<=n ;i++){
        if(max < d[i]) max = d[i];
    }
    cout << max;
    return 0;
}
    // 10 10 -1 -1 -30 100
    // 10 20 19 18 -12 88

    // 10 10 -1 -1 -1 100
    // 10 20 19 18 17 117