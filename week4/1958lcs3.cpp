#include <iostream>
using namespace std;
string a;
string b;
string c;
int d[101][101][101];
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> a;
    cin >> b;
    cin >> c;
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    int al = a.length();
    int bl = b.length();
    int cl = c.length();

    for(int i=1; i<a.length(); i++){
        for(int j=1; j<b.length(); j++){
            for(int k=1; k<c.length(); k++){
                //d[i][j][k] = max(d[i-1][j][k]g)
                if(a[i] == b[j] && b[j] == c[k]){
                    d[i][j][k] = d[i-1][j-1][k-1] + 1;
                }
                else{
                    d[i][j][k] = max(max(d[i-1][j][k], d[i][j-1][k]), d[i][j][k-1]);
                }
            }
        }
    }
    // for(int i=1; i<al; i++){
    //     cout << "i is " << i << endl;
    //     for(int j=1; j<bl; j++){
    //         for(int k=1; k<cl; k++){
    //             cout << d[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // cout << cl << endl;
    cout << d[al-1][bl-1][cl-1];

    return 0;
}