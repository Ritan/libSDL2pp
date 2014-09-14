#pragma once
#include "SDL_ttf.hh"
#include <string>
#include "SDL2pp/RWops.hh"

#ifdef _MSC_VER
#define noexcept
#endif _MSC_VER

namespace SDL2pp
{
	class Font
	{
	public:
		virtual ~Font();

		Font( const Font& other ) = delete;
		Font( Font&& other ) ;
		Font& operator=( const Font& other ) = delete;
		Font& operator=( Font&& other ) noexcept;

		Font( const std::string& path, int ptsize );
		Font( RWops& src, int freesrc, int ptsize );
		Font( const std::string& path, int ptsize, long index );
		Font( RWops& src, int freesrc, int ptsize, long index );
		
		TTF_Font* Get() const;

		int GetStyle() const;
		void SetStyle( int style );
		int GetOutline() const;
		void SetOutline( int outline );
		int GetHinting() const;
		void SetHinting( int hinting );
		int GetKerning() const;
		void SetKerning( int kerning );

		int GetMaxHeight() const;
		int GetAscent() const;
		int GetDescent() const;
		int GetLineSkip() const;
		long GetFacesNum() const;
		bool FaceIsFixedWidth() const;
		std::string FaceFamilyName() const;
		std::string FaceStyleName() const;
		int GlyphIsProvided( Uint16 ch ) const;
		int GlyphMetrics( Uint16 ch, int *minx, int *maxx, int *miny, int *maxy, int *advance ) const;

		int SizeText( std::string& text, int &w, int &h );
		int SizeUTF8( std::string& text, int &w, int &h );
		int SizeUNICODE( std::u16string& text, int &w, int &h );

	private:
		TTF_Font * m_font;
	};
}

#undef noexcept