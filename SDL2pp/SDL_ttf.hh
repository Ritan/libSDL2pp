#pragma once
#include "SDL_ttf.h"


namespace SDL2pp
{
	class SDLttf
	{
	public:
		SDLttf( const SDLttf& other ) = delete;
		SDLttf( SDLttf&& other ) = delete;
		SDLttf& operator=( const SDLttf& other ) = delete;
		SDLttf& operator=( SDLttf&& other ) = delete;

		SDLttf( int unicode_swapped = 0 );
		~SDLttf();
		int WasInit();

		const SDL_version Runtime_version() const;
		const SDL_version Compile_version() const;
	};
}