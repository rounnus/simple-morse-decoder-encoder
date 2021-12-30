#ifndef SIMPLE_MORSE_DECODER_ENCODER_DECODER_H
#define SIMPLE_MORSE_DECODER_ENCODER_DECODER_H


/**
 * Decodes an morse siquece.
 * @param morse_seq The sequence of dots and minus symbols.
 * @return On success the ASCII text that the sequence is
 * equal to.
 */
extern char *decode_morse(const char *morse_seq);


#endif
