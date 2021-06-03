#include "ass2/invert_mat.hh"
#include<bits/stdc++.h>
using namespace std;
#define N 5
#include <iostream>
#include "debug/MATRIX.hh"
#include "debug/RESULT.hh"

void getCfactor(int M[N][N], int t[N][N], int p, int q, int n) {
   int i = 0, j = 0;
   for (int r= 0; r< n; r++) {
      for (int c = 0; c< n; c++){ //Copy only those elements which are not in given row r and column c: {
         if (r != p && c != q) { 
            t[i][j++] = M[r][c]; //If row is filled increase r index and reset c index
            if (j == n - 1) {
               j = 0; i++;

            }
         }
      }
   }
}
int DET(int M[N][N], int n){
   int D = 0;
   if (n == 1)
      return M[0][0];
   int t[N][N]; //store cofactors
   int s = 1; 
   for (int f = 0;f<n;f++) {
      //For Getting Cofactor of M[0][f] do 
      getCfactor(M, t, 0, f, n); 
      D += s * M[0][f] * DET(t, n - 1);
      s = -s;
   }
   return D;
}
void ADJ(int M[N][N],int adj[N][N]){
//to find adjoint matrix {
   if (N == 1) {
      adj[0][0] = 1; 
      return;
   }
   int s = 1,t[N][N];
   for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
         //To get cofactor of M[i][j]
         getCfactor(M, t, i, j, N);
         s = ((i+j)%2==0)? 1: -1; //sign of adj[j][i] positive if sum of row and column indexes is even.
         adj[j][i] = (s)*(DET(t, N-1)); //Interchange rows and columns to get the transpose of the cofactor matrix
      }
   }
}
bool INV(int M[N][N], float inv[N][N]) {
   int det = DET(M, N);
   if (det == 0) {
      cout << "";
      return false;
   }
   int adj[N][N]; 
   ADJ(M, adj);
   for (int i=0; i<N; i++){
      for (int j=0; j<N; j++) {
         inv[i][j] = adj[i][j]/float(det);
      }
   }
   return true;
}

InvertMat::InvertMat(InvertMatParams *params) :
    SimObject(params)
{
	int M[5][5] = {
      {1, 2, 3, 4,-2}, 
      {-5, 6, 7, 8, 4}, 
      {9, 10, -11, 12, 1}, 
      {13, -14, -15, 0, 9}, 
      {20 , -26 , 16 , -17 , 25}
  	};
   float inv[5][5];
   DPRINTF(MATRIX,"Size of the input matrix is : 5 X 5");
   DPRINTF(MATRIX,"INPUT MATRIX is: \n");
   for (int i=0; i<N; i++) 
	{ 
		for (int j=0; j<N; j++){ 
			
			DPRINTF(MATRIX,"%d ",M[i][j]);
		}	
		DPRINTF(MATRIX,"\n"); 
	} 
	if(INV(M,inv)){
		DPRINTF(RESULT,"RESULTANT MATRIX is: \n");
		for (int i=0; i<N; i++) 
		{ 
			for (int j=0; j<N; j++){
				
				DPRINTF(RESULT,"%f",inv[i][j]);
			}
			DPRINTF(RESULT,"\n"); 
		}
	}
}
InvertMat*
InvertMatParams::create()
{
    return new InvertMat(this);
}
