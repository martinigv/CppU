#pragma once
#include <iostream>
using namespace std;

class UI {
public:
	static int nMenu() {
		int n;
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> n;
		return n;
	}

	static int nShape() {
		int n;
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> n;
		return n;
	}

	static int nDelete() {
		int n;
		cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
		cin >> n;
		return n;
	}
};
