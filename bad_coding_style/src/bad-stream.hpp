#ifndef __BAD_STREAM_HPP__
#define __BAD_STREAM_HPP__

#include "hls_stream.h"

typedef hls::stream<int> stream_t;

int top (stream_t &in1, stream_t &in2);

#endif
