#include "rocc.h"

static inline void aes_sd(unsigned long address)
{
	asm volatile ("fence");
	ROCC_INSTRUCTION_S(3, address, 3);
	asm volatile ("fence");
}

static inline void aes_dc(unsigned long low, unsigned long high)
{
	ROCC_INSTRUCTION_SS(3, low, high, 1);
}

static inline void aes_ec(unsigned long low, unsigned long high)
{
	ROCC_INSTRUCTION_SS(3, low, high, 2);
}

static inline void aes_exp(unsigned long low, unsigned long high)
{
	ROCC_INSTRUCTION_SS(3, low, high, 0);
}
static inline void aes_load_key(unsigned long low, unsigned long high)
{
	ROCC_INSTRUCTION_SS(3, low, high, 4);
}
typedef struct {
    unsigned long low;
    unsigned long high;
} data_128;

int main(void)
{
	// unsigned long result;
	data_128 key;  
	data_128 data_pre_0;  
	data_128 data_pre_1;  
	data_128 data_pre_2;  
	data_128 data_pre_3;  
	data_128 data_af_0;  
	data_128 data_af_1;  
	data_128 data_af_2;  
	data_128 data_af_3;  
	unsigned long result_0[2];
	unsigned long result_1[2];
	unsigned long result_2[2];
	unsigned long result_3[2];
	unsigned long result_4[2];
	unsigned long result_5[2];
	unsigned long result_6[2];
	unsigned long result_7[2];
	key.high = 0x2b7e151628aed2a6;
	key.low= 0xabf7158809cf4f3c;
	data_pre_0.high = 0x6bc1bee22e409f96;
	data_pre_0.low  = 0xe93d7e117393172a;
	data_pre_1.high = 0xae2d8a571e03ac9c;
	data_pre_1.low  = 0x9eb76fac45af8e51;
	data_pre_2.high = 0x30c81c46a35ce411;
	data_pre_2.low  = 0xe5fbc1191a0a52ef;
	data_pre_3.high = 0xf69f2445df4f9b17;
	data_pre_3.low  = 0xad2b417be66c3710;

	data_af_0.high =0xd8b67addc9c28b6b; 
	data_af_0.low = 0xfe71863859f55eba;
	data_af_1.high =0xe5c767a40f95e15b; 
	data_af_1.low = 0x9f1d351b8a998274;
	data_af_2.high =0x73efafe42610da24; 
	data_af_2.low = 0x319c2559a342d8b8;
	data_af_3.high =0x5d9e4cb5e470ce12; 
	data_af_3.low = 0x05c911cecda24535;

	//aes_exp(key.low,key.high);
	aes_load_key(key.low,key.high);
	aes_ec(data_pre_0.low, data_pre_0.high);
	aes_sd(result_0);
	aes_ec(data_pre_1.low, data_pre_1.high);
	aes_sd(result_1);
	aes_ec(data_pre_2.low, data_pre_2.high);
	aes_sd(result_2);
	aes_ec(data_pre_3.low, data_pre_3.high);
	aes_sd(result_3);
	aes_dc(data_af_0.low, data_af_0.high);
	aes_sd(result_4);
	aes_dc(data_af_1.low, data_af_1.high);
	aes_sd(result_5);
	aes_dc(data_af_2.low, data_af_2.high);
	aes_sd(result_6);
	aes_dc(data_af_3.low, data_af_3.high);
	aes_sd(result_7);
	return 0;
}
