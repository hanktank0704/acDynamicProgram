#include <iostream>
using namespace std;
int n;
int d[12];
int main(){
    int T;
    cin >> T;
    d[1] = 1;
    d[0] = 1;
    for(int i=0; i<T; i++){
        cin >> n;
        for(int j=2; j<=n; j++){
            d[j] = d[j-1] + d[j-2] + d[j-3];
        }
        // for(int j=1; j<=n; j++){
        //     cout << d[j] << " ";
        // }
        // cout << endl;
        cout << d[n] << endl;
    }
    return 0;
}