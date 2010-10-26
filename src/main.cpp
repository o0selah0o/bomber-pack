#include "Vue/View.h"
#include <iostream>
#include <vector>
#include <string>
#include "math.h"

int main()
{
	View* view = new View("","Fenetre principale", 640, 480);
	view->Run();
	return 0;
}