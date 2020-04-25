#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const unsigned char* afl_postprocess(const unsigned char* in_buf, unsigned int* len){
	unsigned char* new_buf;
	new_buf = (unsigned char*) malloc((*len) + 4);
	int crc = 0xab4130;
	int temp = 0;
	for(int i = 0; i < (*len - 1); i++){
		crc = crc + in_buf[i];
		temp = crc * 0x10;
		crc = temp + crc;

	}
	crc = crc + 0xA;
	temp = crc * 0x10;
	crc = temp + crc;

	memcpy(new_buf,&crc,4);
	memcpy(&(new_buf[4]), in_buf, (*len));
	*len = (*len) + 4 ;
	return new_buf;

}
