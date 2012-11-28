#include "utility/salt/locale.hpp"
#include <stdlib.h>

using namespace std;

//////////////////////////////////////////////////////////////////////////
wstring _salt::string2wstring(const std::string& str)
{
    setlocale(LC_ALL, "zh_CN.utf-8");
    int len = mbstowcs(NULL, str.c_str(), 0);
    wchar_t* wstr = new wchar_t[len + 1];
    mbstowcs(wstr, str.c_str(), str.size());
    wstr[len] = 0;
    wstring result = wstr;
    delete[] wstr;
    return result;
}

//////////////////////////////////////////////////////////////////////////
string _salt::wstring2string(const std::wstring& wstr)
{
    setlocale(LC_ALL, "zh_CN.utf-8");
    int len = wcstombs(NULL, wstr.c_str(), 0);
    char* str = new char[len + 1];
    wcstombs(str, wstr.c_str(), 3 * wstr.size());
    str[len] = 0;
    string result = str;
    delete[] str;
    return result;
}
