
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
 
const int MAX = 100;
 
void LU(double A[][MAX], int n)
{
    double L[n][n], U[n][n];
    memset(L, 0, sizeof(L));
    memset(U, 0, sizeof(U));
 
 
    for (int i = 0; i < n; i++)
    {
        
        for (int k = i; k < n; k++)
        {
          
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
 
       
            U[i][k] = A[i][k] - sum;
        }
 
        
        for (int k = i; k < n; k++)
        {
            if (i == k)
                L[i][i] = 1; 
            else
            {
              
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);
 
             
                L[k][i]
                    = (A[k][i] - sum) / U[i][i];
            }
        }
       cout << setw(6)
         << "      L"
         << setw(32)
         << "U" << endl;
 
   
    for (int i = 0; i < n; i++)
    {
       
        for (int j = 0; j < n; j++)
            cout << setw(6) << L[i][j] << "\t";
        cout << "\t";
 
    
        for (int j = 0; j < n; j++)
            cout << setw(6) << U[i][j] << "\t";
        cout << endl;
    }
}
   


int main()
{
   double A[][MAX]
       = { { 60, 30, 20 }, { 30,20,15}, { 20,15,12} };

// double A[][MAX]
  //      = { { 3,0,1 }, { 0,-1,3}, { 1,3,0} };
 
   //double A[][MAX]
   //     = { { 2, 1,-2 }, { 4,2,-1}, { 6,3,11} };
 
    LU(A, 3);
    return 0;
}
