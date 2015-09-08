#ifndef test_ccxGameNode_Label_h
#define test_ccxGameNode_Label_h

//CCLabel
Label* labelTTF(const char* string, const char* fontName, float size)
{
    return Label::createWithTTF(string, fontName, size);
}

Label* labelSystemTTF(const char* string, const char* fontName, float size)
{
    return Label::createWithSystemFont(string, fontName, size);
}

#endif
