#pragma once
#include "Shape.h"
class GraphicEditor {
	Shape* head;
	Shape* tail;
public:
	GraphicEditor() { head = tail = nullptr; }
	void createNode(int n);
	void deleteNode(int n);
	void showNodes();
	void run();
};
