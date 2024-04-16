#include <iostream>
using namespace std;
int t, w;
int a[1001];
int d[1001][31][3];
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t >> w;
    for(int i=1; i<=t; i++){
        cin >> a[i];
    }
    //max plum using till ith fall, moving j times, and I am in kth tree(1 or 2)
    for(int i=1; i<=t; i++){
        for(int j=1; j<=w; j++){
            for(int k=1; k<=2; k++){
                if(a[i] == k){      // plum fall where i am no need to move
                    d[i][j][k] = d[i-1][j][k] + 1;
                }
                else{               // plum fall different place, need to move
                    d[i][j][k] = d[i-1][j-1][3 - k] + 1;
                }
                //d[i][j][k] = d[i-1][j][k] + 1 if a[i] = k
                //           = if a[i] !=k, d[i][j-1][3 - k] + 1
            }
        }
    }
    cout << max(d[t][w][1], d[t][w][2]);

    return 0;
}