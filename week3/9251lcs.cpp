#include <iostream>
#include <string>
using namespace std;
string a;
string b;
int d[1001][1001]; 
//max length when using until ith in string a, jth in string b
int main(){
    cin >> a >> b;
    char temp = 'x';
    a = temp + a;
    b = temp + b;
    int al = a.size();
    int bl = b.size();
    for(int i=1; i<al; i++){
        for(int j=1; j<bl; j++){
            //d[i][j]  if(a[i] == b[j]) = d[i][j-1] + 1
            d[i][j] = max(d[i][j-1], d[i-1][j]);
            if(a[i] == b[j]){
                // d[i][j] = max(max(d[i][j], d[i-1][j-1] + 1), d[i-1][j]);
                d[i][j] = max(d[i][j], d[i-1][j-1] + 1);
            }
        }
    }
    // for(int i=1; i<al; i++){
    //     for(int j=1; j<bl; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << d[al-1][bl-1];
    return 0;
}