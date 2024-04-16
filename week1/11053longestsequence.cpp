#include <iostream>
using namespace std;
int n;
int a[1001]={0,};
int d[1001]={0,};
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    d[1] = 1;
    for(int i=2; i<=n; i++){
        d[i] = 1;
        for(int j=1; j<i; j++){
            if(a[i] > a[j]){
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     cout << d[i+1] << " ";
    // }
    // cout << endl;
    int mx=0;
    for(int i=1; i<=n; i++){
        mx = max(mx, d[i]);
    }
    cout << mx;
}