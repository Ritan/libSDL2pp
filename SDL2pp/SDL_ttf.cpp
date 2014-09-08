#include "SDL_ttf.hh"
#include "SDL2pp/Exception.hh"

namespace SDL2pp
{
	SDLttf::~SDLttf()
	{
		TTF_Quit();
	}

	SDLttf::SDLttf( int unicode_swapped /* = 0 */ )
	{
		if ( TTF_Init() == -1 ) {
			throw SDL2pp::Exception( "TTF_Init: %s\n" );
		}
		TTF_ByteSwappedUNICODE( unicode_swapped );
	}

	int SDLttf::WasInit()
	{
		return TTF_WasInit();
	}

	const SDL_version SDLttf::Runtime_version() const
	{
		return *TTF_Linked_Version();

	}

	const SDL_version SDLttf::Compile_version() const
	{
		SDL_version version;
		SDL_TTF_VERSION( &version );
		return version;
	}

}
