#include<iostream>
using namespace std;
int n;
int a[1001];
int d[1001][2]; // using ith number, 0 inrease 1 decrease
int main(){
    //1 5 2 1 4 3 4 5 2 1
    //1 2 3 4 4 4 4 5 6 7
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        // d[i][0] = if(a[i] > a[i-j]) d[i][0] = max(d[i-j] + 1, 
        // d[i][1] = if(a[i] < a[i - j)]) d[i][1] = max(d[i-j][0] + 1, d[i-j][1] + 1)
        d[i][0] = 1;
        d[i][1] = 1;
        // int d[1001][2]; // using ith number, 0 inrease 1 decrease
        for(int j=1; j<i; j++){
            if(a[i] > a[j]){
                d[i][0] = max(d[j][0] + 1, d[i][0]);
            }
            if(a[i] < a[j]){
                d[i][1] = max(max(d[j][0] + 1, d[j][1] + 1), d[i][1]);
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout << d[i][0] << " ";
    // }
    // cout << endl;
    // for(int i=1; i<=n; i++){
    //     cout << d[i][1] << " ";
    // }
    // cout << endl;
    int mx=0;
    for(int i=1; i<=n; i++){
        if(mx < max(d[i][0], d[i][1])){
            mx = max(d[i][0], d[i][1]);
        }
    }
    cout << mx;
    return 0;
}