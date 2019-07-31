#pragma once

namespace MSEerror {
	double MatrixQR(float* matrixA, float* matrixQ, float* matrixR, int rowsA, int columnsA);
	double MatrixQ(float* matrixQ, int rowsQ);
	double MatrixQtA(float* matrixA, float* matrixQ, float* matrixR, int rowsA, int columnsA);
	double MatrixR(float* matrixR, int rowsR, int columnsR);
	double MatrixQR(double* matrixA, double* matrixQ, double* matrixR, int rowsA, int columnsA);
	double MatrixQ(double* matrixQ, int rowsQ);
	double MatrixQtA(double* matrixA, double* matrixQ, double* matrixR, int rowsA, int columnsA);
	double MatrixR(double* matrixR, int rowsR, int columnsR);

}