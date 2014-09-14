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

#ifndef SDL2PP_POINT_HH
#define SDL2PP_POINT_HH

#include <SDL_rect.h>

#ifdef _MSC_VER
#define noexcept
#endif _MSC_VER

namespace SDL2pp {

class Point {
private:
	SDL_Point point_;
	bool valid_;

private:
	Point();

public:
	Point(int x, int y);
	virtual ~Point();

	static Point Null();

	Point(const Point&) noexcept = default;
	Point(Point&&) noexcept;
	Point& operator=(const Point&) noexcept = default;
	Point& operator=(Point&&) noexcept;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	SDL_Point* Get();
	const SDL_Point* Get() const;

	bool IsNull() const;

	int GetX() const;
	void SetX(int x);

	int GetY() const;
	void SetY(int y);

	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;

	Point& operator+=(const Point& other);
	Point& operator-=(const Point& other);
};

}
#undef noexcept
#endif
