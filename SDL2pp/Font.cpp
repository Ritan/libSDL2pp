#include "Font.hh"
#include "Exception.hh"
#include <string>

namespace SDL2pp
{
	Font::~Font()
	{
		TTF_CloseFont( m_font );
	}

	Font::Font( const std::string& path, int ptsize )
	{
		m_font = TTF_OpenFont( path.c_str(), ptsize );
		if ( !m_font ) {
			throw Exception("TTF_OpenFont failed");
		}
	}

	Font::Font( RWops& src, int freesrc, int ptsize )
	{
		m_font = TTF_OpenFontRW( src.Get(), freesrc, ptsize );
		if ( !m_font ) {
			throw Exception( "TTF_OpenFontRW failed" );
		}
	}

	Font::Font( const std::string& path, int ptsize, long index )
	{
		m_font = TTF_OpenFontIndex( path.c_str(), ptsize, index );
		if ( !m_font ) {
			throw Exception( "TTF_OpenFontIndex failed" );
		}
	}

	Font::Font( RWops& src, int freesrc, int ptsize, long index )
	{
		m_font = TTF_OpenFontIndexRW( src.Get(), freesrc, ptsize, index);
		if ( !m_font ) {
			throw Exception( "TTF_OpenFontIndexRW failed" );
		}
	}

	Font::Font( Font&& other ) noexcept : m_font( other.m_font )
	{
		other.m_font = nullptr;
	}

	Font& Font::operator=( Font&& other ) noexcept
	{
		this->m_font = other.m_font;
		other.m_font = nullptr;
		return *this;
	}


	TTF_Font* Font::Get() const
	{
		return m_font;
	}

	int Font::GetStyle() const
	{
		return TTF_GetFontStyle( m_font );
	}

	void Font::SetStyle( int style )
	{
		TTF_SetFontStyle( m_font, style );
	}

	int Font::GetOutline() const
	{
		return TTF_GetFontOutline( m_font );
	}

	void Font::SetOutline( int outline )
	{
		TTF_SetFontOutline( m_font, outline );
	}

	int Font::GetHinting() const
	{
		return TTF_GetFontHinting( m_font );
	}

	void Font::SetHinting( int hinting )
	{
		TTF_SetFontHinting( m_font, hinting );
	}

	int Font::GetKerning() const
	{
		return TTF_GetFontKerning( m_font );
	}

	void Font::SetKerning( int kerning )
	{
		TTF_SetFontKerning( m_font, kerning );
	}

	int Font::GetMaxHeight() const
	{
		return TTF_FontHeight( m_font );
	}

	int Font::GetAscent() const
	{
		return TTF_FontAscent( m_font );
	}

	int Font::GetDescent() const
	{
		return TTF_FontDescent( m_font );
	}

	int Font::GetLineSkip() const
	{
		return TTF_FontLineSkip( m_font );
	}

	long Font::GetFacesNum() const
	{
		return TTF_FontFaces( m_font );
	}

	bool Font::FaceIsFixedWidth() const
	{
		return TTF_FontFaceIsFixedWidth( m_font ) > 0;
	}

	std::string Font::FaceFamilyName() const
	{
		return TTF_FontFaceFamilyName( m_font );
	}

	std::string Font::FaceStyleName() const
	{
		return TTF_FontFaceStyleName( m_font );
	}

	int Font::GlyphIsProvided( Uint16 ch ) const
	{
		return TTF_GlyphIsProvided( m_font, ch );
	}

	int Font::GlyphMetrics( Uint16 ch, int *minx, int *maxx, int *miny, int *maxy, int *advance ) const
	{
		int res = TTF_GlyphMetrics( m_font, ch, minx, maxx, miny, maxy, advance );
		if ( res == -1 )
		{
			throw Exception( "TTF_GlyphMetrics failed" );
		}
		return res;
	}

	int Font::SizeText( std::string& text, int &w, int &h )
	{
		int res = TTF_SizeText( m_font, text.c_str(), &w, &h );
		if ( res == -1 )
		{
			throw Exception( "TTF_SizeText failed" );
		}
		return res;
	}

	int Font::SizeUTF8( std::string& text, int &w, int &h )
	{
		int res = TTF_SizeUTF8( m_font, text.c_str( ), &w, &h );
		if ( res == -1 )
		{
			throw Exception( "TTF_SizeUTF8 failed" );
		}
		return res;
	}

	int Font::SizeUNICODE( std::u16string& text, int &w, int &h )
	{
		int res = TTF_SizeUNICODE( m_font, (Uint16*)text.c_str(), &w, &h );
		if ( res == -1 )
		{
			throw Exception( "TTF_SizeUNICODE failed" );
		}
		return res;
	}


}
