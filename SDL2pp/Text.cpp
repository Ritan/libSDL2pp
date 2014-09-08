
#include "Text.hh"
#include <cvt/wstring>
#include <codecvt>

namespace SDL2pp
{

	Text::Text( const std::string& text, Font &&font, Text::Render_mode mode ) : m_font( std::move( font ) )
	{
		SetFGColor( 0, 0, 0, 0xff );
		m_mode = mode;
		m_valid = true;
		m_text = text;
	}

	Text::~Text()
	{

	}

	void Text::SetRenderMode( const Render_mode mode )
	{
		m_mode = mode;
	}

	Text::Render_mode Text::GetRenderMode() const
	{
		return m_mode;
	}

	void Text::SetText( const std::string& str )
	{
		m_text = str;
	}


	std::string Text::GetText() const
	{
		return m_text;
	}


	void Text::SetFont( Font &&font )
	{
		m_valid = true;
		m_font = std::move(font);
	}

	Font& Text::GetFont()
	{
		m_valid = false;
		return m_font;
	}

	SDL_Surface * Text::Render()
	{
		SDL_Surface * surf;

		switch ( m_mode )
		{
			case Text::Render_mode::SOLID:
			surf = TTF_RenderText_Solid( m_font.Get(), m_text.c_str(), m_fg_color );
			break;
			case Text::Render_mode::SHADED:
			surf = TTF_RenderText_Shaded( m_font.Get( ), m_text.c_str( ), m_fg_color, m_bg_color );
			break;
			case Text::Render_mode::BLENDED:
			surf = TTF_RenderText_Blended( m_font.Get( ), m_text.c_str( ), m_fg_color );
			break;
		}

		if ( !surf )
		{
			throw Exception( "TTF_RenderText_* failed" );
		}
		return surf;
	}

	void Text::SetFGColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a )
	{
		m_fg_color.r = r;
		m_fg_color.g = g;
		m_fg_color.b = b;
		m_fg_color.a = a;
	}

	void Text::SetFGColor( SDL_Color color )
	{
		m_fg_color = color;
	}

	SDL_Color Text::GetFGColor() const
	{
		return m_fg_color;
	}

	void Text::SetBGColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a )
	{
		m_bg_color.r = r;
		m_bg_color.g = g;
		m_bg_color.b = b;
		m_bg_color.a = a;
	}

	void Text::SetBGColor( SDL_Color color )
	{
		m_bg_color = color;
	}

	SDL_Color Text::GetBGColor() const
	{
		return m_bg_color;
	}


}