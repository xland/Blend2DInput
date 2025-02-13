#include "WindowMain.h"


void WindowMain::flashCaret()
{
    //auto color = caretVisible ? colorFore : colorBg;
    //SkPoint p;
    //if (caretLineIndex == 0 && caretWordIndex == 0) {
    //    p = SkPoint(12, 0 - fontTop + fontDesent);
    //}
    //else {
    //    p = wordPos[caretLineIndex][caretWordIndex];
    //}
    //auto height{ fontBottom - fontTop };
    //SkPoint start = SkPoint(p.fX, p.fY + fontTop + caretLineIndex * height);// 字符顶部相对于基线的偏移  neagtive
    //SkPoint end = SkPoint(p.fX, p.fY + fontBottom + caretLineIndex * height); // 字符底部相对于基线的偏移
    //auto canvas = ctx->getCanvas();
    //SkPaint paint;
    //paint.setColor(color);
    //paint.setStroke(true);
    //paint.setStrokeWidth(1);
    //canvas->drawLine(start, end, paint);
    //caretVisible = !caretVisible;
}
//void WindowMain::paintSelectedBg(SkCanvas* canvas) {
//    if (selectStartLine == -1 || selectStartWord == -1 || selectEndLine == -1 || selectEndWord == -1) {
//        return;
//    }
//	if (selectStartLine == selectEndLine && selectStartWord == selectEndWord) {
//		return;
//	}
//    auto [startLine, startWord, endLine, endWord ] = getSelectionArea();
//    auto height{ fontBottom - fontTop };
//    SkPaint paint;
//    paint.setColor(0X66000000);
//    for (size_t i = startLine; i <= endLine; i++)
//    {
//        float l, t, r, b;
//        if (i == startLine) {
//            auto p = wordPos[i][startWord];
//            l = p.fX; 
//            t = p.fY + fontTop + i * height;
//            b = p.fY + fontBottom + i * height;
//        }
//        else {
//            auto p = wordPos[i][0];
//            l = p.fX;
//            t = p.fY + fontTop + i * height;
//            b = p.fY + fontBottom + i * height;
//        }
//        if (i == endLine) {
//            auto p = wordPos[endLine][endWord];
//            r = p.fX;
//        }
//        else {
//            auto p = wordPos[i][wordPos[i].size()-1];
//            r = p.fX;
//        }
//        canvas->drawRect(SkRect::MakeLTRB(l, t, r, b),paint);
//    }
//}

void WindowMain::paintText()
{
    auto ctx = getCtx();
    ctx->fillAll(BLRgba32(colorBg));
    BLGlyphBuffer gb;
    BLTextMetrics tm;
    BLFontMetrics fm = font->metrics();
    float lineHeight = fm.ascent - fm.descent + fm.lineGap + lineSpan;
    float x = padding, y = padding + fm.ascent;
    std::wstring line;
    for (wchar_t ch : text) {
        if (ch == L'\n') {
            gb.setWCharText(line.data());
            font->shape(gb);
            font->getTextMetrics(gb, tm);
            ctx->fillGlyphRun(BLPoint(x, y), *font.get(), gb.glyphRun(), BLRgba32(colorFore));
            line.clear();
            y += lineHeight;
        }
        else {
            line += ch;
        }
    }
    if (!line.empty()) {
        gb.setWCharText(line.data());
        font->shape(gb);
        font->getTextMetrics(gb, tm);
        ctx->fillGlyphRun(BLPoint(x, y), *font.get(), gb.glyphRun(), BLRgba32(colorFore));
    }
}
