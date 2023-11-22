#pragma once
#include <vector>
#include "Shape.h"
class GraphicEditor {
	std::vector<Shape*> v;
	std::vector<Shape*>::iterator it;
public:
	GraphicEditor() { v = {}; it = v.begin(); }
	void createNode(int n);
	void deleteNode(int n);
	void showNodes();
	void run();
};
