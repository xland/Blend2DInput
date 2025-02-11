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
    auto ctx = getCtx();
    BLGradient linear(BLLinearGradientValues(0, 0, 0, 480));
    linear.addStop(0.0, BLRgba32(0xFFFFFFFF));
    linear.addStop(0.5, BLRgba32(0xFF5FAFDF));
    linear.addStop(1.0, BLRgba32(0xFF2F5FDF));
    ctx.setFillStyle(linear);
    ctx.fillRoundRect(40.0, 40.0, 400.0, 400.0, 45.5);
    ctx.end();



    //BLFontFace face;
    //BLResult err = face.createFromFile("C:\\Windows\\Fonts\\msyh.ttc"); //黑体
    //if (err) {
    //    return;
    //}
    //BLFont font;
    //font.createFromFace(face, 16.0f);
    //ctx.fillAll(BLRgba32(colorBg));
    //ctx.setFillStyle(BLRgba32(colorFore));
    //std::string str{ "allen" };
    //ctx.fillUtf8Text(BLPoint(60, 80), font, str.c_str());



    //BLGlyphBuffer gb;
    //BLTextMetrics tm;
    //BLFontMetrics fm = font->metrics();
    //double y = 12 + fm.ascent;
    //std::wstring str{ L"测试"};
    //gb.setWCharText(str.data());
    //font->shape(gb);
    //font->getTextMetrics(gb, tm);
    //ctx.fillGlyphRun(BLPoint(12, y), *font.get(), gb.glyphRun(), BLRgba32(colorFore));
    //ctx.end();



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
