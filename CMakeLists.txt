cmake_minimum_required(VERSION 3.18)
project(simple_morse_decoder_encoder C)

set(CMAKE_C_STANDARD 99)

add_executable(morse main.c lib/decoder.c lib/encoder.c)

include_directories(
		lib/include/
	)
