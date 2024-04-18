#include <iostream>
using namespace std;
int n;
int a[1500001][2];
int d[1500001];  //max money using i number 
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    int temp=0;
    for(int i=1; i<=n; i++){
        d[i] = max(d[i], d[i-1]);           //****
        if(i + a[i][0] - 1 <= n){
            // d[i] = d[i] + a[i][1];
            d[i + a[i][0] - 1] = max(d[i-1] + a[i][1], d[i + a[i][0] - 1]);
            //need to change every d[] after i + a[i][0] without for loop
        }
        temp = max(temp, d[i]);
    }
    int mx=0;
    for(int i=1; i<=n; i++){
        mx = max(mx, d[i]);
        // cout << d[i] << " ";
    }
    // cout << endl;
    cout << mx;
    cout << endl;
    return 0;
}