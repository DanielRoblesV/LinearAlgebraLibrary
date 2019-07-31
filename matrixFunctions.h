#pragma once
namespace matrixFunctions {
	// double precision functions
	void Print2DarrayColumnMajor(float* matrix, int const rows, int const columns);
	void Print2DarrayRowMajor(float* matrix, int const rows, int const columns);
	void FillMatrix(float* matrix, int rows, int columns, float value);
	void FillRandMatrixColumnMajor(float* matrix, int rows, int columns);
	void FillRandMatrixRowMajor(float* matrix, int rows, int columns);
	void FillIdentityMatrixColumnMajor(float* matrix, int rows);
	void FillIdentityMatrixRowMajor(float* matrix, int rows);
	double matrixMSE(float* matrixA, float* matrixB, int rows, int columns);
	void matrixMulTransA(float* matrixA, float* matrixB, float* matrixC, int rowsA, int columnsA, int columnsB);
	void matrixMul(float* matrixA, float* matrixB, float* matrixC, int rowsA, int columnsA, int columnsB);
	void matrixMultiplicacionRowMajor(float* matrixA, float* matrixB, float* matrixC, int rowsA, int columnsA, int columnsB);
	void matrixMultiplicacionColumnMajor(float* matrixA, float* matrixB, float* matrixC, int rowsA, int columnsA, int columnsB);
	void matrixConvertToRowMajor(float* matrix, int rows, int columns);
	void matrixConvertToColumnMajor(float* matrix, int rows, int columns);
	void FillBandedRandMatrixRowMajor(float* matrix, int rows, int columns, int lowerDiagonals, int upperDiagonals);
	void FillBandedRandMatrixColumnMajor(float* matrix, int rows, int columns, int lowerDiagonals, int upperDiagonals);
	void CopyMatrix(float* matrixIn, float* matrixOut, int rows, int columns);
	// double precision functions
	void Print2DarrayColumnMajor(double* matrix, int const rows, int const columns);
	void Print2DarrayRowMajor(double* matriz, int const rows, int const columns);
	void FillMatrix(double* matrix, int rows, int columns, double value);
	void FillRandMatrixColumnMajor(double* matrix, int rows, int columns);
	void FillRandMatrixRowMajor(double* matrix, int rows, int columns);
	void FillIdentityMatrixColumnMajor(double* matrix, int rows);
	void FillIdentityMatrixRowMajor(double* matrix, int rows);
	double matrixMSE(double* matrixA, double* matrixB, int rows, int columns);
	void matrixMulTransA(double* matrixA, double* matrixB, double* matrixC, int rowsA, int columnsA, int columnsB);
	void matrixMul(double* matrixA, double* matrixB, double* matrixC, int rowsA, int columnsA, int columnsB);
	void matrixConvertToRowMajor(double* matrix, int rows, int columns);
	void matrixConvertToColumnMajor(double* matrix, int rows, int columns);
	void FillBandedRandMatrixRowMajor(double* matrix, int rows, int columns, int lowerDiagonals, int upperDiagonals);
	void FillBandedRandMatrixColumnMajor(double* matrix, int rows, int columns, int lowerDiagonals, int upperDiagonals);
}
