#include <iostream>
#include "has-deadlock.hpp"

int main () {
	int size = 20;
	int data[] = {30, 57, 10, 10, 50, 12, 12, 100, 10, 59, 21, 59, 6, 67, 27, 55, 47, 2, 58, 74};
	int coef[] = {13, 25, 34, 2, 19, 56, 19, 82, 80, 2, 18, 63, 2, 42, 97, 52, 57, 71, 84, 66};

	stream_t data_i ("input_data");
	stream_t coef_i ("coef");
	stream_t data_o; ("output_data");

	for (int i = 0; i < size; ++i) {
		data_i.write(data[i]);
		coef_i.write(coef[i]);
		top(data_i, coef_i, data_o);
	}

	for (int i = 0; i < size; ++i) {
		std::cout << data_o.read();
		if (i != size-1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}

	return 0;
}
