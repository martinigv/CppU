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
	cout << "메모리 제거됨" << endl;
}
char Ram::read(int address) {
	return mem[address];
}
void Ram::write(int address, char value) {
	mem[address] = value;
}
// inline 함수로 만들려면 class 헤더파일 안에서 구현해야 하는 것을 확인함.
// 즉, Ram.h에 inline을 쓰면 실행이 정상적이게 되고,
// 이 파일에서 inline을 쓰면 실행이 안됨. 
