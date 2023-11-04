/*
Program to calculate if a square is magic. A square of a 2D array is considered "magic" if the following is true: The sums of each row, each column, and each diagonal are all equal.
*/

#include <iostream>
using namespace std;

bool isMagic (int arr[][3], int m, int n){
    if (m!=n) return false;
    int rowSum[n]={0}, colSum[n]={0}, diagonalSum=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            rowSum[i] += arr[i][j];
            colSum[i] += arr[j][i];
        }
        diagonalSum += arr[i][i];
    }
    for (int i=0;i<n;i++){
        if((diagonalSum!=rowSum[i])or(diagonalSum!=colSum[i])) return false;
    } return true;
}

int main() {
    cout << "isMagic for array:\n";
    int a[3][3] = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    cout << "a: " << (isMagic(a, 3, 3)?"true":"false") << endl; //true
    int b[3][3] = {
        {1,1,2},
        {3,2,3},
        {1,4,1}
    };
    cout << "b: " << (isMagic(b, 3, 3)?"true":"false") << endl; //false
    int c[2][3] = {
        {1,1,1},
        {2,2,2}
    };
    cout << "c: " << (isMagic(c, 2, 3)?"true":"false") << endl; //false
    int d[3][3] = {
        {8,1,6},
        {3,5,7},
        {4,9,2}
    };
    cout << "d: " << (isMagic(d, 3, 3)?"true":"false") << endl; //true

    return 0;
}
