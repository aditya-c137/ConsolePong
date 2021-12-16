#include "ConsoleEngine.h"

//public methods of engine
Engine::Engine():
	m_screenWidth(120),
	m_screenHeight(40),
	display(CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER,
		NULL
	)),
	writtenCharacters(0),
	screen(new WCHAR[m_screenWidth * m_screenHeight])
{
	SetConsoleActiveScreenBuffer(display);
}

void Engine::updateFrame(WCHAR* content) {
	memcpy(screen, content, m_screenWidth * m_screenHeight * sizeof(WCHAR));
	Frame();
}

Engine::~Engine() {
	delete[] screen;
}

uint16_t Engine::getScreenHeight() {
	return m_screenHeight;
}

uint16_t Engine::getScreenWidth() {
	return m_screenWidth;
}

//private methods of Engine
BOOL Engine::Frame() {
	screen[(m_screenHeight * m_screenWidth) - 1] = '\0';
	return WriteConsoleOutputCharacterW(
		display,
		screen,
		m_screenWidth * m_screenHeight,
		{0, 0},
		&writtenCharacters
	);
}