#include <iostream>
#include "cml.h"

using namespace std;

void CML::fit(Matrix A, Vector b)
{
  MatrixXd _X;
  Vector _c;
  Vector oneColumn(A.rows());
  oneColumn.fill((double)1);
  A.conservativeResize(A.rows(), A.cols()+1);
  A.col(A.cols()-1) = oneColumn;
  _X = A.transpose() * A;
  _c = A.transpose() * b; 
  _x = _X.colPivHouseholderQr().solve(_c);
}

Vector CML::coefficient(){
   return _x;
 }

 // Resolvemos sistema A^T*A*x = A^T*b
 Matrix CML::predict(Matrix A)
 { 
 Vector oneColumn(A.rows());
 oneColumn.fill((double)1);
 A.conservativeResize(A.rows(), A.cols()+1);
 A.col(A.cols()-1) = oneColumn;
  return A * _x;
 }

