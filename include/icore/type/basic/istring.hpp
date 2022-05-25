/**
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:istring.hpp
* @creation time:2022.5.4 12:50
* @created by: ticks-tan
* -----------------------------------------------------------------------------
* Extension to standard string
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/

#ifndef ___MIRACLEFOREST_I_ISTRING___
#define ___MIRACLEFOREST_I_ISTRING___

#include "../../family/imacrofamily.h"
#include "../type/type_traits.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <set>
#include <list>
#include <map>
#ifdef __WINDOWS__
#include <windows.h>
#include <stringapiset.h>
#endif
#ifdef __CPP_20__
#include <format>
#endif

namespace i {
    namespace core {
        namespace type {
            namespace basic {
#ifdef __CPP_20__
                template <typename Type> requires type_traits::is_std_string_v<Type>
#else
                template <typename Type, std::enable_if_t<type_traits::is_std_string_v<Type>, Type> = 0>
#endif
                class istring final {
                public:

                    /// <summary>
                    /// typedef same as strString typedef
                    /// </summary>
                    typedef typename Type::traits_type traits_type;
                    typedef typename Type::value_type value_type;
                    typedef typename Type::allocator_type allocator_type;
                    typedef typename Type::size_type size_type;
                    typedef typename Type::difference_type difference_type;
                    typedef typename Type::reference reference;
                    typedef typename Type::const_reference const_reference;
                    typedef typename Type::pointer pointer;
                    typedef typename Type::const_pointer const_pointer;
                    typedef typename Type::iterator iterator;
                    typedef typename Type::const_iterator const_iterator;
                    typedef typename Type::reverse_iterator reverse_iterator;
                    typedef typename Type::const_reverse_iterator const_reverse_iterator;
                    static const size_type npos = Type::npos;
                public:
                    /// <summary>
                    /// istring all Constructor
                    /// </summary>
                    explicit istring()
                        : _data() {}

                    explicit istring(const Type& str)
                        : _data(str) {}

                    explicit istring(Type&& str) noexcept
                        : _data(str) {}

                    istring(size_type count, value_type ch)
                        : _data(count, ch) {}

                    istring(const istring& other, size_type pos, size_t count)
                        : _data(other, pos, count) {}

                    istring(const istring& other, size_type pos)
                        : _data(other, pos) {}

                    istring(const value_type* s, size_type count)
                        : _data(s, count) {}

                    istring(const value_type* s)
                        : _data(s) {}

                    istring(const istring& other)
                        : _data(other._data) {}

                    istring(istring&& other) noexcept
                        : _data(std::move(other._data)) {}

                    istring(std::initializer_list<value_type> ilist)
                        : _data(ilist) {}

                    template<class InputIt> istring(InputIt first, InputIt last)
                        : _data(first, last) {}

                    ~istring() {}

                    /// <summary>
                    /// istring assign as stdString assign
                    /// </summary>
                    istring& assign(size_type count, value_type ch)
                    {
                        this->_data.assign(count, ch);
                        return *this;
                    }

                    istring& assign(const istring& str)
                    {
                        if (*this == str) {
                            return *this;
                        }
                        this->_data.assign(str._data);
                        return *this;
                    }

                    istring& assign(const istring& str, size_type pos, size_type count)
                    {
                        this->_data.assign(str._data, pos, count);
                        return *this;
                    }

                    istring& assign(const istring& str, size_type pos)
                    {
                        this->_data.assign(str._data, pos);
                        return *this;
                    }

                    istring& assign(istring&& str) noexcept
                    {
                        this->_data.assign(std::move(str._data));
                        return this;
                    }

                    istring& assign(const value_type* s, size_type count)
                    {
                        this->_data.assign(s, count);
                        return *this;
                    }

                    istring& assign(const value_type* s)
                    {
                        this->_data.assign(s);
                        return *this;
                    }

                    istring& assign(std::initializer_list<value_type> ilist)
                    {
                        this->_data.assign(ilist);
                        return *this;
                    }

                    template<class InputIt> istring& assign(InputIt first, InputIt last)
                    {
                        this->_data.assign(first, last);
                        return *this;
                    }

                    /// <summary>
                    /// get the stdString allocator
                    /// </summary>
                    allocator_type getAllocator() const
                    {
                        return this->_data.get_allocator();
                    }

                    /// <summary>
                    /// get the istring char at pos
                    /// </summary>
                    /// <warning>
                    /// exception : when pos >= length() throw std::out_of_range
                    /// </warning>
                    reference charAt(size_type pos)
                    {
                        return this->_data.at(pos);
                    }

                    const_reference charAt(size_type pos) const
                    {
                        return this->_data.at(pos);
                    }

                    /// <summary>
                    /// get istring first char
                    /// </summary>
                    /// <warning>
                    /// if istring length() == 0, the behavior is undefined
                    /// </warning>
                    reference front()
                    {
                        return this->_data.front();
                    }

                    const_reference front() const
                    {
                        return this->_data.front();
                    }

                    /// <summary>
                    /// get istring last char
                    /// </summary>
                    /// <warning>
                    /// if istring length() == 0, the behavior is undefined
                    /// </warning>
                    reference back()
                    {
                        return this->_data.back();
                    }

                    const_reference back() const
                    {
                        return this->_data.back();
                    }

                    /// <summary>
                    /// get istring string pointer
                    /// </summary>
                    Type data() const noexcept
                    {
                        return this->_data;
                    }

                    Type& data() noexcept
                    {
                        return this->_data;
                    }

                    /// <summary>
                    /// get istring c style string
                    /// </summary>
                    const value_type* cStr() const noexcept
                    {
                        return this->_data.data();
                    }

                    /// <summary>
                    /// get istring first  iterator
                    /// </summary>
                    iterator begin() noexcept
                    {
                        return this->_data.begin();
                    }

                    const_iterator begin() const noexcept
                    {
                        return this->_data.begin();
                    }

                    const_iterator cbegin() const noexcept
                    {
                        return this->_data.cbegin();
                    }

                    /// <summary>
                    /// get istring last iterator
                    /// </summary>
                    iterator end() noexcept
                    {
                        return this->_data.end();
                    }

                    const_iterator end() const noexcept
                    {
                        return this->_data.end();
                    }

                    const_iterator cend() const noexcept
                    {
                        return this->_data.cend();
                    }

                    /// <summary>
                    /// get istring first reverse iterator
                    /// </summary>
                    reverse_iterator rbegin() noexcept
                    {
                        return this->_data.rbegin();
                    }

                    const_reverse_iterator rbegin() const noexcept
                    {
                        return this->_data.rbegin();
                    }

                    const_reverse_iterator crbegin() const noexcept
                    {
                        return this->_data.crbegin();
                    }

                    /// <summary>
                    /// get istring last reverse iterator
                    /// </summary>
                    reverse_iterator rend() noexcept
                    {
                        return this->_data.rend();
                    }

                    const_reverse_iterator rend() const noexcept
                    {
                        return this->_data.rend();
                    }

                    const_reverse_iterator crend() const noexcept
                    {
                        return this->_data.crend();
                    }

                    /// <summary>
                    /// check istring length() == 0
                    /// </summary>
                    bool empty() const noexcept
                    {
                        return this->_data.empty();
                    }

                    /// <summary>
                    /// get istring length
                    /// </summary>
                    size_type length() const noexcept
                    {
                        return this->_data.length();
                    }

                    size_type size() const noexcept
                    {
                        return this->_data.size();
                    }

                    /// <summary>
                    /// get istring max contain
                    /// </summary>
                    size_type maxSize() const noexcept
                    {
                        return this->_data.max_size();
                    }

                    /// <summary>
                    /// set istring alloc size
                    /// </summary>
                    void reserve(size_type new_cap = static_cast<size_type>(0))
                    {
                        this->_data.reserve(new_cap);
                    }

                    /// <summary>
                    /// get istring alloc current size
                    /// </summary>
                    size_type capacity() const noexcept
                    {
                        return this->_data.capacity();
                    }

                    /// <summary>
                    /// fit current alloc size to current string size
                    /// </summary>
                    void fitAllocSize()
                    {
                        this->_data.shrink_to_fit();
                    }

                    /// <summary>
                    /// clear istring
                    /// </summary>
                    void clear() noexcept
                    {
                        this->_data.clear();
                    }

                    /// <summary>
                    /// insert ch or string to istring
                    /// </summary>
                    istring& insert(size_type pos, size_type count, value_type ch)
                    {
                        this->_data.insert(pos, count, ch);
                        return *this;
                    }

                    istring& insert(size_type pos, const value_type* s, size_type count)
                    {
                        this->_data.insert(pos, s, count);
                        return *this;
                    }

                    istring& insert(size_type pos, const value_type* s)
                    {
                        this->_data.insert(pos, s);
                        return *this;
                    }

                    istring& insert(size_type pos, const istring& str)
                    {
                        this->_data.insert(pos, str);
                        return *this;
                    }

                    istring& insert(size_type pos, const istring& str, size_type str_pos, size_type str_count)
                    {
                        this->_data.insert(pos, str, str_pos, str_count);
                        return *this;
                    }

                    istring& insert(size_type pos, const istring& str, size_type str_pos)
                    {
                        this->_data.insert(pos, str, str_pos);
                        return *this;
                    }

                    iterator insert(const_iterator pos, value_type ch)
                    {
                        return this->_data.insert(pos, ch);
                    }

                    iterator insert(const_iterator pos, size_type count, value_type ch)
                    {
                        return this->_data.insert(pos, count, ch);
                    }

                    iterator insert(const_iterator pos, std::initializer_list<value_type> ilist)
                    {
                        return this->_data.insert(pos, ilist);
                    }

                    template<class InputIt> iterator insert(const_iterator pos, InputIt first, InputIt last)
                    {
                        return this->_data.insert(pos, first, last);
                    }

                    /// <summary>
                    /// erase the char or str in istring
                    /// </summary>
                    istring& erase(size_type pos = 0, size_type count = istring::npos)
                    {
                        this->_data.erase(pos, count);
                        return *this;
                    }

                    iterator erase(const_iterator pos)
                    {
                        return this->_data.erase(pos);
                    }

                    iterator erase(const_iterator first, const_iterator last)
                    {
                        return this->_data.erase(first, last);
                    }

                    /// <summary>
                    /// add a char in istring end
                    /// </summary>
                    void pushBack(value_type ch)
                    {
                        this->_data.push_back(ch);
                    }

                    /// <summary>
                    /// remove istring last char
                    /// </summary>
                    /// <warning>
                    /// if istring length() == 0 , the behavior is undefined
                    /// <warning>
                    void popBack()
                    {
                        this->_data.pop_back();
                    }

                    /// <summary>
                    /// append char or string in istring
                    /// </summary>
                    istring& append(size_type count, value_type ch)
                    {
                        this->_data.append(count, ch);
                        return *this;
                    }

                    istring& append(const istring& str)
                    {
                        this->_data.append(str._data);
                        return *this;
                    }

                    istring& append(istring&& str)
                    {
                        this->_data.append(std::move(str._data));
                    }

                    istring& append(const Type& str)
                    {
                        this->_data.append(str);
                        return *this;
                    }

                    istring& append(const istring& str, size_type pos, size_type count)
                    {
                        this->_data.append(str._data, pos, count);
                        return *this;
                    }

                    istring& append(const istring& str, size_type pos)
                    {
                        this->_data.append(str._data, pos);
                        return *this;
                    }

                    istring& append(const value_type* s, size_type count)
                    {
                        this->_data.append(s, count);
                        return *this;
                    }

                    istring& append(const value_type* s)
                    {
                        this->_data.append(s);
                        return *this;
                    }

                    istring& append(std::initializer_list<value_type> ilist)
                    {
                        this->_data.append(ilist);
                        return *this;
                    }

                    istring& append(value_type ch)
                    {
                        this->_data.push_back(ch);
                        return *this;
                    }

                    template <typename InputIt> istring& append(InputIt first, InputIt last)
                    {
                        this->_data.append(first, last);
                        return *this;
                    }

                    /// <summary>
                    /// append number in istring
                    /// </summary>
                    istring& append(int i)
                    {
                        return this->append(std::move(istring::valueOf(i)));
                    }

                    istring& append(i::core::uint ui)
                    {
                        return this->append(std::move(istring::valueOf(ui)));
                    }

                    istring& append(long l)
                    {
                        return this->append(std::move(istring::valueOf(l)));
                    }

                    istring& append(i::core::ulong ul)
                    {
                        return this->append(std::move(istring::valueOf(ul)));
                    }

                    istring& append(long long ll)
                    {
                        return this->append(std::move(istring::valueOf(ll)));
                    }

                    istring& append(i::core::uint64 ull)
                    {
                        return this->append(std::move(istring::valueOf(ull)));
                    }

                    istring& append(float f)
                    {
                        return this->append(std::move(istring::valueOf(f)));
                    }

                    istring& append(double d)
                    {
                        return this->append(std::move(istring::valueOf(d)));
                    }

                    /// <summary>
                    /// replace some str in istring
                    /// </summary>
                    istring& replace(size_type pos, size_type count, const istring& str)
                    {
                        this->_data.replace(pos, count, str._data);
                        return *this;
                    }

                    istring& replace(const_iterator first, const_iterator last, const istring& str)
                    {
                        this->_data.replace(first, last, str._data);
                        return *this;
                    }

                    istring& replace(size_type pos, size_type count, const istring& str,
                        size_type str_pos, size_type str_count = istring::npos)
                    {
                        this->_data.replace(pos, count, str._data, str_pos, str_count);
                        return *this;
                    }

                    template <typename InputIt>
                    istring& replace(const_iterator first, const_iterator last, InputIt first1, InputIt last1)
                    {
                        this->_data.replace(first, last, first1, last1);
                        return *this;
                    }

                    istring& replace(size_type pos, size_type count, const value_type* s, size_type s_count)
                    {
                        this->_data.replace(pos, count, s, s_count);
                        return *this;
                    }

                    istring& replace(size_type pos, size_type count, const value_type* s)
                    {
                        this->_data.replace(pos, count, s);
                        return *this;
                    }

                    istring& replace(const_iterator first, const_iterator last, const value_type* s)
                    {
                        this->_data.replace(first, last, s);
                        return *this;
                    }

                    istring& replace(size_type pos, size_type count, size_type ch_count, value_type ch)
                    {
                        this->_data.replace(pos, count, ch_count, ch);
                        return *this;
                    }

                    istring& replace(const_iterator first, const_iterator last, size_type count, value_type ch)
                    {
                        this->_data.replace(first, last, count, ch);
                        return *this;
                    }

                    istring& replace(const_iterator first, const_iterator last, std::initializer_list<value_type> ilist)
                    {
                        this->_data.replace(first, last, ilist);
                        return *this;
                    }

                    istring& replace(size_type pos, size_type count, std::initializer_list<value_type> ilist)
                    {
                        this->_data.replace(this->_data.begin() + pos, this->_data.begin() + pos + count, ilist);
                        return *this;
                    }

                    /// <summary>
                    /// get istring sub string in [pos, pos + count)
                    /// </summary>
                    istring substr(size_type pos = 0, size_type count = istring::npos) const
                    {
                        istring str(this->_data.substr(pos, count).data());
                        return std::move(str);
                    }

                    /// <summary>
                    /// copy istring [pos, count) str to dest
                    /// </summary>
                    /// <warning>
                    /// if pos > length(), throw std::out_of_range()
                    /// </warning>
                    size_type copy(value_type* dest, size_type count, size_type pos = 0) const
                    {
                        return this->_data.copy(dest, count, pos);
                    }

                    /// <summary>
                    /// set istring ch count to count
                    /// </summary>
                    void resize(size_type count)
                    {
                        this->_data.resize(count);
                    }

                    void resize(size_type count, value_type ch)
                    {
                        this->_data.resize(count, ch);
                    }

                    void swap(istring& other)
                    {
                        if (*this == other) {
                            return;
                        }
                        this->_data.swap(other._data);
                    }

                    /// <summary>
                    /// find the str or ch in istring
                    /// </summary>
                    size_type find(const istring& str, size_type pos = 0) const
                    {
                        return this->_data.find(str._data, pos);
                    }

                    size_type find(const value_type* s, size_type pos, size_type count) const
                    {
                        return this->_data.find(s, pos, count);
                    }

                    size_type find(const value_type* s, size_type pos = 0) const
                    {
                        return this->_data.find(s, pos);
                    }

                    size_type find(value_type ch, size_type pos = 0) const
                    {
                        return this->_data.rfind(ch, pos);
                    }

                    size_type rfind(const istring& str, size_type pos = istring::npos) const
                    {
                        return this->_data.rfind(str._data, pos);
                    }

                    size_type rfind(const value_type* s, size_type pos, size_type count) const
                    {
                        return this->_data.rfind(s, pos, count);
                    }

                    size_type rfind(const value_type* s, size_type pos = istring::npos) const
                    {
                        return this->_data.rfind(s, pos);
                    }

                    size_type rfind(value_type ch, size_type pos = istring::npos) const
                    {
                        return this->_data.rfind(ch, pos);
                    }

                    /// <summary>
                    /// check istring start with str
                    /// </summary>
                    bool startsWith(const istring& str)
                    {
#ifdef __CPP_20__
                        return this->_data.starts_with(str._data);
#else
                        return istring::startsWith(str, *this);
#endif
                    }

                    /// <summary>
                    /// check istring end with str
                    /// </summary>
                    bool endsWith(const istring& str)
                    {
#ifdef __CPP_20__
                        return this->_data.ends_with(str._data);
#else
                        return istring::endsWith(str, *this);
#endif
                    }

                    /// <summary>
                    /// split istring with  char
                    /// </summary>
                    std::vector<istring> split(value_type ch)
                    {
                        std::vector<istring> strs;
                        size_type pos = this->find(ch), start = 0;
                        while (pos != istring::npos) {
                            strs.push_back(this->substr(start, pos));
                            start = pos + 1;
                            pos = this->find(ch, pos + 1);
                        }
                        if (start < this->length()) {
                            strs.push_back(this->substr(start));
                        }
                        return std::move(strs);
                    }

                    /// <summary>
                    /// match the istring with regex
                    /// </summary>
                    bool match(const std::basic_regex<value_type>& regex, bool search = false)
                    {
                        if (!search) {
                            return std::regex_match(this->_data, regex);
                        }
                        return std::regex_search(this->_data, regex);
                    }

                    std::match_results<const value_type*> matchResult(const std::basic_regex<value_type>& regex, bool search)
                    {
                        std::match_results<const value_type*> result;
                        if (!search) {
                            std::regex_match(this->_data, result, regex);
                        }
                        else {
                            std::regex_search(this->_data, result, regex);
                        }
                        return result;
                    }
                public:
                    template<typename Type>
                    static std::string toStdString(Type value) {
                        return std::to_string(value);
                    }

                    static std::string toStdString(const char* value) {
                        return std::string(value);
                    }

                    static std::string toStdString(char value) {
                        return std::string(1, value);
                    }

                    static std::string toStdString(const std::string& value) {
                        return value;
                    }

                    static std::string toStdString(const wchar_t value) {
                        return wideChar2UTF8(std::wstring(1, value));
                    }

                    static std::string toStdString(const wchar_t* value) {
                        return wideChar2UTF8(value);
                    }

                    /// <summary>
                    /// toWideChar
                    /// </summary>
                    /// <param name="code_page">code_page</param>
                    /// <param name="src_str">src_str</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>wstring</returns>
                    static std::wstring toWideChar(std::uint32_t code_page, const std::string& src_str) {
                        if (src_str.empty()) {
                            return L"";
                        }
                        auto len = MultiByteToWideChar(code_page, 0, src_str.c_str(), -1, nullptr, 0);
                        if (!len) {
                            return L"";
                        }
                        auto wstr_c = new wchar_t[len + 1];
                        if (!wstr_c) {
                            return L"";
                        }
                        memset(wstr_c, 0, len + 1);
                        MultiByteToWideChar(code_page, 0, src_str.c_str(), -1, wstr_c, len);
                        std::wstring wstr(wstr_c);
                        delete[] wstr_c;
                        return wstr;
                    }

                    /// <summary>
                    /// wideChar2string
                    /// </summary>
                    /// <param name="code_page">code_page</param>
                    /// <param name="src_wstr">src_wstr</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>string</returns>
                    static std::string fromWideChar(std::uint32_t code_page, const std::wstring& src_wstr) {
                        if (src_wstr.empty()) {
                            return "";
                        }
                        auto len = WideCharToMultiByte(code_page, 0, src_wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
                        if (!len) {
                            return "";
                        }
                        auto str_c = new char[len + 1];
                        if (!str_c) {
                            return "";
                        }
                        memset(str_c, 0, len + 1);
                        WideCharToMultiByte(code_page, 0, src_wstr.c_str(), -1, str_c, len, nullptr, nullptr);
                        std::string str(str_c);
                        delete[] str_c;
                        return str;
                    }

                    /// <summary>
                    /// isWideCharHex
                    /// </summary>
                    /// <param name="wch">wchar_t value</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>isWideCharHex</returns>
                    static bool isWideCharHex(wchar_t wch) {
                        return (wch >= L'0' && wch <= L'9') || (wch >= L'a' && wch <= L'f') || (wch >= L'A' && wch <= L'F');
                    }

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="wch"></param>
                    /// <returns></returns>
                    static std::uint8_t wideChar2hex(wchar_t wch) {
                        if (wch >= L'0' && wch <= L'9') {
                            return wch - L'0';
                        }
                        else if (wch >= L'a' && wch <= L'f') {
                            return wch - L'a' + 10;
                        }
                        else {// wch >= L'A' && wch <= L'F'
                            return wch - L'A' + 10;
                        }
                    }

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="hex"></param>
                    /// <returns></returns>
                    static char hex2char(uint8_t hex) {
                        if (hex <= 9) {
                            return '0' + hex;
                        }
                        else { // hex >= 10 && hex <= 15
                            return 'a' + hex - 10;
                        }
                    }

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="wch"></param>
                    /// <returns></returns>
                    static std::string wideChar2UCS2(wchar_t wch) {
                        auto wch_value = static_cast<uint16_t>(wch);
                        std::string ucs2;
                        ucs2.reserve(6);
                        ucs2 += "\\u";
                        ucs2 += hex2char(wch_value >> 12);
                        ucs2 += hex2char((wch_value >> 8) & 0xf);
                        ucs2 += hex2char((wch_value >> 4) & 0xf);
                        ucs2 += hex2char(wch_value & 0xf);
                        return ucs2;
                    }

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="hex"></param>
                    /// <returns></returns>
                    static char hex2wideChar(uint8_t hex) {
                        if (hex <= 9) {
                            return L'0' + hex;
                        }
                        else {
                            return L'a' + hex - 10;
                        }
                    }

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="wch"></param>
                    /// <returns></returns>
                    static std::wstring wideChar2wideCharUCS2(wchar_t wch) {
                        auto wch_value = static_cast<uint16_t>(wch);
                        std::wstring ucs2;
                        ucs2.reserve(6);
                        ucs2 += L"\\u";
                        ucs2 += hex2wideChar(wch_value >> 12);
                        ucs2 += hex2wideChar((wch_value >> 8) & 0xf);
                        ucs2 += hex2wideChar((wch_value >> 4) & 0xf);
                        ucs2 += hex2wideChar(wch_value & 0xf);
                        return ucs2;
                    }

                    /// <summary>
                    /// Convert a UTF8 encoded string to a wide string
                    /// </summary>
                    /// <param name="utf8"></param>
                    /// <returns>The converted wide string</returns>
                    static std::wstring UTF82wideChar(const std::string& utf8) {
                        return toWideChar(CP_UTF8, utf8);
                    }

                    /// <summary>
                    /// Convert wide strings to UTF8-encoded strings
                    /// </summary>
                    /// <param name="wstr"></param>
                    /// <returns>The converted UTF8 encoded string</returns>
                    static std::string wideChar2UTF8(const std::wstring& wstr) {
                        return fromWideChar(CP_UTF8, wstr);
                    }

                    /// <summary>
                    /// Convert ANSI-encoded strings to wide strings
                    /// </summary>
                    /// <param name="ansi">ANSI-encoded string to be converted</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>The converted wide string</returns>
                    static std::wstring ANSI2wideChar(const std::string& ansi) {
                        return toWideChar(CP_ACP, ansi);
                    }

                    /// <summary>
                    /// Convert wide strings to ANSI-encoded strings
                    /// </summary>
                    /// <param name="wstr">The wide string to be converted into an encoding</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>Converted ANSI-encoded string</returns>
                    static std::string wideChar2ANSI(const std::wstring& wstr) {
                        return fromWideChar(CP_ACP, wstr);
                    }

                    /// <summary>
                    /// Convert ANSI-encoded mixed UCS2 encoded strings to wide strings
                    /// </summary>
                    /// <param name="ansi_with_ucs2">ANSI-encoded mixed UCS2 encoded strings to be converted</param>
                    /// <param name="not_unescape_wide_chars">Wide character set without inverse escaping</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>The converted wide string</returns>
                    static std::wstring ANSIWithUCS22WideChar(const std::string& ansi_with_ucs2, const std::wstring& not_unescape_wide_chars) {
                        return unescapeWideChar(ANSI2wideChar(ansi_with_ucs2), not_unescape_wide_chars);
                    }

                    /// <summary>
                    /// Convert wide strings to ANSI-encoded mixed UCS2 encoded strings
                    /// </summary>
                    /// <param name="wstr">Wide string of codes to be converted</param>
                    /// <param name="force_escape_wide_chars">Wide set of characters to be forcibly escaped</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>Converted ANSI-encoded mixed UCS2 encoded strings</returns>
                    static std::string wideChar2ANSIWithUCS2(const std::wstring& wstr, const std::wstring& force_escape_wide_chars) {
                        if (wstr.empty()) {
                            return "";
                        }
                        BOOL need_escape = FALSE;
                        if (!force_escape_wide_chars.empty()) {
                            for (auto wch : wstr) {
                                if (force_escape_wide_chars.find(wch) != std::wstring::npos) {
                                    need_escape = TRUE;
                                    break;
                                }
                            }
                        }
                        int len;
                        if (need_escape == FALSE) {
                            need_escape = FALSE;
                            len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, &need_escape);
                            if (!len) {
                                return "";
                            }
                        }
                        if (!need_escape) {
                            auto ansi_c = new char[len + 1];
                            if (!ansi_c) {
                                return "";
                            }
                            memset(ansi_c, 0, len + 1);
                            WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, ansi_c, len, nullptr, nullptr);
                            std::string ansi(ansi_c);
                            delete[] ansi_c;
                            return ansi;
                        }
                        else {
                            auto wstr_c_tmp = new wchar_t[2];
                            if (!wstr_c_tmp) {
                                return "";
                            }
                            wstr_c_tmp[1] = L'\0';
                            auto ansi_c_tmp = new char[8];
                            if (!ansi_c_tmp) {
                                delete[] wstr_c_tmp;
                                return "";
                            }
                            std::string ansi_with_ucs2;
                            for (auto it : wstr) {
                                if (force_escape_wide_chars.find(it) == std::wstring::npos) {
                                    if (static_cast<uint16_t>(it) <= 0x7f) {
                                        ansi_with_ucs2 += static_cast<char>(it);
                                        continue;
                                    }
                                    else if ((uint16_t)(it) >> 11 != 0b11011) {
                                        need_escape = FALSE;
                                        wstr_c_tmp[0] = it;
                                        auto len = WideCharToMultiByte(CP_ACP, 0, wstr_c_tmp, -1, nullptr, 0, nullptr, &need_escape);
                                        if (!len) {
                                            delete[] wstr_c_tmp;
                                            delete[] ansi_c_tmp;
                                            return "";
                                        }
                                        if (!need_escape) {
                                            memset(ansi_c_tmp, 0, len + 1);
                                            WideCharToMultiByte(CP_ACP, 0, wstr_c_tmp, -1, ansi_c_tmp, len, nullptr, nullptr);
                                            ansi_with_ucs2 += ansi_c_tmp;
                                            continue;
                                        }
                                    }
                                }
                                ansi_with_ucs2 += wideChar2UCS2(it);
                            }
                            delete[] wstr_c_tmp;
                            delete[] ansi_c_tmp;
                            return ansi_with_ucs2;
                        }
                    }

                    /// <summary>
                    /// Escape wide strings
                    /// </summary>
                    /// <param name="wstr">Wide string containing the wide characters to be escaped</param>
                    /// <param name="escape_wide_chars">Wide set of characters to be escaped</param>
                    /// <warning>null</warning>
                    /// <include>
                    /// string
                    /// </include>
                    /// <bug>null</bug>
                    /// <returns>The escaped wide string</returns>
                    static std::wstring escapeWideChar(const std::wstring& wstr, const std::wstring& escape_wide_chars) {
                        if (wstr.empty()) {
                            return L"";
                        }
                        if (escape_wide_chars.empty()) {
                            return wstr;
                        }
                        std::wstring wstr_with_ucs2;
                        for (wchar_t wch : wstr) {
                            if (escape_wide_chars.find(wch) == std::wstring::npos) {
                                wstr_with_ucs2 += wch;
                            }
                            else {
                                wstr_with_ucs2 += wideChar2wideCharUCS2(wch);
                            }
                        }
                        return wstr_with_ucs2;
                    }

                    /// <summary>
                    /// Inverse Escape Wide String
                    /// </summary>
                    /// <param name="wstr_with_ucs2">Wide strings to be inverse-translated</param>
                    /// <param name="not_unescape_wide_chars">Wide character set without inverse escaping</param>
                    /// <warning>null</warning>
                    /// <include>
                    /// string
                    /// </include>
                    /// <bug>null</bug>
                    /// <returns>Wide string after inverse escape</returns>
                    static std::wstring unescapeWideChar(const std::wstring& wstr_with_ucs2, const std::wstring& not_unescape_wide_chars) {
                        if (wstr_with_ucs2.empty()) {
                            return L"";
                        }
                        std::wstring wstr;
                        wstr.reserve(wstr_with_ucs2.size());
                        std::wstring ucs2_tmp;
                        ucs2_tmp.reserve(6);
                        for (auto it = wstr_with_ucs2.cbegin(), cend = wstr_with_ucs2.cend(); it != cend; it++) {
                            if (*it == L'\\') {
                                ucs2_tmp = L"\\";
                                it++;
                                if (it != cend && *it == L'u') {
                                    ucs2_tmp += L'u';
                                    it++;
                                    if (it != cend && isWideCharHex(*it)) {
                                        ucs2_tmp += *it;
                                        it++;
                                        if (it != cend && isWideCharHex(*it)) {
                                            ucs2_tmp += *it;
                                            it++;
                                            if (it != cend && isWideCharHex(*it)) {
                                                ucs2_tmp += *it;
                                                it++;
                                                if (it != cend && isWideCharHex(*it)) {
                                                    ucs2_tmp += *it;
                                                    auto wch = UCS22WideChar(ucs2_tmp);
                                                    if (not_unescape_wide_chars.find(wch) == std::wstring::npos) {
                                                        wstr += wch;
                                                        continue;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                wstr += ucs2_tmp;
                                if (it == cend) {
                                    break;
                                }
                            }
                            wstr += *it;
                        }
                        return wstr;
                    }

                    /// <summary>
                    /// Escape UTF8-encoded strings
                    /// </summary>
                    /// <param name="utf8">String containing the UTF8 encoding to be escaped</param>
                    /// <param name="escape_utf8_chars">The character set of the UTF8 encoding to be escaped</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>The escaped UTF8 encoded string</returns>
                    static std::string escapeUTF8(const std::string& utf8, const std::string& escape_utf8_chars) {
                        return wideChar2UTF8(escapeWideChar(UTF82wideChar(utf8), UTF82wideChar(escape_utf8_chars)));
                    }

                    /// <summary>
                    /// Inverted UTF8-encoded strings
                    /// </summary>
                    /// <param name="utf8_with_ucs2">UTF8 encoded string to be escaped</param>
                    /// <param name="not_unescape_utf8_chars">UTF8 encoded character set without escaping</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>Reverse-escaped UTF8-encoded string</returns>
                    static std::string unescapeUTF8(const std::string& utf8_with_ucs2, const std::string& not_unescape_utf8_chars) {
                        return wideChar2UTF8(unescapeWideChar(UTF82wideChar(utf8_with_ucs2), UTF82wideChar(not_unescape_utf8_chars)));
                    }

                    /// <summary>
                    /// UCS22WideChar
                    /// </summary>
                    /// <param name="ucs2">ucs2 value</param>
                    /// <warning></warning>
                    /// <include></include>
                    /// <bug></bug>
                    /// <returns>wchar_t</returns>
                    static wchar_t UCS22WideChar(const std::wstring& ucs2) {
                        auto it = ucs2.cbegin();
                        it += 2; // L'\\u'
                        uint16_t wch_value = 0;
                        for (auto i = 0; i < 4; i++) {
                            wch_value <<= 4;
                            wch_value += wideChar2hex(*it);
                            it++;
                        }
                        auto wch = static_cast<wchar_t>(wch_value);
                        return wch;
                    }

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="str"></param>
                    /// <param name="oldStr"></param>
                    /// <param name="newStr"></param>
                    /// <returns></returns>
                    static bool replaceString(
                        istring& str,
                        const istring& oldStr,
                        const istring& newStr
                    ) {
                        bool found = false;
                        size_t pos = 0;
                        while ((pos = str.find(oldStr.data(), pos)) != npos) {
                            found = true;
                            str.replace(pos, oldStr.length(), newStr.data());
                            pos += newStr.length();
                        }
                        return found;
                    }


                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="delimiters"></param>
                    /// <param name="pushEmpty"></param>
                    /// <param name="vInversion"></param>
                    /// <returns></returns>
                    static std::list<Type> istringSplit2List(
                        const istring& str,
                        const istring& delimiters,
                        bool pushEmpty = false,
                        bool vInversion = false) {
                        std::list<Type> arr;
                        if (!str.empty()) {
                            size_type start = 0;
                            size_type end = str.data().find_first_of(delimiters.data(), start);
                            while (end != npos) {
                                Type token = str.data().substr(start, end - start);
                                if (!token.empty() || (token.empty() && pushEmpty)) {
                                    if (vInversion) arr.emplace_front(token);
                                    else arr.emplace_back(token);
                                }
                                start = end + 1;
                                end = str.data().find_first_of(delimiters.data(), start);
                            }
                            Type token = str.data().substr(start);
                            if (!token.empty() || (token.empty() && pushEmpty)) {
                                if (vInversion) {
                                    arr.emplace_front(token);
                                }
                                else {
                                    arr.emplace_back(token);
                                }
                            }
                        }
                        return arr;
                    }

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="delimiters"></param>
                    /// <param name="pushEmpty"></param>
                    /// <returns></returns>
                    static std::vector<Type> istringSplit2Vector(
                        const istring& str,
                        const istring& delimiters,
                        bool pushEmpty = false) {
                        std::vector<Type> arr;
                        if (!str.empty()) {
                            size_type start = 0;
                            size_type end = str.data().find_first_of(delimiters.data(), start);
                            while (end != npos) {
                                Type token = str.data().substr(start, end - start);
                                if (!token.empty() || (token.empty() && pushEmpty)) {
                                    arr.emplace_back(token);
                                }
                                start = end + 1;
                                end = str.data().find_first_of(delimiters.data(), start);
                            }
                            Type token = str.data().substr(start);
                            if (!token.empty() || (token.empty() && pushEmpty)) {
                                arr.emplace_back(token);
                            }
                        }
                        return arr;
                    }

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="delimiters"></param>
                    /// <param name="pushEmpty"></param>
                    /// <returns></returns>
                    static std::set<Type> istringSplit2Set(
                        const istring& str,
                        const istring& delimiters,
                        bool pushEmpty = false) {
                        std::set<Type> arr;
                        if (!str.empty()) {
                            size_type start = 0;
                            size_type end = str.data().find_first_of(delimiters.data(), start);
                            while (end != npos) {
                                Type token = str.data().substr(start, end - start);
                                if (!token.empty() || (token.empty() && pushEmpty))
                                    arr.emplace(token);
                                start = end + 1;
                                end = str.data().find_first_of(delimiters, start);
                            }
                            Type token = str.data().substr(start);
                            if (!token.empty() || (token.empty() && pushEmpty)) {
                                arr.emplace(token);
                            }
                        }
                        return arr;
                    }

                public:

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="delimiters"></param>
                    /// <param name="pushEmpty"></param>
                    /// <param name="vInversion"></param>
                    /// <returns></returns>
                    std::list<Type> split2List(
                        const istring& delimiters,
                        bool pushEmpty = false,
                        bool vInversion = false){
                        std::list<Type> arr;
                        if (!this->_data.empty()) {
                            size_type start = 0;
                            size_type end = (this->_data).find_first_of(delimiters.data(), start);
                            while (end != npos) {
                                Type token = (this->_data).substr(start, end - start);
                                if (!token.empty() || (token.empty() && pushEmpty)) {
                                    if (vInversion) arr.emplace_front(token);
                                    else arr.emplace_back(token);
                                }
                                start = end + 1;
                                end = (this->_data).find_first_of(delimiters.data(), start);
                            }
                            Type token = (this->_data).substr(start);
                            if (!token.empty() || (token.empty() && pushEmpty)) {
                                if (vInversion) {
                                    arr.emplace_front(token);
                                }
                                else {
                                    arr.emplace_back(token);
                                }
                            }
                        }
                        return arr;
                    }
                    
                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="delimiters"></param>
                    /// <param name="pushEmpty"></param>
                    /// <returns></returns>
                    std::vector<Type> split2Vector(
                        const istring& delimiters,
                        bool pushEmpty = false) {
                        std::vector<Type> arr;
                        if (!(this->_data).empty()) {
                            size_type start = 0;
                            size_type end = (this->_data).find_first_of(delimiters.data(), start);
                            while (end != npos) {
                                Type token = (this->_data).substr(start, end - start);
                                if (!token.empty() || (token.empty() && pushEmpty)) {
                                    arr.emplace_back(token);
                                }
                                start = end + 1;
                                end = (this->_data).find_first_of(delimiters.data(), start);
                            }
                            Type token = (this->_data).substr(start);
                            if (!token.empty() || (token.empty() && pushEmpty)) {
                                arr.emplace_back(token);
                            }
                        }
                        return arr;
                    }
                    
                    /// <summary>
                    /// 
                    /// </summary>
                    /// <param name="delimiters"></param>
                    /// <param name="pushEmpty"></param>
                    /// <returns></returns>
                    std::set<Type> split2Set(
                        const istring& delimiters,
                        bool pushEmpty = false) {
                        std::set<Type> arr;
                        if (!(this->_data).empty()) {
                            size_type start = 0;
                            size_type end = (this->_data).find_first_of(delimiters.data(), start);
                            while (end != npos){
                                Type token = (this->_data).substr(start, end - start);
                                if (!token.empty() || (token.empty() && pushEmpty))
                                    arr.emplace(token);
                                start = end + 1;
                                end = (this->_data).find_first_of(delimiters, start);
                            }
                            Type token = (this->_data).substr(start);
                            if (!token.empty() || (token.empty() && pushEmpty)) {
                                arr.emplace(token);
                            }
                        }
                        return arr;
                    }
                    

                public:
                    /// <summary>
                    /// 
                    /// </summary>
                    /// <returns></returns>
                    std::string toHexStdString(){
                        std::ostringstream os;
                        os << std::hex << this->_data;
                        return os.str();
                    }

                    /// <summary>
                    /// 
                    /// </summary>
                    /// <returns></returns>
                    std::string toDecStr(){
                        std::ostringstream os;
                        os << std::dec << this->_data;
                        return os.str();
                    }

                public:
                    /// <summary>
                    /// istring assignment operator
                    /// </summary>
                    istring& operator = (const istring& str)
                    {
                        if (*this == str) {
                            return *this;
                        }
                        this->_data = str;
                        return *this;
                    }

                    istring& operator = (istring&& str) noexcept
                    {
                        if (*this == str) {
                            return *this;
                        }
                        this->_data = std::move(str);
                    }

                    istring& operator = (const value_type* s)
                    {
                        this->_data = s;
                        return *this;
                    }

                    istring& operator = (value_type ch)
                    {
                        this->_data = ch;
                        return *this;
                    }

                    istring& operator = (std::initializer_list<value_type> ilist)
                    {
                        this->_data = ilist;
                        return *this;
                    }

                    /// <summary>
                    /// get istring char at pos
                    /// </summary>
                    /// <warning>
                    /// if pos >= size(), the behavior is undefined
                    /// </warning>
                    reference operator [] (size_type pos)
                    {
                        return this->_data[pos];
                    }

                    const_reference operator [] (size_type pos) const
                    {
                        return this->_data[pos];
                    }

                    /// <summary>
                    /// istring += operator
                    /// </summary>
                    istring& operator += (const istring& str)
                    {
                        this->_data += str._data;
                        return *this;
                    }

                    istring& operator += (value_type ch)
                    {
                        this->_data += ch;
                        return *this;
                    }

                    istring& operator += (const value_type* s)
                    {
                        this->_data += s;
                        return *this;
                    }

                    istring& operator += (std::initializer_list<value_type> ilist)
                    {
                        this->_data += ilist;
                        return *this;
                    }

                    friend bool operator == (const istring& ls, const istring& rs) noexcept
                    {
                        return ls._data == rs._data;
                    }

                    friend bool operator != (const istring& ls, const istring& rs) noexcept
                    {
                        return ls._data != rs._data;
                    }

                    friend bool operator < (const istring& ls, const istring& rs) noexcept
                    {
                        return ls._data < rs._data;
                    }

                    friend bool operator <= (const istring& ls, const istring& rs) noexcept
                    {
                        return ls._data <= rs._data;
                    }

                    friend bool operator > (const istring& ls, const istring& rs) noexcept
                    {
                        return ls._data > rs._data;
                    }

                    friend bool operator >= (const istring& ls, const istring& rs) noexcept
                    {
                        return ls._data >= rs._data;
                    }

                    friend bool operator == (const value_type* s, const istring& rs) noexcept
                    {
                        return s == rs;
                    }

                    friend bool operator == (const istring& ls, const value_type* s)
                    {
                        return ls == s;
                    }

                    friend bool operator != (const istring& ls, const value_type* s)
                    {
                        return ls != s;
                    }

                    friend bool operator < (const istring& ls, const value_type* s)
                    {
                        return ls < s;
                    }

                    friend bool operator <= (const istring& ls, const value_type* s)
                    {
                        return ls <= s;
                    }

                    friend bool operator > (const istring& ls, const value_type* s)
                    {
                        return ls > s;
                    }

                    friend bool operator >= (const istring& ls, const value_type* s)
                    {
                        return ls >= s;
                    }

                    friend std::ostream& operator << (std::ostream& os, const istring& str)
                    {
                        os << str._data;
                        return os;
                    }

                    friend std::istream& operator >> (std::istream& is, const istring& str)
                    {
                        is >> str._data;
                        return is;
                    }

                    /// <summary>
                    /// stream input str or ch or number to istring
                    /// </summary>
                    istring& operator << (const istring& str)
                    {
                        return this->append(str);
                    }

                    istring& operator << (const value_type* s)
                    {
                        return this->append(s);
                    }

                    istring& operator << (const Type& str)
                    {
                        return this->append(str);
                    }

                    istring& operator << (value_type ch)
                    {
                        return this->append(ch);
                    }

                    istring& operator << (int i)
                    {
                        return this->append(i);
                    }

                    istring& operator << (i::core::uint ui)
                    {
                        return this->append(ui);
                    }

                    istring& operator << (long l)
                    {
                        return this->append(l);
                    }

                    istring& operator << (i::core::ulong ul)
                    {
                        return this->append(ul);
                    }

                    istring& operator << (long long ll)
                    {
                        return this->append(ll);
                    }

                    istring& operator << (i::core::uint64 ull)
                    {
                        return this->append(ull);
                    }

                    istring& operator << (float f)
                    {
                        return this->append(f);
                    }

                    istring& operator << (double d)
                    {
                        return this->append(d);
                    }

                    istring& operator << (std::initializer_list<value_type> ilist)
                    {
                        return this->append(ilist);
                    }

                    /// <summary>
                    /// append ls and rs to a new istring
                    /// </summary>
                    friend istring operator + (const istring& ls, const istring& rs)
                    {
                        istring str(ls);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend istring operator + (istring&& ls, const istring& rs)
                    {
                        ls.append(rs);
                        return ls;
                    }

                    friend istring operator + (istring&& ls, istring&& rs)
                    {
                        ls.append(rs);
                        return ls;
                    }

                    friend istring operator + (const istring& ls, const value_type* s)
                    {
                        istring str(ls);
                        str.append(s);
                        return std::move(str);
                    }

                    friend istring operator + (istring&& ls, const value_type* s)
                    {
                        ls.append(s);
                        return ls;
                    }

                    friend istring operator + (const istring& ls, value_type ch)
                    {
                        istring str(ls);
                        str.pushBack(ch);
                        return std::move(str);
                    }

                    friend istring operator + (istring&& ls, value_type ch)
                    {
                        ls.pushBack(ch);
                        return ls;
                    }

                    friend istring operator + (const istring& ls, std::initializer_list<value_type> ilist)
                    {
                        istring str(ls);
                        str.append(ilist);
                        return std::move(str);
                    }

                    friend istring operator + (istring&& ls, std::initializer_list<value_type> ilist)
                    {
                        ls.append(ilist);
                        return ls;
                    }

                    friend istring operator + (value_type ch, const istring& rs)
                    {
                        istring str(1, ch);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend istring operator + (value_type ch, istring&& rs)
                    {
                        istring str(1, ch);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend istring operator + (const value_type* s, const istring& rs)
                    {
                        istring str(s);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend istring operator + (const value_type* s, istring&& rs)
                    {
                        istring str(s);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend istring operator + (std::initializer_list<value_type> ilist, const istring& rs)
                    {
                        istring str(ilist);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend istring operator + (std::initializer_list<value_type> ilist, istring&& rs)
                    {
                        istring str(ilist);
                        str.append(rs);
                        return std::move(str);
                    }

                public:
                    /// <summary>
                    /// to_string / to_wstring
                    /// </summary>
                    template <typename T>
                    static istring valueOf(T&& value)
                    {
#ifdef __CPP_17__
                        if constexpr (std::is_same_v<Type, std::string>) {
                            return static_cast<istring>(std::to_string(value));
                        }
                        return static_cast<istring>(std::to_wstring(value));
#else
                        if (std::is_same_v<Type, std::string>) {
                            return static_cast<istring>(std::to_string(value));
                        }
                        return static_cast<istring>(std::to_wstring(value));
#endif
                    }

                    /// <summary>
                    /// check str start with sub
                    /// </summary>
                    static bool startsWith(const istring& sub, const istring& str);

                    /// <summary>
                    /// check str end with sub
                    /// </summary>
                    static bool endsWith(const istring& sub, const istring& str);

                protected:

                private:
                    Type _data;
                };

                /*
#ifdef __CPP_20__
                template <typename Type> requires type::type_traits::is_std_string_v<Type>
                bool istring<Type>::startsWith(const istring& sub, const istring& str)
#else
                template <typename Type, std::enable_if_t <type_traits::is_std_string_v<Type>, Type> t>
                bool istring<Type, t>::startsWith(const istring& sub, const istring& str)
#endif
                {
                    if (sub.length() > str.length()) {
                        return false;
                    }
                    auto sub_iter = sub.cbegin();
                    auto str_iter = str.cbegin();
                    while (sub_iter != sub.cend()) {
                        if (*sub_iter != *str_iter) {
                            return false;
                        }
                        ++sub_iter;
                        ++str_iter;
                    }
                    return true;
                }
                
                
#ifdef __CPP_20__
                template <typename Type> requires type::type_traits::is_std_string_v<Type>
                bool istring<Type>::endsWith(const istring& sub, const istring& str)
#else
                template <typename Type, std::enable_if_t <type_traits::is_std_string_v<Type>, Type> t>
                bool istring<Type, t>::endsWith(const istring& sub, const istring& str)
#endif
                {
                    if (sub.length() > str.length()) {
                        return false;
                    }
                    auto sub_iter = sub.crbegin();
                    auto str_iter = str.crbegin();
                    while (sub_iter != sub.crend()) {
                        if (*sub_iter != *str_iter) {
                            return false;
                        }
                        ++sub_iter;
                        ++str_iter;
                    }
                    return true;
                }
                */

            }//namespace basic
        }//namespace type
    }//namespace core
}//namespace i


#endif //!___MIRACLEFOREST_I_ISTRING___