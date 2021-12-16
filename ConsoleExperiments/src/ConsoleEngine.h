#pragma once
#include <cstdint>
#include <Windows.h>

class Engine {
private:
	uint16_t m_screenWidth;
	uint16_t m_screenHeight;
	HANDLE display;
	DWORD writtenCharacters;
	WCHAR* screen;

public:
	Engine();
	~Engine();
	void updateFrame(WCHAR* content);
	uint16_t getScreenWidth();
	uint16_t getScreenHeight();

private:
	BOOL Frame();
};