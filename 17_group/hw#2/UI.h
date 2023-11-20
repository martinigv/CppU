#pragma once
#include <iostream>
using namespace std;

class UI {
public:
	static int nMenu() {
		int n;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> n;
		return n;
	}

	static int nShape() {
		int n;
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> n;
		return n;
	}

	static int nDelete() {
		int n;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> n;
		return n;
	}
};
