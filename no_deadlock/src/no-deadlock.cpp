#include "no-deadlock.hpp"

void block0 (stream_t &data_i, stream_t &coef_i, stream_t &feedback_i, stream_t &data_o, stream_t &dump_fb1) {
	int fb = feedback_i.empty() ? 0 : feedback_i.read();
	dump_fb1.write(fb); // for demonstration
	data_o.write(data_i.read() * coef_i.read() - fb);
}

void block1 (stream_t &data_i, stream_t &data_o, stream_t &feedback_o, stream_t &dump_fb2) {
	int val = data_i.read();
	int fb = (val > MAXFEEDBACK) ? MAXFEEDBACK : val;
	dump_fb2.write(fb); // for demonstration
	data_o.write(val);
	feedback_o.write(fb);
}

void top (stream_t &data_i, stream_t &coef_i, stream_t &data_o, stream_t &dump_fb1, stream_t &dump_fb2) {
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_fifo depth=20 port=dump_fb1
#pragma HLS INTERFACE ap_fifo depth=20 port=dump_fb2

	static stream_t data ("intermediate_data");
	static stream_t feedback ("feedback");

	block0(data_i, coef_i, feedback, data, dump_fb1);
	block1(data, data_o, feedback, dump_fb2);
}
