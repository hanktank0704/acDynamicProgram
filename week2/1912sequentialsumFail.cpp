#include <iostream>
#include <vector>
using namespace std;
int n;
int a[100001];
vector<pair<int, int>> d;       //d[n]: start and end index of maximum sum sequence
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        a[i] += a[i-1];
    }
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    d.push_back({0,0});
    d.push_back({0,1});
    for(int i=2; i<=n; i++){
        // d[i].first = d[i-1].first;
        // d[i].second = d[i-1].second;
        int start = d[i-1].first;
        int end = d[i-1].second;
        if(a[i] - a[end] > 0){
            end = i;
        }
        // code for changing start variable

        d.push_back({start, end});
    }
    cout << endl;
    for(int i=1; i<=n; i++){
        cout << d[i].first << " " << d[i].second << ", ";
    }
    cout << endl;
    cout << a[d[n].second] - a[d[n].first] << endl;
    // 10 10 -1 -1 -30 100

    return 0;
}