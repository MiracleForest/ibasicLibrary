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

#ifndef ___MIRACLEFOREST_I_BASIC_ISTRING___
#define ___MIRACLEFOREST_I_BASIC_ISTRING___

#include <sstream>
#include "../../family/imacrofamily.h"
#include "../type/type_traits.hpp"
#include "basic/ibasic.hpp"

#include "../../../cppstd/iostream"
#include "../../../cppstd/string"
#include "../../../cppstd/vector"
#include "../../../cppstd/regex"
#include "../../../cppstd/set"
#include "../../../cppstd/list"
#include "../../../cppstd/map"
#ifdef __WINDOWS__
#include <windows.h>
#include <stringapiset.h>
#endif

SPACE(i) {
    SPACE(core) {
        SPACE(type) {
            SPACE(basic) {

#ifdef __CPP_20__
                template <typename Type> requires type_traits::is_std_string_v<Type>
#else
                template <typename Type, std::enable_if_t<type_traits::is_std_string_v<Type>, Type> = 0>
#endif
                class basic_istring final {
                public:

                    // typedef same as strString typedef
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
                    //basic_istring all Constructor
                    explicit basic_istring()
                        : _data() {}

                    explicit basic_istring(const Type& str)
                        : _data(str) {}

                    explicit basic_istring(Type&& str) noexcept
                        : _data(str) {}

                    basic_istring(size_type count, value_type ch)
                        : _data(count, ch) {}

                    basic_istring(const basic_istring& other, size_type pos, size_t count)
                        : _data(other, pos, count) {}

                    basic_istring(const basic_istring& other, size_type pos)
                        : _data(other, pos) {}

                    basic_istring(const value_type* s, size_type count)
                        : _data(s, count) {}

                    basic_istring(const value_type* s)
                        : _data(s) {}

                    basic_istring(const basic_istring& other)
                        : _data(other._data) {}

                    basic_istring(basic_istring&& other) noexcept
                        : _data(std::move(other._data)) {}

                    basic_istring(std::initializer_list<value_type> ilist)
                        : _data(ilist) {}

                    template<class InputIt> basic_istring(InputIt first, InputIt last)
                        : _data(first, last) {}

                    ~basic_istring() {}

                    /****
                    * @author ticks
                    * @since 22-6-23 上午11:59
                    * @brief basic_istring assign as stdString assign
                    *
                    * @param count: 要替换的下标(0开始)
                    * @param ch: 要替换的新字符
                    * @retval basic_istring& basic_istring引用
                    * @par Example
                    * @code
                    * istring str = "Hello istring";
                    * str.assign(0, 'h');
                    * str ==> "hello istring"
                    * @endcode
                    *
                    * @include <string>
                    ****/
                    basic_istring& assign(size_type count, value_type ch)
                    {
                        this->_data.assign(count, ch);
                        return *this;
                    }

                    /**
                    * @author ticks
                    * @since 22-6-23 下午12:05
                    *
                    * @brief 用新替换原字符串
                    *
                    * @param str: 新字符串
                    * @retval basic_istring&: basic_istring引用
                    *
                    * @par Example
                    * @code
                    * istring str = "Hello istring";
                    * istring str1 = "hello";
                    * str.assign(str1);
                    * str ==> "hello"
                    * @endcode
                    *
                    * @include <string>
                    *
                    **/
                    basic_istring& assign(const basic_istring& str)
                    {
                        if (*this == str) {
                            return *this;
                        }
                        this->_data.assign(str._data);
                        return *this;
                    }

                    basic_istring& assign(const basic_istring& str, size_type pos, size_type count)
                    {
                        this->_data.assign(str._data, pos, count);
                        return *this;
                    }

                    basic_istring& assign(const basic_istring& str, size_type pos)
                    {
                        this->_data.assign(str._data, pos);
                        return *this;
                    }

                    basic_istring& assign(basic_istring&& str) noexcept
                    {
                        this->_data.assign(std::move(str._data));
                        return this;
                    }

                    basic_istring& assign(const value_type* s, size_type count)
                    {
                        this->_data.assign(s, count);
                        return *this;
                    }

                    basic_istring& assign(const value_type* s)
                    {
                        this->_data.assign(s);
                        return *this;
                    }

                    basic_istring& assign(std::initializer_list<value_type> ilist)
                    {
                        this->_data.assign(ilist);
                        return *this;
                    }

                    template<class InputIt> basic_istring& assign(InputIt first, InputIt last)
                    {
                        this->_data.assign(first, last);
                        return *this;
                    }

                    /****
                    * @author ticks
                    * @since 22-6-23 下午12:13 
                    * @brief 获取 basic_istring 底层内存分配器
                    *
                    * @retval allocator_type: 底层内存分配器
                    *
                    * @par Example
                    * @code
                    * istring str = "";
                    * auto allocator = str.getAllocator();
                    * @endcode
                    *
                    * @include <string>
                    * @details
                    * 获取 basic_istring 底层内存分配器
                    * @enddetails
                    *
                    ****/
                    allocator_type getAllocator() const
                    {
                        return this->_data.get_allocator();
                    }

                    /****
                    * @author ticks
                    * @since 22-6-23 下午12:21
                    * @brief 获取 basic_istring指定下标的字符
                    *
                    * @param pos: 下标(0开始)
                    * @retval reference: 字符引用
                    * @throws std::out_of_range : 当 pos > length() 时抛出
                    *
                    * @note
                    * pos 应小于字符串长度
                    * @endnote
                    * @par Example
                    * @code
                    *
                    * @endcode
                    *
                    * @include string
                    * @details
                    * 获取 basic_istring指定下标的字符
                    * @enddetails
                    *
                    ****/
                    reference charAt(size_type pos)
                    {
                        return this->_data.at(pos);
                    }

                    const_reference charAt(size_type pos) const
                    {
                        return this->_data.at(pos);
                    }

                    /****
                    * @author ticks
                    * @since 22-6-23 下午12:42
                    * @brief 获取字符串第一个字符
                    *
                    * @retval reference: 字符串第一个字符引用
                    * @throws
                    *
                    * @note
                    * 字符串长度为0时不要使用该函数
                    * @endnote
                    * @pre length() > 0
                    * @par Example
                    * @code
                    * istring str = "hello";
                    * str.front() = 'H';
                    * str ==> "Hello"
                    * @endcode
                    *
                    * @warning 如果字符串长度为0，行为未定义。
                    * @include string
                    * @details
                    * 获取字符串第一个字符
                    * @enddetails
                    *
                    ****/
                    reference front()
                    {
                        return this->_data.front();
                    }

                    const_reference front() const
                    {
                        return this->_data.front();
                    }

                    /****
                    * @author ticks
                    * @since 22-6-23 下午12:46
                    * @brief 获取字符串最后一个字符
                    *
                    * @retval reference: 字符串最后一个字符引用
                    * @throws
                    *
                    * @note
                    * 字符串长度为0时不要使用
                    * @endnote
                    * @pre length() > 0
                    * @par Example
                    * @code
                    * istring str = "hello";
                    * str.back() = 'O';
                    * str ==> "HellO"
                    * @endcode
                    *
                    * @warning 如果字符串长度为0,行为未定义
                    * @include string
                    * @details
                    * 获取字符串最后一个字符
                    * @enddetails
                    *
                    ****/
                    reference back()
                    {
                        return this->_data.back();
                    }

                    const_reference back() const
                    {
                        return this->_data.back();
                    }

                    /****
                    * @author ticks
                    * @since 22-6-23 下午12:48
                    * @brief 获取字符串指针
                    *
                    * @retval const_pointer: const 指针类型
                    *
                    * @par Example
                    * @code
                    * istring str = "Hello"
                    * auto strs = str.data();
                    * @endcode
                    *
                    * @include string
                    * @details
                    * 获取字符串指针
                    * @enddetails
                    *
                    ****/
                    const_pointer data() const noexcept
                    {
                        return this->_data.data();
                    }

                    pointer data() noexcept
                    {
                        return this->_data.data();
                    }

                    /****
                    * @author ticks
                    * @since 22-6-23 下午12:54
                    * @brief 获取字符串的c风格表示
                    *
                    * @retval const value_type* : 字符串指针
                    *
                    * @par Example
                    * @code
                    * istring str = "Hello";
                    * auto* str1 = str.cStr();
                    * @endcode
                    *
                    * @include string
                    * @details
                    * 获取字符串的c风格表示
                    * @enddetails
                    *
                    ****/
                    const value_type* cStr() const noexcept
                    {
                        return this->_data.data();
                    }

                    /****
                    * @author ticks
                    * @since 22-6-23 下午12:59
                    * @brief 获取字符串开始迭代器
                    *
                    * @retval 返回值注释
                    * @throws 
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * get basic_istring first  iterator
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author ticks
                    * @since 22-6-23 下午1:01
                    * @brief get basic_istring last iterator
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * get basic_istring last iterator
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief get basic_istring first reverse iterator
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * get basic_istring first reverse iterator
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief  get basic_istring last reverse iterator
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    *  get basic_istring last reverse iterator
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief check basic_istring length() == 0
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * check basic_istring length() == 0
                    * @enddetails
                    * @other 其他
                    ****/
                    bool empty() const noexcept
                    {
                        return this->_data.empty();
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief get basic_istring length
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * get basic_istring length
                    * @enddetails
                    * @other 其他
                    ****/
                    size_type length() const noexcept
                    {
                        return this->_data.length();
                    }

                    size_type size() const noexcept
                    {
                        return this->_data.size();
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief get basic_istring max contain
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * get basic_istring max contain
                    * @enddetails
                    * @other 其他
                    ****/
                    size_type maxSize() const noexcept
                    {
                        return this->_data.max_size();
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief set basic_istring alloc size
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    void reserve(size_type new_cap = static_cast<size_type>(0))
                    {
                        this->_data.reserve(new_cap);
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief get basic_istring alloc current size
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    size_type capacity() const noexcept
                    {
                        return this->_data.capacity();
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief fit current alloc size to current string size
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * fit current alloc size to current string size
                    * @enddetails
                    * @other 其他
                    ****/
                    void fitAllocSize()
                    {
                        this->_data.shrink_to_fit();
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief clear basic_istring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    void clear() noexcept
                    {
                        this->_data.clear();
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief insert ch or string to basic_istring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * insert ch or string to basic_istring
                    * @enddetails
                    * @other 其他
                    ****/
                    basic_istring& insert(size_type pos, size_type count, value_type ch)
                    {
                        this->_data.insert(pos, count, ch);
                        return *this;
                    }

                    basic_istring& insert(size_type pos, const value_type* s, size_type count)
                    {
                        this->_data.insert(pos, s, count);
                        return *this;
                    }

                    basic_istring& insert(size_type pos, const value_type* s)
                    {
                        this->_data.insert(pos, s);
                        return *this;
                    }

                    basic_istring& insert(size_type pos, const basic_istring& str)
                    {
                        this->_data.insert(pos, str);
                        return *this;
                    }

                    basic_istring& insert(size_type pos, const basic_istring& str, size_type str_pos, size_type str_count)
                    {
                        this->_data.insert(pos, str, str_pos, str_count);
                        return *this;
                    }

                    basic_istring& insert(size_type pos, const basic_istring& str, size_type str_pos)
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief erase the char or str in basic_istring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * erase the char or str in basic_istring
                    * @enddetails
                    * @other 其他
                    ****/
                    basic_istring& erase(size_type pos = 0, size_type count = basic_istring::npos)
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

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief add a char in basic_istring end
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    void pushBack(value_type ch)
                    {
                        this->_data.push_back(ch);
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief remove basic_istring last char
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning if basic_istring length() == 0 , the behavior is undefined
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    void popBack()
                    {
                        this->_data.pop_back();
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief append char or string in basic_istring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    basic_istring& append(size_type count, value_type ch)
                    {
                        this->_data.append(count, ch);
                        return *this;
                    }

                    basic_istring& append(const basic_istring& str)
                    {
                        this->_data.append(str._data);
                        return *this;
                    }

                    basic_istring& append(basic_istring&& str)
                    {
                        this->_data.append(std::move(str._data));
                    }

                    basic_istring& append(const Type& str)
                    {
                        this->_data.append(str);
                        return *this;
                    }

                    basic_istring& append(const basic_istring& str, size_type pos, size_type count)
                    {
                        this->_data.append(str._data, pos, count);
                        return *this;
                    }

                    basic_istring& append(const basic_istring& str, size_type pos)
                    {
                        this->_data.append(str._data, pos);
                        return *this;
                    }

                    basic_istring& append(const value_type* s, size_type count)
                    {
                        this->_data.append(s, count);
                        return *this;
                    }

                    basic_istring& append(const value_type* s)
                    {
                        this->_data.append(s);
                        return *this;
                    }

                    basic_istring& append(std::initializer_list<value_type> ilist)
                    {
                        this->_data.append(ilist);
                        return *this;
                    }

                    basic_istring& append(value_type ch)
                    {
                        this->_data.push_back(ch);
                        return *this;
                    }

                    template <typename InputIt> basic_istring& append(InputIt first, InputIt last)
                    {
                        this->_data.append(first, last);
                        return *this;
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief append number in basic_istring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    basic_istring& append(int i)
                    {
                        return this->append(std::move(basic_istring::valueOf(i)));
                    }

                    basic_istring& append(i::core::uint ui)
                    {
                        return this->append(std::move(basic_istring::valueOf(ui)));
                    }

                    basic_istring& append(long l)
                    {
                        return this->append(std::move(basic_istring::valueOf(l)));
                    }

                    basic_istring& append(i::core::ulong ul)
                    {
                        return this->append(std::move(basic_istring::valueOf(ul)));
                    }

                    basic_istring& append(long long ll)
                    {
                        return this->append(std::move(basic_istring::valueOf(ll)));
                    }

                    basic_istring& append(i::core::uint64 ull)
                    {
                        return this->append(std::move(basic_istring::valueOf(ull)));
                    }

                    basic_istring& append(float f)
                    {
                        return this->append(std::move(basic_istring::valueOf(f)));
                    }

                    basic_istring& append(double d)
                    {
                        return this->append(std::move(basic_istring::valueOf(d)));
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief replace some str in basic_istring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    basic_istring& replace(size_type pos, size_type count, const basic_istring& str)
                    {
                        this->_data.replace(pos, count, str._data);
                        return *this;
                    }

                    basic_istring& replace(const_iterator first, const_iterator last, const basic_istring& str)
                    {
                        this->_data.replace(first, last, str._data);
                        return *this;
                    }

                    basic_istring& replace(size_type pos, size_type count, const basic_istring& str,
                        size_type str_pos, size_type str_count = basic_istring::npos)
                    {
                        this->_data.replace(pos, count, str._data, str_pos, str_count);
                        return *this;
                    }

                    template <typename InputIt>
                    basic_istring& replace(const_iterator first, const_iterator last, InputIt first1, InputIt last1)
                    {
                        this->_data.replace(first, last, first1, last1);
                        return *this;
                    }

                    basic_istring& replace(size_type pos, size_type count, const value_type* s, size_type s_count)
                    {
                        this->_data.replace(pos, count, s, s_count);
                        return *this;
                    }

                    basic_istring& replace(size_type pos, size_type count, const value_type* s)
                    {
                        this->_data.replace(pos, count, s);
                        return *this;
                    }

                    basic_istring& replace(const_iterator first, const_iterator last, const value_type* s)
                    {
                        this->_data.replace(first, last, s);
                        return *this;
                    }

                    basic_istring& replace(size_type pos, size_type count, size_type ch_count, value_type ch)
                    {
                        this->_data.replace(pos, count, ch_count, ch);
                        return *this;
                    }

                    basic_istring& replace(const_iterator first, const_iterator last, size_type count, value_type ch)
                    {
                        this->_data.replace(first, last, count, ch);
                        return *this;
                    }

                    basic_istring& replace(const_iterator first, const_iterator last, std::initializer_list<value_type> ilist)
                    {
                        this->_data.replace(first, last, ilist);
                        return *this;
                    }

                    basic_istring& replace(size_type pos, size_type count, std::initializer_list<value_type> ilist)
                    {
                        this->_data.replace(this->_data.begin() + pos, this->_data.begin() + pos + count, ilist);
                        return *this;
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief get basic_istring sub string in [pos, pos + count)
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    basic_istring substr(size_type pos = 0, size_type count = basic_istring::npos) const
                    {
                        basic_istring str(this->_data.substr(pos, count).data());
                        return std::move(str);
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief copy basic_istring [pos, count) str to dest
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws std::out_of_range :  if pos > length()
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    size_type copy(value_type* dest, size_type count, size_type pos = 0) const
                    {
                        return this->_data.copy(dest, count, pos);
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief set basic_istring ch count to count
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    void resize(size_type count)
                    {
                        this->_data.resize(count);
                    }

                    void resize(size_type count, value_type ch)
                    {
                        this->_data.resize(count, ch);
                    }

                    void swap(basic_istring& other)
                    {
                        if (*this == other) {
                            return;
                        }
                        this->_data.swap(other._data);
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief find the str or ch in basic_istring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    size_type find(const basic_istring& str, size_type pos = 0) const
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

                    size_type rfind(const basic_istring& str, size_type pos = basic_istring::npos) const
                    {
                        return this->_data.rfind(str._data, pos);
                    }

                    size_type rfind(const value_type* s, size_type pos, size_type count) const
                    {
                        return this->_data.rfind(s, pos, count);
                    }

                    size_type rfind(const value_type* s, size_type pos = basic_istring::npos) const
                    {
                        return this->_data.rfind(s, pos);
                    }

                    size_type rfind(value_type ch, size_type pos = basic_istring::npos) const
                    {
                        return this->_data.rfind(ch, pos);
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief check basic_istring start with str
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    bool startsWith(const basic_istring& str)
                    {
#ifdef __CPP_20__
                        return this->_data.starts_with(str._data);
#else
                        return basic_istring::startsWith(str, *this);
#endif
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief check basic_istring end with str
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    bool endsWith(const basic_istring& str)
                    {
#ifdef __CPP_20__
                        return this->_data.ends_with(str._data);
#else
                        return basic_istring::endsWith(str, *this);
#endif
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief split basic_istring with  char
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    std::vector<basic_istring> split(value_type ch)
                    {
                        std::vector<basic_istring> strs;
                        size_type pos = this->find(ch), start = 0;
                        while (pos != basic_istring::npos) {
                            strs.push_back(this->substr(start, pos));
                            start = pos + 1;
                            pos = this->find(ch, pos + 1);
                        }
                        if (start < this->length()) {
                            strs.push_back(this->substr(start));
                        }
                        return strs;
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief match the basic_istring with regex
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
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

                    template<typename Type1>
                    static std::string toStdString(Type1 value) {
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 转到宽字符串
                    *
                    * @param code_page 注释
                    * @param src_str 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::wstring toWideChar(std::uint32_t code_page, const std::string& src_str) {
                        if (src_str.empty()) {
                            return L"";
                        }
#ifdef __WINDOWS__
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
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return L"";
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::string fromWideChar(std::uint32_t code_page, const std::wstring& src_wstr) {
                        if (src_wstr.empty()) {
                            return "";
                        }
#ifdef __WINDOWS__
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
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return "";
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static bool isWideCharHex(wchar_t wch) {
                        return (wch >= L'0' && wch <= L'9') || (wch >= L'a' && wch <= L'f') || (wch >= L'A' && wch <= L'F');
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static char hex2char(uint8_t hex) {
                        if (hex <= 9) {
                            return '0' + hex;
                        }
                        else { // hex >= 10 && hex <= 15
                            return 'a' + hex - 10;
                        }
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static char hex2wideChar(uint8_t hex) {
                        if (hex <= 9) {
                            return L'0' + hex;
                        }
                        else {
                            return L'a' + hex - 10;
                        }
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief Convert a UTF8 encoded string to a wide string
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval The converted wide string
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::wstring UTF82wideChar(const std::string& utf8) {
#ifdef __WINDOWS__
                        return toWideChar(CP_UTF8, utf8);
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return L"";
                    }


                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief Convert wide strings to UTF8-encoded strings
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval The converted UTF8 encoded string
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::string wideChar2UTF8(const std::wstring& wstr) {
#ifdef __WINDOWS__
                        return fromWideChar(CP_UTF8, wstr);
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return "";
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief Convert ANSI-encoded strings to wide strings
                    *
                    * @param ansi ANSI-encoded string to be converted
                    * @future 未来要做的事情
                    * @retval The converted wide string
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::wstring ANSI2wideChar(const std::string& ansi) {
#ifdef __WINDOWS__
                        return toWideChar(CP_ACP, ansi);
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return L"";
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief Convert wide strings to ANSI-encoded strings
                    *
                    * @param wstr The wide string to be converted into an encoding
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval Converted ANSI-encoded string
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::string wideChar2ANSI(const std::wstring& wstr) {
#ifdef __WINDOWS__
                        return fromWideChar(CP_ACP, wstr);
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return "";
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief Convert ANSI-encoded mixed UCS2 encoded strings to wide strings
                    *
                    * @param ansi_with_ucs2 ANSI-encoded mixed UCS2 encoded strings to be converted
                    * @param not_unescape_wide_chars Wide character set without inverse escaping
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval The converted wide string
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::wstring ANSIWithUCS22WideChar(const std::string& ansi_with_ucs2, const std::wstring& not_unescape_wide_chars) {
                        return unescapeWideChar(ANSI2wideChar(ansi_with_ucs2), not_unescape_wide_chars);
                    }


                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::string wideChar2ANSIWithUCS2(const std::wstring& wstr, const std::wstring& force_escape_wide_chars) {
                        if (wstr.empty()) {
                            return "";
                        }
#ifdef __WINDOWS__
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
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return "";
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::string escapeUTF8(const std::string& utf8, const std::string& escape_utf8_chars) {
                        return wideChar2UTF8(escapeWideChar(UTF82wideChar(utf8), UTF82wideChar(escape_utf8_chars)));
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::string unescapeUTF8(const std::string& utf8_with_ucs2, const std::string& not_unescape_utf8_chars) {
                        return wideChar2UTF8(unescapeWideChar(UTF82wideChar(utf8_with_ucs2), UTF82wideChar(not_unescape_utf8_chars)));
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static bool replaceString(
                        basic_istring& str,
                        const basic_istring& oldStr,
                        const basic_istring& newStr
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


                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::list<Type> istringSplit2List(
                        const basic_istring& str,
                        const basic_istring& delimiters,
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::vector<Type> istringSplit2Vector(
                        const basic_istring& str,
                        const basic_istring& delimiters,
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

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @warning 警告
                    * @bug C2228->[<1>]
                    * @include <set>
                    * @details
                    * 详细描述
                    * @enddetails
                    ****/
                    static std::set<Type> istringSplit2Set(
                        const basic_istring& str,
                        const basic_istring& delimiters,
                        bool pushEmpty = false) = delete;/* {
                        std::set<Type> arr;
                        if (!str.empty()) {
                            size_type start = 0;
                        <1> size_type end = str.data().find_first_of(delimiters.data(), start);
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
                    }*/

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::wstring str2wstr(const std::string& str) {
#ifdef __WINDOWS__
                        return str2wstr(str, CP_UTF8);
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return L"";
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::wstring str2wstr(const std::string& str, i::core::uint codePage)
                    {
#ifdef __WINDOWS__
                        auto len = MultiByteToWideChar(codePage, 0, str.c_str(), -1, nullptr, 0);
                        auto* buffer = new wchar_t[len + 1];
                        MultiByteToWideChar(codePage, 0, str.c_str(), -1, buffer, len + 1);
                        buffer[len] = L'\0';

                        std::wstring result = std::wstring(buffer);
                        delete[] buffer;
                        return result;
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return L"";
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::string wstr2str(const std::wstring& wstr) {
#ifdef __WINDOWS__
                        return wstr2str(wstr, CP_UTF8);
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return "";
                    }


                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param wstr 待转换的宽字符串
                    * @param codePage codePage
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static std::string wstr2str(const std::wstring& wstr,uint codePage){
#ifdef __WINDOWS__
                        auto len = WideCharToMultiByte(codePage, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
                        char* buffer = new char[len + 1];
                        WideCharToMultiByte(codePage, 0, wstr.c_str(), -1, buffer, len + 1, nullptr, nullptr);
                        buffer[len] = '\0';

                        std::string result = std::string(buffer);
                        delete[] buffer;
                        return result;
#endif
                        // TODO 22-6-23 : Linux实现待定
                        return "";
                    }

                public:

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param delimiters 注释
                    * @param pushEmpty = false 注释
                    * @param vInversion = false 注释
                    * @future 未来要做的事情
                    * @retval std::list<Type>
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    std::list<Type> split2List(
                        const basic_istring& delimiters,
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
                    
                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    std::vector<Type> split2Vector(
                        const basic_istring& delimiters,
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
                    
                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    std::set<Type> split2Set(
                        const basic_istring& delimiters,
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
                    


                    /**
                    * @brief Integer to hex string.
                    *
                    * @tparam T      The integer type
                    * @param  value  The integer value
                    * @param  upper  Whether to use upper case (0x1A or 0x1a)
                    * @param  no0x   Whether to omit 0x prefix
                    * @param  noLeadingZero  Whether to omit leading zero
                    * @return std::string    The hex string
                    *
                    * @par Example
                    * @code
                    * IntToHexStr(15); // "F"
                    * IntToHexStr(16, true, true, false); // "0000000F"
                    * @endcode
                    */
                    template <typename T>
                    std::string IntToHexStr(const T& value, bool upper = true, bool no0x = true,
                        bool noLeadingZero = true)
                    {
                        std::string result;
                        if (value < 0) result += '-';
                        if (!no0x) result += "0x";
                        auto hexStr = upper ? "0123456789ABCDEF" : "0123456789abcdef";
                        bool leadingZero = true;
                        for (int i = sizeof(T) * 2; i > 0; --i)
                        {
                            auto hex = (value >> (i - 1) * 4) & 0xF;
                            if (noLeadingZero && leadingZero && hex == 0) continue;
                            leadingZero = false;
                            result += hexStr[hex];
                        }
                        return result;
                    }
                public:
                    

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    std::string toHexStdString(){
                        std::ostringstream os;
                        os << std::hex << this->_data;
                        return os.str();
                    }

                    /****
                    * @author Lovelylavender4
                    * @since 编写此代码的时间或版本
                    * @brief 描述
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    std::string toDecStr(){
                        std::ostringstream os;
                        os << std::dec << this->_data;
                        return os.str();
                    }

                public:

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief basic_istring assignment operator
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    basic_istring& operator = (const basic_istring& str)
                    {
                        if (*this == str) {
                            return *this;
                        }
                        this->_data = str;
                        return *this;
                    }

                    basic_istring& operator = (basic_istring&& str) noexcept
                    {
                        if (*this == str) {
                            return *this;
                        }
                        this->_data = std::move(str);
                    }

                    basic_istring& operator = (const value_type* s)
                    {
                        this->_data = s;
                        return *this;
                    }

                    basic_istring& operator = (value_type ch)
                    {
                        this->_data = ch;
                        return *this;
                    }

                    basic_istring& operator = (std::initializer_list<value_type> ilist)
                    {
                        this->_data = ilist;
                        return *this;
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief get basic_istring char at pos
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning if pos >= size(), the behavior is undefined
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    reference operator [] (size_type pos)
                    {
                        return this->_data[pos];
                    }

                    const_reference operator [] (size_type pos) const
                    {
                        return this->_data[pos];
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief basic_istring += operator
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    basic_istring& operator += (const basic_istring& str)
                    {
                        this->_data += str._data;
                        return *this;
                    }

                    basic_istring& operator += (value_type ch)
                    {
                        this->_data += ch;
                        return *this;
                    }

                    basic_istring& operator += (const value_type* s)
                    {
                        this->_data += s;
                        return *this;
                    }

                    basic_istring& operator += (std::initializer_list<value_type> ilist)
                    {
                        this->_data += ilist;
                        return *this;
                    }

                    friend bool operator == (const basic_istring& ls, const basic_istring& rs) noexcept
                    {
                        return ls._data == rs._data;
                    }

                    friend bool operator != (const basic_istring& ls, const basic_istring& rs) noexcept
                    {
                        return ls._data != rs._data;
                    }

                    friend bool operator < (const basic_istring& ls, const basic_istring& rs) noexcept
                    {
                        return ls._data < rs._data;
                    }

                    friend bool operator <= (const basic_istring& ls, const basic_istring& rs) noexcept
                    {
                        return ls._data <= rs._data;
                    }

                    friend bool operator > (const basic_istring& ls, const basic_istring& rs) noexcept
                    {
                        return ls._data > rs._data;
                    }

                    friend bool operator >= (const basic_istring& ls, const basic_istring& rs) noexcept
                    {
                        return ls._data >= rs._data;
                    }

                    friend bool operator == (const value_type* s, const basic_istring& rs) noexcept
                    {
                        return s == rs;
                    }

                    friend bool operator == (const basic_istring& ls, const value_type* s)
                    {
                        return ls == s;
                    }

                    friend bool operator != (const basic_istring& ls, const value_type* s)
                    {
                        return ls != s;
                    }

                    friend bool operator < (const basic_istring& ls, const value_type* s)
                    {
                        return ls < s;
                    }

                    friend bool operator <= (const basic_istring& ls, const value_type* s)
                    {
                        return ls <= s;
                    }

                    friend bool operator > (const basic_istring& ls, const value_type* s)
                    {
                        return ls > s;
                    }

                    friend bool operator >= (const basic_istring& ls, const value_type* s)
                    {
                        return ls >= s;
                    }

                    friend std::ostream& operator << (std::ostream& os, const basic_istring& str)
                    {
                        os << str._data;
                        return os;
                    }

                    friend std::istream& operator >> (std::istream& is, const basic_istring& str)
                    {
                        is >> str._data;
                        return is;
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief stream input str or ch or number to basic_istring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    basic_istring& operator << (const basic_istring& str)
                    {
                        return this->append(str);
                    }

                    basic_istring& operator << (const value_type* s)
                    {
                        return this->append(s);
                    }

                    basic_istring& operator << (const Type& str)
                    {
                        return this->append(str);
                    }

                    basic_istring& operator << (value_type ch)
                    {
                        return this->append(ch);
                    }

                    basic_istring& operator << (int i)
                    {
                        return this->append(i);
                    }

                    basic_istring& operator << (i::core::uint ui)
                    {
                        return this->append(ui);
                    }

                    basic_istring& operator << (long l)
                    {
                        return this->append(l);
                    }

                    basic_istring& operator << (i::core::ulong ul)
                    {
                        return this->append(ul);
                    }

                    basic_istring& operator << (long long ll)
                    {
                        return this->append(ll);
                    }

                    basic_istring& operator << (i::core::uint64 ull)
                    {
                        return this->append(ull);
                    }

                    basic_istring& operator << (float f)
                    {
                        return this->append(f);
                    }

                    basic_istring& operator << (double d)
                    {
                        return this->append(d);
                    }

                    basic_istring& operator << (std::initializer_list<value_type> ilist)
                    {
                        return this->append(ilist);
                    }

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief append ls and rs to a new basic_istring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    friend basic_istring operator + (const basic_istring& ls, const basic_istring& rs)
                    {
                        basic_istring str(ls);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend basic_istring operator + (basic_istring&& ls, const basic_istring& rs)
                    {
                        ls.append(rs);
                        return ls;
                    }

                    friend basic_istring operator + (basic_istring&& ls, basic_istring&& rs)
                    {
                        ls.append(rs);
                        return ls;
                    }

                    friend basic_istring operator + (const basic_istring& ls, const value_type* s)
                    {
                        basic_istring str(ls);
                        str.append(s);
                        return std::move(str);
                    }

                    friend basic_istring operator + (basic_istring&& ls, const value_type* s)
                    {
                        ls.append(s);
                        return ls;
                    }

                    friend basic_istring operator + (const basic_istring& ls, value_type ch)
                    {
                        basic_istring str(ls);
                        str.pushBack(ch);
                        return std::move(str);
                    }

                    friend basic_istring operator + (basic_istring&& ls, value_type ch)
                    {
                        ls.pushBack(ch);
                        return ls;
                    }

                    friend basic_istring operator + (const basic_istring& ls, std::initializer_list<value_type> ilist)
                    {
                        basic_istring str(ls);
                        str.append(ilist);
                        return std::move(str);
                    }

                    friend basic_istring operator + (basic_istring&& ls, std::initializer_list<value_type> ilist)
                    {
                        ls.append(ilist);
                        return ls;
                    }

                    friend basic_istring operator + (value_type ch, const basic_istring& rs)
                    {
                        basic_istring str(1, ch);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend basic_istring operator + (value_type ch, basic_istring&& rs)
                    {
                        basic_istring str(1, ch);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend basic_istring operator + (const value_type* s, const basic_istring& rs)
                    {
                        basic_istring str(s);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend basic_istring operator + (const value_type* s, basic_istring&& rs)
                    {
                        basic_istring str(s);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend basic_istring operator + (std::initializer_list<value_type> ilist, const basic_istring& rs)
                    {
                        basic_istring str(ilist);
                        str.append(rs);
                        return std::move(str);
                    }

                    friend basic_istring operator + (std::initializer_list<value_type> ilist, basic_istring&& rs)
                    {
                        basic_istring str(ilist);
                        str.append(rs);
                        return std::move(str);
                    }

                public:
                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief to_string / to_wstring
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    template <typename T>
                    static basic_istring valueOf(T&& value)
                    {
#ifdef __CPP_17__
                        if constexpr (std::is_same_v<Type, std::string>) {
                            return static_cast<basic_istring>(std::to_string(value));
                        }
                        return static_cast<basic_istring>(std::to_wstring(value));
#else
                        if (std::is_same_v<Type, std::string>) {
                            return static_cast<basic_istring>(std::to_string(value));
                        }
                        return static_cast<basic_istring>(std::to_wstring(value));
#endif
                    }

#if __LINUX__ && __GCC__ 

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief check str start with sub
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static bool startsWith(const basic_istring& sub, const basic_istring& str);

                    /****
                    * @author ticks
                    * @since 编写此代码的时间或版本
                    * @brief check str end with sub
                    *
                    * @param 参数名 注释
                    * @tparam 模板参数名 注释
                    * @future 未来要做的事情
                    * @retval 返回值注释
                    * @throws 抛出的异常
                    *
                    * @note
                    * 注意事项
                    * @endnote
                    * @pre 使用此函数的前提条件
                    * @par Example
                    * @code
                    * 代码示例
                    * @endcode
                    *
                    * @warning 警告
                    * @bug 存在的漏洞
                    * @include 需要包含的头文件
                    * @details
                    * 详细描述
                    * @enddetails
                    * @other 其他
                    ****/
                    static bool endsWith(const basic_istring& sub, const basic_istring& str);
#endif
                protected:

                private:
                    Type _data;
                };

#if __LINUX__ && __GCC__ 
#ifdef __CPP_20__
                template <typename Type> requires type::type_traits::is_std_string_v<Type>
                bool basic_istring<Type>::startsWith(const basic_istring& sub, const basic_istring& str)
#else
                template <typename Type, std::enable_if_t <type_traits::is_std_string_v<Type>, Type> t>
                bool basic_istring<Type, t>::startsWith(const basic_istring& sub, const basic_istring& str)
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
                bool basic_istring<Type>::endsWith(const basic_istring& sub, const basic_istring& str)
#else
                template <typename Type, std::enable_if_t <type_traits::is_std_string_v<Type>, Type> t>
                bool basic_istring<Type, t>::endsWith(const basic_istring& sub, const basic_istring& str)
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
#endif// __LINUX__ && __GCC__ 

            }//SPACE(basic)
        }//SPACE(type)
    }//SPACE(core)
}//SPACE(i)


#endif //!___MIRACLEFOREST_I_BASIC_ISTRING___