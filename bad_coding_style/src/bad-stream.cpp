#include "bad-stream.hpp"

int top (stream_t &in1, stream_t &in2) {
	if (!in1.empty()) {
		return in1.read();
	}
	else if (!in2.empty()) {
		return in2.read();
	}
	return 0;
}

