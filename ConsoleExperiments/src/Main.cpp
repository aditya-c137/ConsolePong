#include "ConsoleEngine.h"

#define OFFSET 120*5+30

#define OFFSET2 120*(40-6)+30

void setOffset(WCHAR*,int&,int);

int main() {
	Engine engine;

	WCHAR* content = new WCHAR[
		engine.getScreenHeight() * engine.getScreenWidth()
	];

	for (uint16_t i = 0; i < engine.getScreenHeight() * engine.getScreenWidth(); i++) {
		content[i] = '\0';
	}

	int i = 0 + OFFSET, j = -1, k = 0 + OFFSET2;
	int offset = 0;
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		engine.updateFrame(content);

		//train effect
		j = i == 0 + OFFSET ? (j + 1) % 26 : j;

		//setOffset(content, i, offset);

		content[i] = (WCHAR)(((i + j) % 7) + 65);	
		i = (i + 1) % (60) + OFFSET;

		content[k] = (WCHAR)(((k + j) % 7) + 65);
		k = (k + 1) % (60) + OFFSET2;
	}

	delete[] content;

	return 0;
}

void setOffset(WCHAR* content, int& position, int offset) {
	content[position] = (WCHAR)(((position) % 7) + 65);
	position = ((position + 1) % 60) + offset;
}