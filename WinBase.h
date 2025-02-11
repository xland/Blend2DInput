#pragma once
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <array>
#include <thread>
#include <windows.h>
#include <windowsx.h>
#include <Blend2D.h>


class WinBase
{
public:
	WinBase();
	~WinBase();
	void show();
public:
	int x, y, w, h;
	HWND hwnd;
protected:
	void createWindow();
	BLContext getCtx();
	//virtual void paint(SkCanvas* canvas) {};
	virtual LRESULT CALLBACK procMsg(UINT msg, WPARAM wParam, LPARAM lParam);
	virtual void onShown() {};
	virtual void onSize() {};
protected:
	std::unique_ptr<BLImage> img;
private:
	void paintWin();
	static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);	
};
