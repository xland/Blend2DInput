#pragma once
#include <string>
class Action
{
public:
    Action();
    ~Action();
public:
    std::wstring textBefore;
    std::wstring textAfter; 
    size_t cursorBefore;    
    size_t cursorAfter;     
};

