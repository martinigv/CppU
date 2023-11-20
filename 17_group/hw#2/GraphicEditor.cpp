#include <iostream>
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "GraphicEditor.h"
#include "UI.h"

using namespace std;

void GraphicEditor::createNode(int n) {
	Shape* p = nullptr;
	switch (n) {
	case 1:
		p = new Line();
		break;
	case 2:
		p = new Circle();
		break;
	case 3:
		p = new Rect();
		break;
	default:
		break;
	}
	if (!head) {
		head = p;
		tail = p;
		return;
	}
	tail->add(p);
	tail = tail->getNext();
}

void GraphicEditor::deleteNode(int n) {
	Shape* pre = head;
	Shape* temp = head;
	if (!head) {
		cout << "삭제할 노드가 없어" << endl;
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		pre = temp->getNext();
		temp = temp->getNext();
	}
	if (temp == head) {
		head = temp->getNext();
		delete temp;
		return;
	}
	pre->add(temp->getNext());
	delete temp;
}

void GraphicEditor::showNodes() {
	Shape* temp = head;
	int index = 0;
	while (temp) {
		cout << index++ << ": ";
		temp->paint();
		temp = temp->getNext();
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