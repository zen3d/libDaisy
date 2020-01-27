#include <string.h>
#include "daisy_seed.h"
#include "daisysp.h"
#include <math.h>

// 1MB test
#define TEST_BUFF_SIZE (1024 * 1024)

using namespace daisy;
using namespace daisysp;

static uint32_t DSY_SDRAM_BSS test_buff[TEST_BUFF_SIZE];

static daisy_handle hw;

void passthru(float *in, float *out, size_t size)
{
    memcpy(out, in, sizeof(float) * size);
}

int main(void)
{
	// Initialize Hardware
	daisy_seed_init(&hw);
//	for(uint32_t i = 0; i < TEST_BUFF_SIZE; i++) 
//	{
//		test_buff[i] = i;
//	}
//	for(uint32_t i = 0; i < TEST_BUFF_SIZE; i++) 
//	{
//		if(test_buff[i] != i) 
//		{
//			asm("bkpt 255");
//		}
//	}
//	dsy_tim_start();
    hw.audio_handle.SetCallback(passthru);
    hw.audio_handle.Start();

    //	dsy_audio_set_callback(DSY_AUDIO_INTERNAL, bad_callback);
    //	dsy_audio_start(DSY_AUDIO_INTERNAL);
	while(1) {}
}

