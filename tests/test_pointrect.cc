#include <SDL2pp/Point.hh>
#include <SDL2pp/Rect.hh>

#include "testing.h"

using namespace SDL2pp;

BEGIN_TEST()
	{
		// Point basic ops
		Point p(1,2);

		EXPECT_TRUE(!p.IsNull());
		EXPECT_TRUE(p.GetX() == 1 && p.GetY() == 2);
		EXPECT_TRUE(p == Point(1,2));
		EXPECT_TRUE(p != Point(1,1));
		EXPECT_TRUE(p != Point(2,2));
		EXPECT_TRUE(p != Point::Null());

		p.SetX(4);
		p.SetY(5);

		EXPECT_TRUE(p.GetX() == 4 && p.GetY() == 5);
		EXPECT_TRUE(p == Point(4,5));

		p = Point(6,7);

		EXPECT_TRUE(p.GetX() == 6 && p.GetY() == 7);
		EXPECT_TRUE(p == Point(6,7));

		p = Point::Null();

		EXPECT_TRUE(p != Point(1,2));
		EXPECT_TRUE(p == Point::Null());
		EXPECT_TRUE(p.IsNull());
	}

	{
		// Point self assignment
		Point p(8,9);
		p = Point(10,11);

		p = p;

		EXPECT_TRUE(p.GetX() == 10 && p.GetY() == 11);
	}

	{
		// Point self move-assignment
		Point p(12,13);
		p = Point(14,15);

		p = std::move(p);

		EXPECT_TRUE(p.GetX() == 14 && p.GetY() == 15);
	}

	{
		// Rect basic ops
		Rect r(1,2,3,4);

		EXPECT_TRUE(!r.IsNull());
		EXPECT_TRUE(r.GetX() == 1 && r.GetY() == 2 && r.GetW() == 3 && r.GetH() == 4);
		EXPECT_TRUE(r == Rect(1,2,3,4));
		EXPECT_TRUE(r != Rect(2,2,3,4));
		EXPECT_TRUE(r != Rect(1,3,3,4));
		EXPECT_TRUE(r != Rect(1,2,4,4));
		EXPECT_TRUE(r != Rect(1,2,3,5));
		EXPECT_TRUE(r != Rect::Null());

		r.SetX(5);
		r.SetY(6);
		r.SetW(7);
		r.SetH(8);

		EXPECT_TRUE(r.GetX() == 5 && r.GetY() == 6 && r.GetW() == 7 && r.GetH() == 8);
		EXPECT_TRUE(r == Rect(5,6,7,8));

		r = Rect(9,10,11,12);

		EXPECT_TRUE(r.GetX() == 9 && r.GetY() == 10 && r.GetW() == 11 && r.GetH() == 12);
		EXPECT_TRUE(r == Rect(9,10,11,12));

		r = Rect::Null();

		EXPECT_TRUE(r != Rect(1,2,3,4));
		EXPECT_TRUE(r == Rect::Null());
		EXPECT_TRUE(r.IsNull());
	}

	{
		// Rect self assignment
		Rect r(13,14,15,16);
		r = Rect(17,18,19,20);

		r = r;

		EXPECT_TRUE(r.GetX() == 17 && r.GetY() == 18 && r.GetW() == 19 && r.GetH() == 20);
	}

	{
		// Rect self move assignment
		Rect r(21,22,23,24);
		r = Rect(25,26,27,28);

		r = std::move(r);

		EXPECT_TRUE(r.GetX() == 25 && r.GetY() == 26 && r.GetW() == 27 && r.GetH() == 28);
	}

	{
		// Rect second point stuff
		Rect r(50,100,5,10);

		EXPECT_TRUE(r.GetX2() == 54 && r.GetY2() == 109);

		r.SetX2(50+15);
		r.SetY2(100+30);

		EXPECT_TRUE(r.GetW() == 16 && r.GetH() == 31);
	}
END_TEST()