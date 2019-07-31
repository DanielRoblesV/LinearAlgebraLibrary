#include "QRGivens.h"
#include <algorithm>
#include <iostream>

namespace Givens {
	// Computes the QR decomposition of matrixA using Givens rotations, using the classical annihilation squeme
	void QRDecompositionAScls(float* matrixA, int rows, int columns, float* matrixQ, float* matrixR) {
		float a, b, c, s, r;
		for (int k = 0; k < std::min(rows - 1, columns); k++) {
			for (int i = rows - 1; i >= k + 1; i--) {
				b = matrixR[i * columns + k];
				if (b != 0.0f) {
					a = matrixR[(i - 1) * columns + k];
					r = 1.0f / sqrt(a * a + b * b);
					c = a * r;
					s = b * r;
					for (int j = k; j < columns; j++) {
						a = matrixR[(i - 1) * columns + j];
						b = matrixR[(i)* columns + j];
						matrixR[(i - 1) * columns + j] = c * a + s * b;
						matrixR[(i)* columns + j] = -s * a + c * b;
					}
					for (int l = i - k - 1; l < rows; l++) {
						a = matrixQ[(i - 1) + l * rows];
						b = matrixQ[(i)+l * rows];
						matrixQ[(i - 1) + l * rows] = c * a + s * b;
						matrixQ[(i)+l * rows] = -s * a + c * b;
					}
				}
			}
		}
	}
	// Computes the QR decomposition of banded matrix A using Givens rotations, using the classical annihilation squeme
	void QRDecompositionAScls(float* matrixA, int rows, int columns, int lowerDiagonals, int upperDiagonals, float* matrixQ, float* matrixR) {
		float a, b, c, s, r;
		for (int k = 0; k < std::min(rows - 1, columns); k++) {
			for (int i = std::min(rows, k+lowerDiagonals); i >= k + 1; i--) {
				b = matrixR[i * columns + k];
				if (b != 0.0f) {
					a = matrixR[(i - 1) * columns + k];
					r = 1.0f / sqrt(a * a + b * b);
					c = a * r;
					s = b * r;
					for (int j = k; j < std::min(std::min(columns,rows+upperDiagonals), k + lowerDiagonals + upperDiagonals); j++) {
						a = matrixR[(i - 1) * columns + j];
						b = matrixR[(i)* columns + j];
						matrixR[(i - 1) * columns + j] = c * a + s * b;
						matrixR[(i)* columns + j] = -s * a + c * b;
					}
					for (int l = i - k - 1; l < std::min(rows, k+lowerDiagonals); l++) {
						a = matrixQ[(i - 1) + l * rows];
						b = matrixQ[(i)+l * rows];
						matrixQ[(i - 1) + l * rows] = c * a + s * b;
						matrixQ[(i)+l * rows] = -s * a + c * b;
					}
				}
			}
		}
	}
	// Computes the QR decomposition of matrixA using Givens rotations, using the Routh annihilation squeme
	void QRDecompositionASrs(float* matrixA, int rows, int columns, float* matrixQ, float* matrixR) {
		float a, b, c, s, r;
		for (int k = 0; k < std::min(rows - 1, columns); k++) {
			for (int i = k+1; i < rows; i++) {
				b = matrixR[i * columns + k];
				if (b != 0.0f) {
					a = matrixR[k * columns + k];
					r = 1.0f / sqrt(a * a + b * b);
					c = a * r;
					s = b * r;
					for (int j = k; j < columns; j++) {
						a = matrixR[k * columns + j];
						b = matrixR[i * columns + j];
						matrixR[k * columns + j] =  c * a + s * b;
						matrixR[i * columns + j] = -s * a + c * b;
					}
					for (int l = 0; l <= i; l++) {
						a = matrixQ[l * rows + k ];
						b = matrixQ[l * rows + i];
						matrixQ[l * rows + k] =  c * a + s * b;
						matrixQ[l * rows + i] = -s * a + c * b;
					}
				}
			}
		}
	}
	// Computes the QR decomposition of banded matrix A using Givens rotations, obtaining matrices: matrixR and matrixQ
	void QRDecompositionASrs(float* matrixA, int rows, int columns, int lowerDiagonals, int upperDiagonals, float* matrixQ, float* matrixR) {
		float a, b, c, s, r;
		for (int k = 0; k < std::min(rows - 1, columns); k++) {
			for (int i = k+1; i < std::min(rows, k + lowerDiagonals); i++) {
				b = matrixR[i * columns + k];
				if (b != 0.0f) {
					a = matrixR[k * columns + k];
					r = 1.0f / sqrt(a * a + b * b);
					c = a * r;
					s = b * r;
					for (int j = k; j < std::min(columns, upperDiagonals + i); j++) {
						a = matrixR[k * columns + j];
						b = matrixR[i * columns + j];
						matrixR[k * columns + j] = c * a + s * b;
						matrixR[i * columns + j] = -s * a + c * b;
					}
					for (int l = 0; l <= i; l++) {
						a = matrixQ[l * rows + k];
						b = matrixQ[l * rows + i];
						matrixQ[l * rows + k] = c * a + s * b;
						matrixQ[l * rows + i] = -s * a + c * b;
					}
				}
			}
		}
	}
}