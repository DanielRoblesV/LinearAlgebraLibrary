#include "matrixFunctions.h"
#include "QRGivens.h"
#include <iostream>
//using namespace matrixFunctions;
void Test();
void QRDecompositionTest();

int main() {
	QRDecompositionTest();
	//Test();
}
void QRDecompositionTest() {
	//float matrixIn[16] = { 12, -51, 4, 1, 6, 167, -68, 1, -4, 24, -41, 1, 7, 8, 9, 1 };
	float* matrixA; float* matrixR; float* matrixQ;
	float* matrixQR;
	int rowsA, columnsA, sizeMatrixA;
	std::string respuesta;
	do {
		system("cls");
		std::cout << "rows of A:" << "\n";
		std::cin >> rowsA;
		std::cout << "columns of A:" << "\n";
		std::cin >> columnsA;
		sizeMatrixA = rowsA * columnsA;
		matrixA = new float[sizeMatrixA];
		matrixR = new float[sizeMatrixA];
		matrixQR = new float[sizeMatrixA];
		matrixQ = new float[(int)(rowsA * rowsA)];
		//Filling values of matrices A, R and Q
		matrixFunctions::FillRandMatrixRowMajor(matrixA, rowsA, columnsA);
		//matrixFunctions::CopyMatrix(matrixIn, matrixA, rowsA, columnsA);
		matrixFunctions::CopyMatrix(matrixA, matrixR, rowsA, columnsA);
		matrixFunctions::FillIdentityMatrixRowMajor(matrixQ, rowsA);
		std::cout << "matrixA values: \n";
		for (size_t i = 0; i < sizeMatrixA; i++)
		{
			std::cout << "matrixA[" << i << "] = " << matrixA[i] << "\n";
		}
		std::cout << "matrixA\n";
		matrixFunctions::Print2DarrayRowMajor(matrixA, rowsA, columnsA);
		std::cout << "matrixQ\n";
		matrixFunctions::Print2DarrayRowMajor(matrixQ, rowsA, rowsA);
		// QR decomposition of matrix A
		Givens::QRDecompositionASrs(matrixA, rowsA, columnsA, matrixQ, matrixR);
		// Printing results
		std::cout << "matrixR\n";
		matrixFunctions::Print2DarrayRowMajor(matrixR, rowsA, columnsA);
		std::cout << "matrixQ\n";
		matrixFunctions::Print2DarrayRowMajor(matrixQ, rowsA, columnsA);
		matrixFunctions::matrixMultiplicacionRowMajor(matrixQ, matrixR, matrixQR, rowsA, rowsA, columnsA);
		std::cout << "matrixQR\n";
		matrixFunctions::Print2DarrayRowMajor(matrixQR, rowsA, columnsA);
		std::cout << "do you want to repeat the experiment? (y,n)\n";
		std::cin >> respuesta;
		delete[] matrixA;
		delete[] matrixR;
		delete[] matrixQ;
	} while (respuesta == "y");
	std::cin.get();
}
void Test() {
	float* matrixA;
	int rowsA, columnsA, sizeMatrixA;
	std::string respuesta;
	do {
		system("cls");
		std::cout << "rows of A:" << "\n";
		std::cin >> rowsA;
		std::cout << "columns of A:" << "\n";
		std::cin >> columnsA;
		sizeMatrixA = rowsA * columnsA;
		matrixA = new float[sizeMatrixA];
		//matrixFunctions::FillRandMatrixColumnMajor(matrixA, rowsA, columnsA);
		std::cout << "matrixA values: \n";
		for (size_t i = 0; i < sizeMatrixA; i++)
		{
			matrixA[i] = (float)i;
			std::cout << "matrixA[" << i << "] = " << matrixA[i] << "\n";
		}
		std::cout << "matrixA printed in column major order \n";
		matrixFunctions::Print2DarrayColumnMajor(matrixA, rowsA, columnsA);
		std::cout << "matrixA printed in row major order \n";
		matrixFunctions::Print2DarrayRowMajor(matrixA, rowsA, columnsA);
		std::cout << "matrixA values in column major: \n";
		matrixFunctions::matrixConvertToColumnMajor(matrixA, rowsA, columnsA);
		for (size_t i = 0; i < sizeMatrixA; i++)
		{
			std::cout << "matrixA[" << i << "] = " << matrixA[i] << "\n";
		}
		std::cout << "do you want to repeat the experiment? (y,n)\n";
		std::cin >> respuesta;
		delete[] matrixA;
	} while (respuesta == "y");
	std::cin.get();
}