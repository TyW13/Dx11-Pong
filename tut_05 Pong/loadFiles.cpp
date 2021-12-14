#include "loadFiles.h"

bool GF::loadTexture(const std::string& file, sf::Texture& tex, const bool& smoothing)
{
	if (tex.loadFromFile(file))
	{
		tex.setSmooth(smoothing);
		return true;
	}
	assert(false);
	return false;
}

bool GF::loadAudio(const std::string& file, sf::SoundBuffer& buffer)
{
	if (buffer.loadFromFile(file))
	{
		return true;
	}
	assert(false);
	return false;
}