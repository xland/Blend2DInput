#pragma once

#include "WindowBase.h"

class WindowMain:public WindowBase
{
public:
	WindowMain();
	~WindowMain();
protected:
	void onShown() override;
	void onSize() override;
	void onKeyDown(const uint32_t& key) override;
	void onKeyDownWithCtrl(const uint32_t& key) override;

	void onMousePress(const int& x, const int& y) override;
	void onMouseDBClick(const int& x, const int& y) override;
	void onMouseRelease(const int& x, const int& y) override;
	void onMouseDrag(const int& x, const int& y) override;
	void onMouseMove(const int& x, const int& y) override;
	void onMousePressRight(const int& x, const int& y) override;

private:
	void initText();
	void initFont();
	void initPosSize();

	void paintText();
	void flashCaret();
	//void paintSelectedBg(SkCanvas* canvas);
	//void paintLine(const std::wstring& text, const int& lineIndex, SkCanvas* canvas);


	std::pair<float, float> setMouseAtIndex(const int& x, const int& y);

	void onKeyEnter();
	void onKeyBackspace();
	void onKeyDelete();
	void onKeyLeft();
	void onKeyUp();
	void onKeyRight();
	void onCopy();
	void onPaste();
	void onCut();
	void onSelectAll();
	void onChar(const unsigned int& val);

	bool enableAlpha();
	void activeKeyboard();
	bool hasSelection();
	void deleteSelection();
	void cancelSelection();
	std::wstring getClipboardText();
	std::array<int, 4> getSelectionArea();
	void saveToClipboard(const std::wstring& str);
	std::vector<std::wstring> textToLines(const std::wstring& text);
	std::string convertToUTF8(const std::wstring& wstr);
	std::string convertToUTF8(const LPWSTR& wstr);
private:
	std::wstring text{ LR"(破阵子·为陈同甫赋壮词以寄之
辛弃疾 · 宋 · XinQiJi(1140年－1207年) 

醉里挑灯看剑，梦回吹角连营。
八百里分麾下炙，五十弦翻塞外声，沙场秋点兵。
马作的卢飞快，弓如霹雳弦惊。
了却君王天下事，赢得生前身后名。可怜白发生！
)" };

	std::unique_ptr<BLFont> font;
	float fontTop, fontBottom, fontAsent, fontDesent;//fontAsent从基线到字体中最高字符顶部的距离,fTop 是从基线到字体中理论上最高点的距离。
	std::vector<std::wstring> lines;
	//std::map<int, std::vector<SkPoint>> wordPos;

	bool caretVisible{ true };
	int caretLineIndex{ -1 }, caretWordIndex{ -1 };
	int selectStartLine{ -1 }, selectStartWord{ -1 }, selectEndLine{ -1 }, selectEndWord{ -1 };
	float fontSize{ 26 };
	bool isMouseDown{ false };
	uint32_t colorBg{ 0XFFFFFFFF }, colorFore{ 0XFF000000 };
};