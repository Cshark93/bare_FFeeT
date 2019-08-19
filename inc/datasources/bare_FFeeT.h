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
	std::vector<std::pair<std::chrono::steady_clock::time_point, float>> cos_freq_gen(float frequency, int duration_sec, int sample_rate_ms) {
		float pi = 3.141592654;
		float ang_inc = 360.0 * frequency /1000.0 * sample_rate_ms;

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
	};

	void fft_test() {
		Eigen::MatrixXf A = Eigen::MatrixXf::Random(3, 10);
		Eigen::FFT<float> fourier;
		Eigen::MatrixXcf B(3, 10);  // note the change from real to complex
									//fft.fwd(B,A); // It is natural to want to do this, unfortunately it is not yet supported

									// it works to iterate over the columns
		for (int k = 0; k < A.cols(); ++k) {
			B.col(k) = fourier.fwd(A.col(k));
		}
		std::cout << "Matrix result fourier: \n" << B.row(1) << std::endl;
	}

	std::vector < std::pair<float, float>> fft(std::vector < std::chrono::steady_clock::time_point >, std::vector<float>) {
		Eigen::MatrixXf A;
		Eigen::FFT<float> fourier;
		Eigen::MatrixXcf B(3, 10);  // note the change from real to complex
							 //fft.fwd(B,A); // It is natural to want to do this, unfortunately it is not yet supported

							 // it works to iterate over the columns
		for (int k = 0; k < A.cols(); ++k) {
			B.col(k) = fourier.fwd(A.col(k));
		}
		std::cout << "Matrix result fourier: \n" << B << std::endl;
		return std::vector < std::pair<float, float>>();
	};
//input: vector<time>, vector<double>
//output: vector<pair<frequenz, amplitude> >
		/*
		
		
		
		*/


}; // namespace bare_FFeeT

#endif /*__BARE_FFEET_H__*/
