#include "good-stream.hpp"

int top (stream_t &in1, stream_t &in2) {
	bool cond1, cond2;

	cond1 = in1.empty();
	cond2 = in2.empty();

	if (!cond1) {
		return in1.read();
	}
	else if (!cond2) {
		return in2.read();
	}
	return 0;
}

