#include "WavModel.h"

#include <cstdint>
#include <cstring>

using std::string;
using std::istream;
using std::vector;

const unsigned SUB1_SIZE_PARAM = 16; //Location of Subchunk1_Size param in Wav file

istream& operator>>(istream &is, WavModel &model)
{
	byte b4[4];

	uint32_t sub1_size;
	uint16_t num_channels;
	uint32_t sample_rate;
	uint32_t byte_rate;
	uint16_t block_size;
	uint16_t bps;
	uint32_t sub2_size;

	is >> std::noskipws;
	is.seekg(SUB1_SIZE_PARAM, std::ios_base::beg);
	
	is >> b4[0] >> b4[1] >> b4[2] >> b4[3];
	memcpy(&sub1_size, b4, 4);

	is.seekg(2, std::ios_base::cur);	//Skip audio format param

	is >> b4[0] >> b4[1];
	memcpy(&num_channels, b4, 2);
	
	is >> b4[0] >> b4[1] >> b4[2] >> b4[3];
	memcpy(&sample_rate, b4, 4);
	
	is >> b4[0] >> b4[1] >> b4[2] >> b4[3];
	memcpy(&byte_rate, b4, 4);
	
	is >> b4[0] >> b4[1];
	memcpy(&block_size, b4, 2);
	
	is >> b4[0] >> b4[1];
	memcpy(&bps, b4, 2);

	is.seekg(SUB1_SIZE_PARAM + 4 + sub1_size + 4, std::ios_base::beg);	//Read subchunk2_size param
	is >> b4[0] >> b4[1] >> b4[2] >> b4[3];
	memcpy(&sub2_size, b4, 4);

	uint32_t num_samples = sub2_size / block_size;

	model.m_sample_rate = sample_rate;
	model.m_byte_rate = byte_rate;
	model.m_sample_num = num_samples;
	model.m_bps = bps;
	model.m_duration = static_cast<double>(num_samples) / sample_rate;

	model.m_channel = vector<vector<short>>(num_channels, vector<short>(num_samples));//WATCH OUT

	for (uint32_t samp = 0; samp < num_samples; samp++)
	{
		for (uint32_t chan = 0; chan < num_channels; chan++)
		{
			for (short _byte = 0; _byte < bps / 8; _byte++)
				is >> b4[_byte];
			short sample;
			memcpy(&sample, b4, bps / 8);
			model.m_channel[chan][samp] = sample;
		}
	}

	return is;
}