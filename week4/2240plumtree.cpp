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
    //max plum using till ith fall, moving j times, and ends in  kth tree(1 or 2)
    for(int i=1; i<=t; i++){
        for(int j=0; j<=w; j++){
            if(j==0){
                d[i][j][1] = d[i-1][j][1] ;
                if(a[i] == 1){
                    d[i][j][1] = d[i-1][j][1] + 1;
                }
                continue;
            }
            if(a[i] == 1){
                d[i][j][1] = max(d[i-1][j][1] + 1, d[i-1][j-1][2] + 1);
                d[i][j][2] = d[i-1][j][2];
            }
            if(a[i] == 2){
                d[i][j][1] = d[i-1][j][1];
                d[i][j][2] = max(d[i-1][j][2] + 1, d[i-1][j-1][1] + 1);
            }
            // for(int k=1; k<=2; k++){
            //     if(a[i] == k){      // plum fall where i am no need to move
            //         d[i][j][k] = max(d[i-1][j][k] + 1, d[i-1][j-1][3-k] + 1);

            //     }
            //     else{               // plum fall different place, need to move
            //         d[i][j][k] = max(d[i-1][j][k], d[i-1][j-1][3-k]);
            //     }
            // }
        }
    }
    // for(int i=1; i<=t; i++){
    //     cout << "i is " << i << endl;
    //     for(int j=0; j<=w; j++){
    //         cout << d[i][j][1] << " " << d[i][j][2] << endl;
    //     }
    //     cout << endl;
    // }

    cout << max(d[t][w][1], d[t][w][2]);

    return 0;
}