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

#include <iostream>
#include <vector>
#include <regex>
#include "../type/type_traits.hpp"

namespace i::core {
	namespace type {
		namespace basic {
#ifdef __CPP_20__
            template <typename Type> requires type_traits::is_std_string_v<Type>
#else
            template <typename Type, std::enable_if_t<type_traits::is_std_string_v<Type>, Type> = 0>
#endif
			class istring final{
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
                    : _data(other, pos, count){}

                istring(const istring& other, size_type pos)
                    : _data(other, pos) {}

                istring(const value_type* s, size_type count)
                    : _data(s, count) {}

                istring(const value_type* s)
                    : _data(s){}

                istring(const istring& other)
                    : _data(other._data) {}

                istring(istring&& other) noexcept
                    : _data(std::move(other._data)) {}

                istring(std::initializer_list<value_type> ilist)
                    : _data(ilist) {}

                template<class InputIt> istring(InputIt first, InputIt last)
                    : _data(first, last) {}

                ~ istring(){}

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
                    if (*this == str){
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

                istring& append(i::core::ullong ull)
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
                    if (*this == other){
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
                    while (pos != istring::npos){
                        strs.push_back(this->substr(start, pos));
                        start = pos + 1;
                        pos = this->find(ch, pos + 1);
                    }
                    if (start < this->length()){
                        strs.push_back(this->substr(start));
                    }
                    return std::move(strs);
                }

                /// <summary>
                /// match the istring with regex
                /// </summary>
                bool match(const std::basic_regex<value_type>& regex, bool search = false)
                {
                    if (!search){
                        return std::regex_match(this->_data, regex);
                    }
                    return std::regex_search(this->_data, regex);
                }

                std::match_results<const value_type*> matchResult(const std::basic_regex<value_type>& regex, bool search)
                {
                    std::match_results<const value_type*> result;
                    if (!search) {
                        std::regex_match(this->_data, result, regex);
                    }else{
                        std::regex_search(this->_data, result, regex);
                    }
                    return result;
                }

			public:
                /// <summary>
                /// istring assignment operator
                /// </summary>
                istring& operator = (const istring& str)
                {
                    if (*this == str){
                        return *this;
                    }
                    this->_data = str;
                    return *this;
                }

                istring& operator = (istring&& str) noexcept
                {
                    if (*this == str){
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

                istring& operator << (i::core::ullong ull)
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
                    constexpr if (std::is_same_v<Type, std::string>){
                        return static_cast<istring>(std::to_string(value));
                    }
                    return static_cast<istring>(std::to_wstring(value));
#else
                    if (std::is_same_v<Type, std::string>){
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

#ifdef __CPP_20__
            template <typename Type> requires type::type_traits::is_std_string_v<Type>
            bool istring<Type>::startsWith(const istring& sub, const istring& str)
#else
            template <typename Type, std::enable_if_t <type_traits::is_std_string_v<Type>, Type> t>
            bool istring<Type, t>::startsWith(const istring &sub, const istring &str)
#endif
            {
                if (sub.length() > str.length()){
                    return false;
                }
                auto sub_iter = sub.cbegin();
                auto str_iter = str.cbegin();
                while (sub_iter != sub.cend()){
                    if (*sub_iter != *str_iter){
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
            bool istring<Type, t>::endsWith(const istring &sub, const istring &str)
#endif
            {
                if (sub.length() > str.length()){
                    return false;
                }
                auto sub_iter = sub.crbegin();
                auto str_iter = str.crbegin();
                while (sub_iter != sub.crend()){
                    if (*sub_iter != *str_iter){
                        return false;
                    }
                    ++sub_iter;
                    ++str_iter;
                }
                return true;
            }

        }//namespace basic
	}//namespace type
}//namespace i::core


#endif //!___MIRACLEFOREST_I_ISTRING___