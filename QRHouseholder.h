#pragma once

namespace Householder {
	// float precision functions
	void QRDecomposition(float* matrixA, int rows, int columns, float* matrixQ, float* matrixR);
	void QRDecomposition(float* matrixA, int rows, int columns, int lowerDiagonals, int upperDiagonals, float* matrixQ, float* matrixR);
	void BlockedQRDecomposition(float* matrixA, int rows, int columns, float* matrixQ, float* matrixR);
	void BlockedQRDecomposition(float* matrixA, int rows, int columns, int lowerDiagonals, int upperDiagonals, float* matrixQ, float* matrixR);
	// double precision functions

}