#include "matrixFunctions.h"
#include <iostream>
#include <algorithm>

namespace matrixFunctions {
	// Print an array in matricial form using column-major order
	void Print2DarrayColumnMajor(float* matrix, int const rows, int const columns) {
		int numElements = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << matrix[i + j * rows] << "["<< numElements <<"]\t";
				numElements++;
			}
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
	// Print an array in matricial form using column-major order
	void Print2DarrayColumnMajor(double* matrix, int const rows, int const columns) {
		int numElements = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << matrix[i + j * rows] << "[" << numElements << "]\t";
				numElements++;
			}
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
	// Print an array in matricial form using row-major order
	void Print2DarrayRowMajor(float* matrix, int const rows, int const columns) {
		int numElements = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << matrix[j + i * columns] << "[" << numElements << "]\t";
				numElements++;
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
	// Print an array in matricial form using row-major order
	void Print2DarrayRowMajor(double* matrix, int const rows, int const columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << matrix[j + i * columns] << "\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
	// Fill matrix with all elements equal to a given value
	void FillMatrix(float* matrix, int rows, int columns, float value) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i + j * rows] = value;
			}
		}
	}
	// Fill matrix with all elements equal to a given value
	void FillMatrix(double* matrix, int rows, int columns, double value) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i + j * rows] = value;
			}
		}
	}
	//Fill matrix with integer random numbers in column-major order
	void FillRandMatrixColumnMajor(float* matrix, int rows, int columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i + j * rows] = (float)rand();
			}
		}
	}
	//Fill matrix with integer random numbers in column-major order
	void FillRandMatrixColumnMajor(double* matrix, int rows, int columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i + j * rows] = (float)rand();
			}
		}
	}
	//Fill matrix with random numbers in row-major order
	void FillRandMatrixRowMajor(float* matrix, int rows, int columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[j + i * columns] = (float)rand();
			}
		}
	}
	//Fill matrix with integer random numbers in row-major order
	void FillRandMatrixRowMajor(double* matrix, int rows, int columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[j + i * columns] = (float)rand();
			}
		}
	}
	//Fill matrix with the identity matrix in column-major order 
	void FillIdentityMatrixColumnMajor(float* matrix, int rows) {
		int size = rows * rows;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				if (i == j) {
					matrix[i + j * rows] = 1;
				}
				else {
					matrix[i + j * rows] = 0;
				}
			}
		}
	}
	//Fill matrix with the identity matrix in column-major order 
	void FillIdentityMatrixColumnMajor(double* matrix, int rows) {
		int size = rows * rows;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				if (i == j) {
					matrix[i + j * rows] = 1;
				}
				else {
					matrix[i + j * rows] = 0;
				}
			}
		}
	}
	//Fill matrix with the identity matrix in row-major order
	void FillIdentityMatrixRowMajor(float* matrix, int rows) {
		int size = rows * rows;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				if (i == j) {
					matrix[j + i * rows] = 1;
				}
				else {
					matrix[j + i * rows] = 0;
				}
			}
		}
	}
	//Fill matrix with the identity matrix in row-major order
	void FillIdentityMatrixRowMajor(double* matrix, int rows) {
		int size = rows * rows;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				if (i == j) {
					matrix[j + i * rows] = 1;
				}
				else {
					matrix[j + i * rows] = 0;
				}
			}
		}
	}
	//mean squared error (MSE) of matrixA and matrixB
	double matrixMSE(float* matrixA, float* matrixB, int rows, int columns) {
		double mse = 0, temporalValue = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temporalValue = (double)matrixA[i + j * rows] - matrixB[i + j * rows];
				temporalValue = temporalValue * temporalValue;
				mse = mse + temporalValue;
			}
		}
		mse = mse / ((double)rows * columns);
		return mse;
	}
	//mean squared error (MSE) of matrixA and matrixB
	double matrixMSE(double* matrixA, double* matrixB, int rows, int columns) {
		double mse = 0, temporalValue = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temporalValue = matrixA[i + j * rows] - matrixB[i + j * rows];
				temporalValue = temporalValue * temporalValue;
				mse = mse + temporalValue;
			}
		}
		mse = mse / ((double)rows * columns);
		return mse;
	}
	//Matrix multiplication of the transpose of matrixA with matrixB, Operation C = A'*B
	void matrixMulTransA(float* matrixA, float* matrixB, float* matrixC, int rowsA, int columnsA, int columnsB) {
		for (int i = 0; i < rowsA; i++) {
			for (int j = 0; j < columnsB; j++) {
				matrixC[i + j * rowsA] = 0;
				for (int k = 0; k < columnsA; k++) {
					matrixC[i + j * rowsA] = matrixC[i + j * rowsA] + matrixA[k + i * columnsA] * matrixB[k + j * columnsA];
				}
			}
		}
	}
	//Matrix multiplication of the transpose of matrixA with matrixB, Operation C = A'*B
	void matrixMulTransA(double* matrixA, double* matrixB, double* matrixC, int rowsA, int columnsA, int columnsB) {
		for (int i = 0; i < rowsA; i++) {
			for (int j = 0; j < columnsB; j++) {
				matrixC[i + j * rowsA] = 0;
				for (int k = 0; k < columnsA; k++) {
					matrixC[i + j * rowsA] = matrixC[i + j * rowsA] + matrixA[k + i * columnsA] * matrixB[k + j * columnsA];
				}
			}
		}
	}
	//matrix multiplication C = A*B
	void matrixMul(float* matrixA, float* matrixB, float* matrixC, int rowsA, int columnsA, int columnsB) {
		for (int i = 0; i < rowsA; i++) {
			for (int j = 0; j < columnsB; j++) {
				matrixC[i + j * rowsA] = 0;
				for (int k = 0; k < columnsA; k++) {
					matrixC[i + j * rowsA] = matrixC[i + j * rowsA] + matrixA[i + k * rowsA] * matrixB[k + j * columnsA];
				}
			}
		}
	}
	//matrix multiplication C = A*B
	void matrixMul(double* matrixA, double* matrixB, double* matrixC, int rowsA, int columnsA, int columnsB) {
		for (int i = 0; i < rowsA; i++) {
			for (int j = 0; j < columnsB; j++) {
				matrixC[i + j * rowsA] = 0;
				for (int k = 0; k < columnsA; k++) {
					matrixC[i + j * rowsA] = matrixC[i + j * rowsA] + matrixA[i + k * rowsA] * matrixB[k + j * columnsA];
				}
			}
		}
	}
	//matrix multiplication C = A*B matrix are loaded and stored in column-major order
	void matrixMultiplicacionColumnMajor(float* matrixA, float* matrixB, float* matrixC, int rowsA, int columnsA, int columnsB) {
		for (int i = 0; i < rowsA; i++) {
			for (int j = 0; j < columnsB; j++) {
				matrixC[i + j * rowsA] = 0;
				for (int k = 0; k < columnsA; k++) {
					matrixC[i + j * rowsA] = matrixC[i + j * rowsA] + matrixA[i + k * rowsA] * matrixB[k + j * columnsA];
				}
			}
		}
	}
	//matrix multiplication C = A*B matrix are loaded and stored in column-major order
	void matrixMultiplicacionRowMajor(float* matrixA, float* matrixB, float* matrixC, int rowsA, int columnsA, int columnsB) {
		for (int i = 0; i < rowsA; i++) {
			for (int j = 0; j < columnsB; j++) {
				matrixC[j + i * columnsB] = 0;
				for (int k = 0; k < columnsA; k++) {
					matrixC[j + i * columnsB] = matrixC[j + i * columnsB] + matrixA[k + i * columnsA] * matrixB[j + k * columnsB];
				}
			}
		}
	}
	// change the elements of matrix A from column-major to row-major order
	void matrixConvertToRowMajor(float* matrix, int rows, int columns) {
		int numElements = 0;
		int sizeMatrix = rows * columns;
		float* temporalMatrix = new float[sizeMatrix];
		for (int i = 0; i <= (rows-1); i++) {
			for (int j = 0; j <= (columns-1); j++) {
				temporalMatrix[numElements] = matrix[j + i * columns];
				//std::cout << "matrix[" << i << "] = " << matrix[numElements] << "\n";
				numElements++;
			}
		}
		for (int i = 0; i <= sizeMatrix - 1; i++)
		{
			matrix[i] = temporalMatrix[i];
		}
		delete[] temporalMatrix;
	}
	// change the elements of matrix A from column-major to row-major order
	void matrixConvertToRowMajor(double* matrix, int rows, int columns) {
		int numElements = 0;
		int sizeMatrix = rows * columns;
		double* temporalMatrix = new double[sizeMatrix];
		for (int i = 0; i <= (rows - 1); i++) {
			for (int j = 0; j <= (columns - 1); j++) {
				temporalMatrix[numElements] = matrix[j + i * columns];
				//std::cout << "matrix[" << i << "] = " << matrix[numElements] << "\n";
				numElements++;
			}
		}
		for (int i = 0; i <= sizeMatrix - 1; i++)
		{
			matrix[i] = temporalMatrix[i];
		}
		delete[] temporalMatrix;
	}
	// change the elements of matrix A from row-major to column-major order
	void matrixConvertToColumnMajor(float* matrix, int rows, int columns) {
		int numElements = 0;
		int sizeMatrix = rows * columns;
		float* temporalMatrix = new float[sizeMatrix];
		for (int i = 0; i <= (rows - 1); i++) {
			for (int j = 0; j <= (columns - 1); j++) {
				temporalMatrix[numElements] = matrix[i + j * rows];
				//std::cout << "matrix[" << numElements << "] = " << temporalMatrix[numElements] << "\n";
				numElements++;
			}
		}
		for (int i = 0; i <= sizeMatrix-1; i++)
		{
			matrix[i] = temporalMatrix[i];
		}
		delete[] temporalMatrix;
	}
	// change the elements of matrix A from row-major to column-major order
	void matrixConvertToColumnMajor(double* matrix, int rows, int columns) {
		int numElements = 0;
		int sizeMatrix = rows * columns;
		double* temporalMatrix = new double[sizeMatrix];
		for (int i = 0; i <= (rows - 1); i++) {
			for (int j = 0; j <= (columns - 1); j++) {
				temporalMatrix[numElements] = matrix[i + j * rows];
				//std::cout << "matrix[" << numElements << "] = " << temporalMatrix[numElements] << "\n";
				numElements++;
			}
		}
		for (int i = 0; i <= sizeMatrix - 1; i++)
		{
			matrix[i] = temporalMatrix[i];
		}
		delete[] temporalMatrix;
	}
	//Fill banded matrix A with random numbers in the non-zero elements in row-major order
	void FillBandedRandMatrixRowMajor(float* matrix, int rows, int columns, int lowerDiagonals, int upperDiagonals) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (i > (j + lowerDiagonals) || j > (i + upperDiagonals)) {
					matrix[j + i * columns] = 0.0f;
				}
				else {
					matrix[j + i * columns] = (float)rand();
				}
			}
		}
	}
	//Fill banded matrix A with random numbers in the non-zero elements in row-major order
	void FillBandedRandMatrixRowMajor(double* matrix, int rows, int columns, int lowerDiagonals, int upperDiagonals) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (i > (j + lowerDiagonals) || j > (i + upperDiagonals)) {
					matrix[j + i * columns] = 0.0;
				}
				else {
					matrix[j + i * columns] = (double)rand();
				}
			}
		}
	}
	//Fill banded matrix A with random numbers in the non-zero elements in column-major order
	void FillBandedRandMatrixColumnMajor(float* matrix, int rows, int columns, int lowerDiagonals, int upperDiagonals) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (i > (j + lowerDiagonals) || j > (i + upperDiagonals)) {
					matrix[i + j * rows] = 0.0f;
				}
				else {
					matrix[i + j * rows] = (float)rand();
				}
			}
		}
	}
	//Fill banded matrix A with random numbers in the non-zero elements in column-major order
	void FillBandedRandMatrixColumnMajor(double* matrix, int rows, int columns, int lowerDiagonals, int upperDiagonals) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (i > (j + lowerDiagonals) || j > (i + upperDiagonals)) {
					matrix[i + j * rows] = 0.0;
				}
				else {
					matrix[i + j * rows] = (double)rand();
				}
			}
		}
	}
	// Copy the elements from matrixIn to matrixOut
	void CopyMatrix(float* matrixIn, float* matrixOut, int rows, int columns) {
		int sizeMatrix = rows * columns;
		for (int i = 0; i < sizeMatrix; i++)
		{
			matrixOut[i] = matrixIn[i];
		}
	}
}