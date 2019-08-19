#include "inc/datasources/bare_FFeeT.h"
#include <iostream>

int main() {
	std::cout << "Test cos_gen" << std::endl;

	auto vec_pair = bare_FFeeT::cos_freq_gen(1, 1, 1);
	auto start = vec_pair.at(0).first;
	for (auto v : vec_pair) {
		std::chrono::duration<double> t = v.first - start;
		std::cout << t.count() << "sec | " << v.second << std::endl;
	}

	bare_FFeeT::fft_test();
	int i;
	std::cin >> i;
	return 0;
}