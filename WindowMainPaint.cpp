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

//void WindowMain::paintLine(const std::wstring& text, const int& lineIndex, SkCanvas* canvas)
//{
//    wordPos.insert({ lineIndex,std::vector<SkPoint>() });
//    SkPaint paint;
//    paint.setColor(colorFore);
//    paint.setStroke(false);
//    paint.setAntiAlias(true);
//    auto length = text.size() * sizeof(wchar_t);
//    std::vector<SkGlyphID> glyphs(text.size());
//    int glyphCount = font.textToGlyphs(text.data(), length, SkTextEncoding::kUTF16, glyphs.data(), text.size());
//    std::vector<SkScalar> widths(glyphCount);
//    font.getWidthsBounds(glyphs.data(), glyphCount, widths.data(), nullptr, nullptr);
//
//    SkScalar x = 12;
//    float height{ fontBottom - fontTop };
//    for (int i = 0; i < glyphCount; ++i) {
//        wordPos[lineIndex].push_back(SkPoint::Make(x, height));
//        x += widths[i]; // 累计宽度
//    }
//    wordPos[lineIndex].push_back(SkPoint::Make(x, height));
//    canvas->drawGlyphs(glyphCount, glyphs.data(), wordPos[lineIndex].data(), SkPoint(0, lineIndex * height), font, paint);
//}

void WindowMain::paintText()
{
    std::wstring text{ LR"(破阵子·为陈同甫赋壮词以寄之
辛弃疾 · 宋 · XinQiJi(1140年－1207年) 

醉里挑灯看剑，梦回吹角连营。
八百里分麾下炙，五十弦翻塞外声，沙场秋点兵。
马作的卢飞快，弓如霹雳弦惊。
了却君王天下事，赢得生前身后名。可怜白发生！
)" };

    auto ctx = getCtx();
    BLGlyphBuffer gb;
    BLTextMetrics tm;
    BLFontMetrics fm = font->metrics();

    double lineHeight = fm.ascent - fm.descent + fm.lineGap;
    double maxWidth = 400.0;  // 设定最大行宽
    double x = 12, y = 12 + fm.ascent;

    std::wstring line;
    double lineWidth = 0.0;

    for (wchar_t ch : text) {
        if (ch == L'\n') {  // 处理换行符
            gb.setWCharText(line.data());
            font->shape(gb);
            font->getTextMetrics(gb, tm);
            ctx->fillGlyphRun(BLPoint(x, y), *font.get(), gb.glyphRun(), BLRgba32(colorFore));

            line.clear();
            lineWidth = 0.0;
            y += lineHeight;
            continue;
        }

        std::wstring tempLine = line + ch;
        gb.setWCharText(tempLine.data());
        font->shape(gb);
        font->getTextMetrics(gb, tm);

        if (tm.boundingBox.x1 > maxWidth) {  // 超出最大宽度，换行
            gb.setWCharText(line.data());
            font->shape(gb);
            font->getTextMetrics(gb, tm);
            ctx->fillGlyphRun(BLPoint(x, y), *font.get(), gb.glyphRun(), BLRgba32(colorFore));

            line.clear();
            lineWidth = 0.0;
            y += lineHeight;
        }

        line += ch;
    }

    if (!line.empty()) {  // 绘制最后一行
        gb.setWCharText(line.data());
        font->shape(gb);
        font->getTextMetrics(gb, tm);
        ctx->fillGlyphRun(BLPoint(x, y), *font.get(), gb.glyphRun(), BLRgba32(colorFore));
    }



    //paintSelectedBg(canvas);
    //wordPos.clear();
    //int lineIndex{ 0 };
    //for (size_t i = 0; i < lines.size(); i++)
    //{
    //    paintLine(lines[i], i, canvas);
    //}
    //if (caretLineIndex < 0) {
    //    caretLineIndex = wordPos.size() - 1;
    //}
    //if (caretWordIndex < 0) {
    //    caretWordIndex = wordPos[wordPos.size() - 1].size() - 1;
    //}
    //caretVisible = true;
    //flashCaret();
}
