#include <iostream>
using namespace std;
int n, m;
int s, e;
int a[2001];
int d[2001][2001];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i=1; i<n; i++){
        d[i][i] = 1;
        if(a[i] == a[i+1]){
            d[i][i+1] = 1;
        }
    }
    d[n][n] = 1;
    for(int i=n; i>=1; i--){
        for(int j=i+1; j<=n; j++){
            // whether i to j is a palindrome
            // if d[i+1][j-1] is palindrome && a[i] = a[j]
            // if(d[i+1][j] == 1 || d[i][j-1] == 1){
            //     d[i][j] = 0;
            // }
            if(d[i+1][j-1] == 1 && a[i] == a[j]){
                d[i][j] = 1;
            }
        }
    }
    for(int j=1; j<=m; j++){
        cin >> s >> e;
        cout << d[s][e] << '\n';
    }

    return 0;
}