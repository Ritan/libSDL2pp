#pragma once

#include "Font.hh"
#include "SDL.hh"
#include <string>

namespace SDL2pp
{
	class Text
	{
	public:
		enum class Render_mode {
			SOLID, SHADED, BLENDED
		};
	
		Text( const std::string& text, Font &&font, Text::Render_mode mode );

		void SetRenderMode( const Render_mode mode );
		Render_mode GetRenderMode() const;

		void SetText( const std::string& str );
		std::string GetText() const;

		void SetFont( Font &&font );
		Font& GetFont();

		void SetFGColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a );
		void SetFGColor( SDL_Color color );

		SDL_Color GetFGColor() const;

		void SetBGColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a );
		void SetBGColor( SDL_Color color );

		SDL_Color GetBGColor() const;

		SDL_Surface * Render();

		virtual ~Text();

	private:
		Text();
		Render_mode m_mode;
		std::string m_text;
		Font m_font;
		SDL_Color m_fg_color;
		SDL_Color m_bg_color;
		bool m_valid;
	};
}