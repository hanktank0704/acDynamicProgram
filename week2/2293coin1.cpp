#include <iostream>
using namespace std;
int d[10001];
int main(){
    int n,k;
    int a[101];
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    d[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j >= a[i]){
                d[j] += d[j - a[i]];
            }
        }
        for(int i=1; i<=k; i++){
            cout << d[i] << " ";
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
    for(int i=1; i<=k; i++){                 // i don't understand why this does not work!!
        //d[i]: way to express i value with coins
        //d[i] = d[i - a[j]]
        for(int j=1; j<=n; j++){
            if(i >= a[j]){
                d[i] += d[i-a[j]];
            }
            for(int i=1; i<=k; i++){
                cout << d[i] << " ";
            }
            cout << endl;
        }
    }
    // for(int i=1; i<=k; i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    cout << d[k];
    return 0;
}