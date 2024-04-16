#include <iostream>
using namespace std;
int n;
int a[100001];
int d[100001][2];      //max sequential sum including ith number
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=0; i<=n; i++){
        d[i][0] = -1001;
        d[i][1] = -1001;
    }
    // d[i][0] : using till ith number longest sequential sum without deletion
    // d[i][1] : with deletion
    // d[i][1] = d[i-1][1] + a[i], d[i-1][0]
    for(int i=1; i<=n; i++){
        d[i][0] = max(a[i] , d[i-1][0] + a[i]);
        d[i][1] = max(d[i-1][1] + a[i], d[i-1][0]);
    }
    // for(int i=1; i<=n; i++){
    //     cout << d[i][0] << " ";
    // }
    // cout << endl;
    // for(int i=1; i<=n; i++){
    //     cout << d[i][1] << " ";
    // }
    // cout << endl;
    int mx=-1001;
    for(int i=1; i<=n; i++){
        if(mx < max(d[i][0], d[i][1])){
            mx = max(d[i][0], d[i][1]);
        }
    }
    cout << mx;
    cout << endl;
    return 0;
}
    // 10 10 -1 -1 -30 100
    // 10 20 19 18 -12 88

    // 10 10 -1 -1 -1 100
    // 10 20 19 18 17 117