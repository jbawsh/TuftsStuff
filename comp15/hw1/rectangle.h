// FILE: rectangle.h
// CLASS: rectangle
//
// CONSTRUCTORS for rectangle class:
// rectangle()
//   default constructor, creates unit square (width=1,length=1)
//
// rectangle(float side)
//   contructs a rectangle with width=side and height=side
//   assertion: side > 0
//
// rectangle(float w, float h)
//   constructs a rectangle with width=w and height=h
//   assertion: w > 0 and h > 0
// 
// GETTERS
//
// float getWidth()
//   returns width
//
// float getHeight()
//   returns height
//
// SETTERS
//
// void setWidth(float w)
//   sets width
//
// void setHeight(float h)
//   sets height
//
// OTHER MEMBER FUNCTIONS
//
// float perimeter()
//   returns the perimeter of the rectangle
//
// float area()
//   returns the area of the rectangle
//
// bool isSquare()
//   returns whether the rectangle is a square or not


#ifndef RECTANGLE_H
#define RECTANGLE_H

// epsilon for the float comparison
#define EPSILON (0.00001)

class rectangle {
	public:
		// CONSTRUCTORS
		rectangle();
		rectangle(float side);
		rectangle(float w, float h);

		// GETTERS
		float getWidth() ;
		float getHeight() ;

		// SETTERS
		void setWidth(float w) ;
		void setHeight(float h) ;

		// OTHER MEMBER FUNCTIONS
		float perimeter();
		float area();
		bool isSquare();

	private:
		float width,height;
};

#endif
