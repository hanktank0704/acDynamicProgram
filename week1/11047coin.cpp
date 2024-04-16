#include <iostream>
using namespace std;
int n,k;
int a[1000001];
int d[100000001];
int main(){
    int de =100000000;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    d[0] = 0;
    for(int i=1; i<=k; i++){
        d[i] = de;
        for(int j=0; j<n; j++){
            if(i >= a[j]){
                d[i] = min(d[i-a[j]] + 1, d[i]);
            }
        }
    }
    cout << d[k] << endl;
    return 0;
}