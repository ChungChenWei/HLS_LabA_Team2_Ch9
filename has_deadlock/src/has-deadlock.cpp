#include "has-deadlock.hpp"

void block0 (stream_t &data_i, stream_t &coef_i, stream_t &feedback_i, stream_t &data_o) {
	data_o.write(data_i.read() * coef_i.read() - feedback_i.read());
}

void block1 (stream_t &data_i, stream_t &data_o, stream_t &feedback_o) {
	int val = data_i.read();
	int fb = (val > MAXFEEDBACK) ? MAXFEEDBACK : val;

	data_o.write(val);
	feedback_o.write(fb);
}

void top (stream_t &data_i, stream_t &coef_i, stream_t &data_o) {
	static stream_t data ("intermediate_data");
	static stream_t feedback ("feedback");

	block0(data_i, coef_i, feedback, data);
	block1(data, data_o, feedback);
}
