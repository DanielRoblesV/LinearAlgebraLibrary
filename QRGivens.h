#pragma once
namespace Givens {
	// float precision functions
	void QRDecompositionAScls(float* matrixA, int rows, int columns, float* matrixQ, float* matrixR);
	void QRDecompositionAScls(float* matrixA, int rows, int columns, int lowerDiagonals, int upperDiagonals, float* matrixQ, float* matrixR);
	void QRDecompositionASrs(float* matrixA, int rows, int columns, float* matrixQ, float* matrixR);
	void QRDecompositionASrs(float* matrixA, int rows, int columns, int lowerDiagonals, int upperDiagonals, float* matrixQ, float* matrixR);
	// double precision functions
	void QRDecompositionAScls(double* matrixA, int rows, int columns, double* matrixQ, double* matrixR);
	void QRDecompositionAScls(double* matrixA, int rows, int columns, int lowerDiagonals, int upperDiagonals, double* matrixQ, double* matrixR);
	void QRDecompositionASrs(double* matrixA, int rows, int columns, double* matrixQ, double* matrixR);
	void QRDecompositionASrs(double* matrixA, int rows, int columns, int lowerDiagonals, int upperDiagonals, double* matrixQ, double* matrixR);
}