#ifndef WAV_MODEL
#define WAV_MODEL

#include <iostream>
#include <vector>

typedef unsigned char byte;

class WavModel;
std::istream& operator>>(std::istream &is, WavModel &model);

class WavModel
{
public:
	friend std::istream& operator>>(std::istream &is, WavModel& model);

	std::vector<short>& get_channel(unsigned channel_num) { return m_channel[channel_num]; }

	unsigned	get_sample_rate() const { return m_sample_rate; }
	unsigned	get_byte_rate() const { return m_byte_rate; }
	unsigned	get_channel_num() { return m_channel.size(); }
	unsigned	get_sample_num() { return m_sample_num; }
	short		get_bps() const { return m_bps; }
	double		get_duration() const { return m_duration; }
private:
	unsigned 	m_sample_rate;
	unsigned	m_byte_rate;
	unsigned	m_sample_num;
	short		m_bps;
	double		m_duration;

	std::vector<std::vector<short>> m_channel;
};

#endif