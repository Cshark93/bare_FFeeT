#ifndef __BARE_FFEET_H__
#define __BARE_FFEET_H__
#include <eigen/FFT.h>
#include<Eigen/Dense>
#include <chrono>
#include <vector>
#include <math.h>
#include <iostream>

namespace bare_FFeeT
{
	//ZIEL:
	//input: vector<time>, vector<double>
	//output: vector<pair<frequenz, amplitude> >

	std::vector<std::pair<std::chrono::steady_clock::time_point, float>> cos_freq_gen(float frequency, int duration_sec, int sample_rate_ms) {
		float pi = 3.141592654;
		float ang_inc = 360.0 * frequency /1000.0 * sample_rate_ms; //Winkelinkrement von sample zu sample. Berücksichtigt die Frequenz und die Abtastrate. 

		std::vector<std::pair<std::chrono::steady_clock::time_point, float>> ret;
		int sample = 0;
		std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
		while (duration_sec * 1000 - sample * sample_rate_ms >= 0) {
			std::chrono::steady_clock::time_point tp = start + std::chrono::milliseconds(sample*sample_rate_ms);
			float val = cos(((sample*ang_inc) * pi) / 180);
			ret.push_back(std::pair<std::chrono::steady_clock::time_point, float>(tp, val));
			sample++;
		}
		return ret;
	}

	void fft_test() { //from an example
		Eigen::MatrixXf A = Eigen::MatrixXf::Random(3, 10);
		Eigen::FFT<float> fourier;
		Eigen::MatrixXcf B(3, 10);  
		for (int k = 0; k < A.cols(); ++k) {
			B.col(k) = fourier.fwd(A.col(k));
		}
		std::cout << "Matrix result fourier: \n" << B.row(1) << std::endl;
	}

}; // namespace bare_FFeeT

#endif /*__BARE_FFEET_H__*/
