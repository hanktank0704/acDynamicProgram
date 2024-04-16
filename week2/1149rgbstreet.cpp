#include <iostream>
using namespace std;
int n;
int p[1001][3];
int d[1001][3];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    for(int i=1; i<=n; i++){
        // cost of painting till i th house, when house i is colored with j 0:red, 1:blue, 2: green
        d[i][0] = min(d[i-1][1], d[i-1][2]) + p[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + p[i][1];
        d[i][2] = min(d[i-1][1], d[i-1][0]) + p[i][2];
    }
    cout << min(min(d[n][0], d[n][1]), d[n][2]);

    return 0;
}