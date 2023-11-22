#include <iostream>
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "GraphicEditor.h"
#include "UI.h"

using namespace std;

void GraphicEditor::createNode(int n) {
	switch (n) {
	case 1:
		v.push_back(new Line());
		break;
	case 2:
		v.push_back(new Circle());
		break;
	case 3:
		v.push_back(new Rect());
		break;
	default:
		break;
	}
}

void GraphicEditor::deleteNode(int n) {

	if (n >= v.size() || n < 0) {
		cout << "index 에러" << endl;
		return;
	}
	it = v.begin();
	Shape* temp = *(it + n);
	v.erase(it + n);
	delete temp;
}

void GraphicEditor::showNodes() {
	int i = 0;
	for (Shape* p : v) {
		cout << i++ << ": ";
		p->paint();
	}
}

void GraphicEditor::run() {
	cout << "그래픽 에디터입니다." << endl;
	int n, deleteN, createN;
	while (true) {
		n = UI::nMenu();
		switch (n) {
		case 1:
			createN = UI::nShape();
			createNode(createN);
			break;
		case 2:
			deleteN = UI::nDelete();
			deleteNode(deleteN);
			break;
		case 3:
			showNodes();
			break;
		case 4:
			return;
		default:
			cout << "다시 선택해라" << endl;
		}
	}
}