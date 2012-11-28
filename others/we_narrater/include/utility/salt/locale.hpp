#ifndef __salt_locale_HPP__
#define __salt_locale_HPP__

#include <string>

namespace _salt
{
    std::wstring string2wstring(const std::string& str);

    std::string wstring2string(const std::wstring& wstr);
}

#endif//__salt_locale_HPP__
