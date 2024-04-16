#include <iostream>
using namespace std;
int n;
// int a[100001][4];
// int dd[100001][4];
int main(){
    cin >> n;
    int d[4] ={0,};
    int m[4] ={0,};
    int a1, a2, a3;
    for(int i=1; i<=n; i++){
        cin >> a1 >> a2 >> a3;
        int d1, d2, d3;
        int m1, m2, m3;
        d1 = max(d[1], d[2]) + a1;
        d2 = max(max(d[1], d[2]), d[3]) + a2;
        d3 = max(d[3], d[2]) + a3;

        m1 = min(m[1], m[2]) + a1;
        m2 = min(min(m[1], m[2]), m[3]) + a2;
        m3 = min(m[3], m[2]) + a3;
        d[1] = d1;
        d[2] = d2;
        d[3] = d3;
        m[1] = m1;
        m[2] = m2;
        m[3] = m3;
    }
    cout << max(max(d[1], d[2]), d[3]) << " ";
    cout << min(min(m[1], m[2]), m[3]);
    // for(int i=1; i<=n; i++){
    //     dd[i][1] = max(dd[i-1][1], dd[i-1][2]) + a[i][1];
    //     dd[i][2] = max(max(dd[i-1][1], dd[i-1][2]), dd[i-1][3]) + a[i][2];
    //     dd[i][3] = max(dd[i-1][3], dd[i-1][2]) + a[i][3];
    // }
    // cout << max(max(dd[n][1],dd[n][2]),dd[n][3]) << " ";
    // for(int i=1; i<=n; i++){
    //     dd[i][1] = min(dd[i-1][1], dd[i-1][2]) + a[i][1];
    //     dd[i][2] = min(min(dd[i-1][1], dd[i-1][2]), dd[i-1][3]) + a[i][2];
    //     dd[i][3] = min(dd[i-1][3], dd[i-1][2]) + a[i][3];
    // }

    // cout << min(min(dd[n][1],dd[n][2]),dd[n][3]) << " ";
    return 0;
}