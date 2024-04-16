#include <iostream>
#include <cmath>
using namespace std;
int a[1001];
int d[1001];
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    d[1] = 0;
    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            if(d[i] < d[j] + abs(a[i] - a[j+1])){
                d[i] = d[j] + abs(a[i] - a[j+1]);
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    cout << d[n];
    return 0;
}