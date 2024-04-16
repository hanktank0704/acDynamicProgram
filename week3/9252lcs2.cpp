#include <iostream>
#include <vector>
#include <string>
using namespace std;
string a;
string b;
int d[1001][1001]; 
int r[1001][1001]; 
//max length when using until ith in string a, jth in string b
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> a >> b;
    char temp = 'x';
    a = temp + a;
    b = temp + b;
    int al = a.size();
    int bl = b.size();
    vector <char> v;
    for(int i=1; i<al; i++){
        for(int j=1; j<bl; j++){
            //d[i][j]  if(a[i] == b[j]) = d[i][j-1] + 1
            d[i][j] = max(d[i][j-1], d[i-1][j]);
            if(a[i] == b[j]){
                // d[i][j] = max(max(d[i][j], d[i-1][j-1] + 1), d[i-1][j]);
                d[i][j] = max(d[i][j], d[i-1][j-1] + 1);
                // if(d[i][j] == d[i-1][j-1] + 1){
                //     v.push_back(a[i-1]);
                // }
                // else{
                // }
            }
        }
    }
    int x= al-1;
    int y= bl-1;
    while(x >= 1 && y >= 1){
        if(d[x][y] > d[x-1][y] && d[x][y] > d[x-1][y-1] && d[x][y] > d[x][y-1]){
            v.push_back(a[x]);
            x--;
            y--;
        }
        else if(d[x][y] > d[x-1][y] && d[x][y] == d[x][y-1]){
            y--;
        }
        else{
            x--;
        }
    }
    cout << d[al-1][bl-1];
    cout << endl;
    for(int i=v.size() -1; i>=0; i--){
        cout << v[i] ;
    }
    return 0;
}
// ACAYKP
// CAPCAK
// ABCDEF
// JAKBCK