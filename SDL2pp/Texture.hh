/*
  libSDL2pp - C++ wrapper for libSDL2
  Copyright (C) 2013 Dmitry Marakasov <amdmi3@amdmi3.ru>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef SDL2PP_TEXTURE_HH
#define SDL2PP_TEXTURE_HH

#ifdef _MSC_VER
#define noexcept
#endif _MSC_VER

#include <string>

#include <SDL_stdinc.h>
#include <SDL_blendmode.h>

#include <SDL2pp/Config.hh>

struct SDL_Texture;

namespace SDL2pp {

class Renderer;
class Rect;
class RWops;

class Texture {
private:
	SDL_Texture* texture_;

public:
	Texture(Renderer& renderer, Uint32 format, int access, int w, int h);
	Texture( Renderer& renderer, SDL_Surface * surface );
#ifdef SDL2PP_WITH_IMAGE
	Texture(Renderer& renderer, RWops& rwops);
	Texture(Renderer& renderer, const std::string& filename);
#endif
	virtual ~Texture();

	Texture(const Texture& other) = delete;
	Texture(Texture&& other) noexcept;
	Texture& operator=(const Texture& other) = delete;
	Texture& operator=(Texture&& other) noexcept;

	SDL_Texture* Get() const;

	void Update(const Rect& rect, const void* pixels, int pitch);

	void SetBlendMode(SDL_BlendMode blendMode);
	void SetAlphaMod(Uint8 alpha = 255);
	void SetColorMod(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255);
};

}

#endif
