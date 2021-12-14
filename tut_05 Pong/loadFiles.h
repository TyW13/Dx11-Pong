#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <assert.h>

/*
Global functions,
functions that can be applied to all sprites in the game
*/
namespace GF
{
	/*
	*description - Function to load texture using file path and assign it as a texture variables value, also gives the option for image smoothing
	*parameters - file (string&), tex (Texture&), smoothing(bool&)
	*pre-conditions - file path must be correct/exist, texture variable is declared
	*post-conditions - texture variable has been assigned a value
	*/
	bool loadTexture(const std::string& file, sf::Texture& tex, const bool& smoothing);

	bool loadAudio(const std::string& file, sf::SoundBuffer& buffer);
};