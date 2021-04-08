#include <iostream>
#include "good-stream.hpp"

int main () {
	int result;
	stream_t s11;
	stream_t s12;
	stream_t s21;
	stream_t s22;

	s11.write(3);
	s22.write(15);

	result = top(s11, s12);
	if (result != 3) {
		std::cout << "[size = 1] expect " << 3 << " , got " << result << std::endl;
		return 1;
	}

	result = top(s21, s22);
	if (result != 15) {
		std::cout << "[size = 2] expect " << 15 << " , got " << result << std::endl;
		return 1;
	}

	std::cout << "success" << std::endl;

	return 0;
}
