#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[11];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int ans=0;
    for(int i=n-1; i>=0; i--){
        int temp;
        temp = k/a[i];
        k -= temp*a[i];
        ans += temp;
    }
    cout << ans;
    return 0;
}