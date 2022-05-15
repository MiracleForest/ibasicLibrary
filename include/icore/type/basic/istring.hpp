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

#include <string>

namespace i::core {
	namespace type {
		namespace basic {

			template<typename Type>
			class istring final{
			public:

                //
                // typedef same as strString typedef
                //
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
                //
                // istring all Constructor
                //
                explicit istring()
                    : _data(){}

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
                    : _data(other) {}

                istring(const istring&& other) noexcept
                    : _data(other) {}

                istring(std::initializer_list<value_type> ilist)
                    : _data(ilist) {}

                template<class InputIt> istring(InputIt first, InputIt last)
                    : _data(first, last) {}

                ~ istring(){}

                //
                // istring assign as stdString assign
                //
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
                    this->_data.assign(str._data);
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

                //
                // get the stdString allocator
                //
                allocator_type getAllocator() const
                {
                    return this->_data.get_allocator();
                }

                //
                // get the istring char at pos
                //
                // exception : when pos >= length() throw std::out_of_range
                //
                reference charAt(size_type pos)
                {
                    return this->_data.at(pos);
                }

                const_reference charAt(size_type pos) const
                {
                    return this->_data.at(pos);
                }

                //
                // get istring first char
                //
                // if istring length() == 0, the behavior is undefined
                //
                reference front()
                {
                    return this->_data.front();
                }

                const_reference front() const
                {
                    return this->_data.front();
                }

                //
                // get istring last char
                //
                // if istring length() == 0, the behavior is undefined
                //
                reference back()
                {
                    return this->_data.back();
                }

                const_reference back() const
                {
                    return this->_data.back();
                }

                //
                // get istring string pointer
                //
                const value_type* data() const noexcept
                {
                    return this->_data.data();
                }

                value_type* data() noexcept
                {
                    return this->_data.data();
                }

                //
                // get istring c style string
                //
                const value_type* cString() const noexcept
                {
                    return this->_data.c_str();
                }

                //
                // get istring first  iterator
                //
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

                //
                // get istring last iterator
                //
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

                //
                // get istring first reverse iterator
                //
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

                //
                // get istring last reverse iterator
                //
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

                //
                // check istring length() == 0
                //
                bool empty() const noexcept
                {
                    return this->_data.empty();
                }

                //
                // get istring length
                //
                size_type length() const noexcept
                {
                    return this->_data.length();
                }

                size_type size() const noexcept
                {
                    return this->_data.size();
                }

                //
                // get istring max contain
                //
                size_type maxSize() const noexcept
                {
                    return this->_data.max_size();
                }

                //
                // set istring alloc size
                //
                void reserve(size_type new_cap = static_cast<size_type>(0))
                {
                    this->_data.reserve(new_cap);
                }

                //
                // get istring alloc current size
                //
                size_type capacity() const noexcept
                {
                    return this->_data.capacity();
                }

                //
                // fit current alloc size to current string size
                //
                void fitAllocSize()
                {
                    this->_data.shrink_to_fit();
                }

                //
                // clear istring
                //
                void clear() noexcept
                {
                    this->_data.clear();
                }

                //
                // insert ch or string to istring
                //
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


			public:
                //
                // istring assignment operator
                //
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

                //
                // get istring char at pos
                //
                // if pos >= size(), the behavior is undefined
                //
                reference operator [] (size_type pos)
                {
                    return this->_data[pos];
                }

                const_reference operator [] (size_type pos) const
                {
                    return this->_data[pos];
                }

			public:

			protected:

			private:
				Type _data;
			};


		}//namespace basic
	}//namespace type
}//namespace i::core


#endif //!___MIRACLEFOREST_I_ISTRING___