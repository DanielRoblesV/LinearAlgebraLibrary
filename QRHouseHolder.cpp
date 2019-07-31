#include "QRHouseholder.h"
#include <algorithm>

namespace Householder {

	double House(double* x, double* v, int m, int offset) {
		double beta;
		double sigma = 0;
		double mi;
		v[offset] = 1;
		for (int i = offset + 1; i < m; i++) {
			sigma = sigma + x[i] * x[i];
			v[i] = x[i];
		}

		if (sigma == 0 && x[offset] >= 0) {
			beta = 0;
		}
		else if (sigma == 0 && x[offset] < 0) {
			beta = -2;
		}
		else {
			mi = sqrt(x[offset] * x[offset] + sigma);
			if (x[offset] <= 0) {
				v[offset] = x[offset] - mi;
			}
			else {
				v[offset] = -sigma / (x[offset] + mi);
			}
			beta = 2 * v[offset] * v[offset] / (sigma + v[offset] * v[offset]);
			for (int j = offset; j < m; j++) {
				v[j] = v[j] / v[offset];
			}
		}
		return beta;
	}

}