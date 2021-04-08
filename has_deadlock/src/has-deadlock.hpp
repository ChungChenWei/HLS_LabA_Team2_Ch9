#ifndef __HAS_DEADLOCK_HPP__
#define __HAS_DEADLOCK_HPP__

#include "hls_stream.h"

#define MAXFEEDBACK (3000)

typedef hls::stream<int> stream_t;

void block0 (stream_t &data_i, stream_t &coef_i, stream_t &feedback_i, stream_t &data_o);
void block1 (stream_t &data_i, stream_t &data_o, stream_t &feedback_o);

void top (stream_t &data_i, stream_t &coef_i, stream_t &data_o);

#endif
