#include <iostream>
#include "Ram.h"
using namespace std;

Ram::Ram() {
	for (int i = 0; i < 102400; i++) {
		mem[i] = 0;
	}
	size = 100 * 1024;
}
Ram::~Ram() {
	cout << "�޸� ���ŵ�" << endl;
}
char Ram::read(int address) {
	return mem[address];
}
void Ram::write(int address, char value) {
	mem[address] = value;
}
// inline �Լ��� ������� class ������� �ȿ��� �����ؾ� �ϴ� ���� Ȯ����.
// ��, Ram.h�� inline�� ���� ������ �������̰� �ǰ�,
// �� ���Ͽ��� inline�� ���� ������ �ȵ�. 
