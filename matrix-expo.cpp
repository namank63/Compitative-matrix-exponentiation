#include <bits/stdc++.h>
using namespace std;
void multiplyMatrix(int resMatrix[2][2], int b[2][2])          // 2 Matrix Multiplication function
{
    int temp[2][2];
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            temp[i][j] = 0;
            for(int k=0; k<2 ; k++)
                temp[i][j] += resMatrix[i][k] * b[k][j];
        }
    }
    for(int i=0; i<2; i++)                  // Updating the value of the constant matrix.
    {
        for(int j=0; j<2; j++)
        {
            resMatrix[i][j] = temp[i][j];
        }
    }
}
void matrixFastExpo(int resMatrix[2][2], int n, int x, int y)
{
    int constantMatrix[2][2] = {{1,1},
                                {1,0}};     // The constant matrix for the fibonacci relation.
    if(n == 0){         // return identity matrix when exponent is 0 (return 1 base case).
        resMatrix[0][0] = 1;
        resMatrix[0][1] = 0;
        resMatrix[1][0] = 0;
        resMatrix[1][1] = 1;
        return;     // End function call.
    }
    matrixFastExpo(resMatrix, n/2, x, y);
    multiplyMatrix(resMatrix,resMatrix);
    if(n % 2 != 0) multiplyMatrix(resMatrix, constantMatrix);
}

int matrixExpo(int n, int x, int y) {
    int resMatrix[2][2] = {{1,1},
                           {1,0}};     // The constant matrix for the fibonacci relation.
    if(n == 1) return y;
    if(n == 0) return x;
    matrixFastExpo(resMatrix, n-1, x, y);
    return (resMatrix[0][0] * y) + (resMatrix[0][1] * x);
}

int main()
{
    int x,y,n;
    cin >> n >> x >> y;
    cout << matrixExpo(n,x,y);
    return 0;
}
