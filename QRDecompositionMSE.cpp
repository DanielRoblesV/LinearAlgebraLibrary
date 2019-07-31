#include "QRDecompositionMSE.h"
#include "matrixFunctions.h"
using namespace matrixFunctions;
namespace MSEerror {
	// mean square error of A and Q*R, A = Q*R
	double MatrixQR(float* matrixA, float* matrixQ, float* matrixR, int rowsA, int columnsA) {
		int size = rowsA * columnsA;
		double mse;
		float* matrixQR;
		matrixQR = new float[size];
		matrixMul(matrixQ, matrixR, matrixQR, rowsA, rowsA, columnsA); // matrixQR = matrixQ*matrixR
		mse = matrixMSE(matrixQR, matrixA, rowsA, columnsA);		   // matrixA = matrixQR
		delete[] matrixQR;
		return mse;
	}
	// mean square error of A and Q*R, A = Q*R
	double MatrixQR(double* matrixA, double* matrixQ, double* matrixR, int rowsA, int columnsA) {
		int size = rowsA * columnsA;
		double mse;
		double* matrixQR;
		matrixQR = new double[size];
		matrixMul(matrixQ, matrixR, matrixQR, rowsA, rowsA, columnsA); // matrixQR = matrixQ*matrixR
		mse = matrixMSE(matrixQR, matrixA, rowsA, columnsA);		   // matrixA = matrixQR
		delete[] matrixQR;
		return mse;
	}
	// mean square error of the orthogonality of matrix Q,  Q'Q = I
	double MatrixQ(float* matrixQ, int rowsQ) {
		double mse;
		int size = rowsQ * rowsQ;
		float* matrixQtQ;
		float* matrixI;
		matrixQtQ = new float[size];
		matrixI = new float[size];
		FillIdentityMatrixColumnMajor(matrixI, rowsQ);
		matrixMulTransA(matrixQ, matrixQ, matrixQtQ, rowsQ, rowsQ, rowsQ);		// matrixQtQ = matrixQ'*matrixQ 
		mse = matrixMSE(matrixQtQ, matrixI, rowsQ, rowsQ);						// matrixQtQ = matrixI
		delete[] matrixQtQ;
		delete[] matrixI;
		return mse;
	}
	// mean square error of the orthogonality of matrix Q,  Q'Q = I
	double MatrixQ(double* matrixQ, int rowsQ) {
		double mse;
		int size = rowsQ * rowsQ;
		double* matrixQtQ; double* matrixI;
		matrixQtQ = new double[size];
		matrixI = new double[size];
		FillIdentityMatrixColumnMajor(matrixI, rowsQ);
		matrixMulTransA(matrixQ, matrixQ, matrixQtQ, rowsQ, rowsQ, rowsQ);		// matrixQtQ = matrixQ'*matrixQ 
		mse = matrixMSE(matrixQtQ, matrixI, rowsQ, rowsQ);						// matrixQtQ = matrixI
		delete[] matrixQtQ;
		delete[] matrixI;
		return mse;
	}
	// mean square error of matrix R and Q'*A, R = Q'*A
	double MatrixQtA(float* matrixA, float* matrixQ, float* matrixR, int rowsA, int columnsA) {
		double mse = 0;
		int size = rowsA * columnsA;
		float* matrixQtA;
		matrixQtA = new float[size];
		matrixMulTransA(matrixQ, matrixA, matrixQtA, rowsA, rowsA, columnsA);  // matrixQtA = matrixQ'*A
		mse = matrixMSE(matrixQtA, matrixR, rowsA, columnsA);				   // matrixQtA = matrixR
		delete[] matrixQtA;
		return mse;
	}
	// mean square error of matrix R and Q'*A, R = Q'*A
	double MatrixQtA(double* matrixA, double* matrixQ, double* matrixR, int rowsA, int columnsA) {
		double mse = 0;
		int size = rowsA * columnsA;
		double* matrixQtA;
		matrixQtA = new double[size];
		matrixMulTransA(matrixQ, matrixA, matrixQtA, rowsA, rowsA, columnsA);  // matrixQtA = matrixQ'*A
		mse = matrixMSE(matrixQtA, matrixR, rowsA, columnsA);				   // matrixQtA = matrixR
		delete[] matrixQtA;
		return mse;
	}
	// mean square error of matrix R, must be upper triangular
	double MatrixR(float* matrixR, int rowsR, int columnsR) {
		double mse = 0;
		double temporalValue = 0;
		unsigned int zeroElements = 0;
		for (int i = 0; i < rowsR; i++) {
			for (int j = 0; j < columnsR; j++) {
				if (j < i) {
					temporalValue = 0 - (double)matrixR[i + j * rowsR];
					temporalValue = temporalValue * temporalValue;
					mse = mse + temporalValue;
					zeroElements++;
				}
			}
		}
		mse = mse / zeroElements;
		return mse;
	}
	// mean square error of matrix R, must be upper triangular
	double MatrixR(double* matrixR, int rowsR, int columnsR) {
		double mse = 0;
		double temporalValue = 0;
		unsigned int zeroElements = 0;
		for (int i = 0; i < rowsR; i++) {
			for (int j = 0; j < columnsR; j++) {
				if (j < i) {
					temporalValue = 0 - matrixR[i + j * rowsR];
					temporalValue = temporalValue * temporalValue;
					mse = mse + temporalValue;
					zeroElements++;
				}
			}
		}
		mse = mse / zeroElements;
		return mse;
	}
}

