#include <string.h>
#include <iostream>

class Shape
{
public: 
	virtual void draw() = 0;
};

class Rectangle : public Shape 
{
public:
	void draw()
	{
		std::cout<< "Inside Rectangle::draw() method.\n" <<std::endl;
	}
};

class Square : public Shape
{	
public:
	void draw()
	{
		std::cout << "Inside Square::draw() method.\n" << std::endl;
	}
};
class Circle : public Shape
{
public:
	void draw()
	{
		std::cout << "Inside Circle::draw() method.\n" << std::endl;
	}
};

class ShapeFactory
{
public:
	Shape* GetShape(const char* shapeType)
	{
		if(shapeType == nullptr) return nullptr;
		if(strcmp(shapeType, "CIRCLE") == 0 )
		{
			return new Circle();	
		}
		if(strcmp(shapeType, "RECTANGLE") == 0 )
		{
			return new Rectangle();	
		}
		if(strcmp(shapeType, "SQUARE") == 0 )
		{
			return new Square();	
		}
		return nullptr;
	}
};

int main(int argc, char* argv[])
{
	ShapeFactory sf;
	std::cout << "----------------- 1 ------------------" << std::endl;
	//circle
	Shape* pS1 = sf.GetShape("CIRCLE");
	pS1->draw();

	std::cout << "----------------- 2 ------------------" << std::endl;
	Shape* pS2 = sf.GetShape("RECTANGLE");
	pS2->draw();

	std::cout << "----------------- 3 ------------------" << std::endl;
	Shape* pS3 = sf.GetShape("SQUARE");
	pS3->draw();

	return 0;
}










