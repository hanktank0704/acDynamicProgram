#include<iostream>
using namespace std;
int n;
int a[100001];
int d[100001][2];
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        d[i][0] = -1001;
        d[i][1] = -1001;
    }
    for(int i=1; i<=n; i++){
        d[i][0] = max(d[i-1][0] + a[i], a[i]);
        d[i][1] = max(d[i-1][1] + a[i], d[i-1][0]);
    }
    // for(int i=1; i<=n; i++){
    //     cout << d[i][0] << " ";
    // }
    // cout << endl;
    // for(int i=1; i<=n; i++){
    //     cout << d[i][1] << " ";
    // }
    int mx=0;
    for(int i=1; i<=n; i++){
        if(mx < max(d[i][0], d[i][1])){
            mx = max(d[i][0], d[i][1]);
        }
    }
    // cout << endl;
    cout << mx;
    return 0;
}