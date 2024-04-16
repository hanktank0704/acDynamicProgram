#include <iostream>
#include <vector>
using namespace std;
int n;
// int d[101][101];
long long d[101];
vector <pair<int, int>> v;
int main(){
    cin >> n;
    //1. +1, 2. 3. 4. *x
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    d[4] = 4;
    for(int i=4; i<=n; i++){
        d[i] = d[i-1]+1;
        //d[i][j]: press button i times and press ca for first time at j
        // 
        // ca -> cc -> cv  *2
        // cv -> cv -> cv  
        //d[i]: max buffer = d[i-2]
        // d[i] = max(d[i-3] * 2, d[i-3]+3, d[i-3]);
        for(int j=1; j<i; j++){
            d[i] = max(d[i], d[j] * (i - j - 1));
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    cout << d[n];
    return 0;
}