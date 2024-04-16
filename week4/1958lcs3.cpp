#include <iostream>
using namespace std;
string a;
string b;
string c;
int d[101][101][101];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> a;
    cin >> b;
    cin >> c;

    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            for(int k=1; k<=c.length(); k++){
                //d[i][j][k] = max(d[i-1][j][k]g)
            }
        }
    }

    return 0;
}