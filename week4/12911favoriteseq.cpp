#include<iostream>
using namespace std;
int n, m;
int mod = 1000000007;
int d[11][100001];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n>> m; 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // length is i and ends with j
            //d[i][j] = d[i-1][1] + .... d[i-1][j-1] + d[i-1][j]
            // if k % j != 0, += d[i-1][k]
        }
    } 
    return 0;
}