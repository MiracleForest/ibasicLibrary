/*
* 
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
* 
* @filename : numberArray.hpp
* @creation time : 2022.4.27 22:28
* @created by : WitherVictor
* @project:iBasicLibrary-BasicType
* -----------------------------------------------------------------------------
* Contains definition of class number
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback. 
* We will try to do our best!
*/

#include "number.hpp"
#include <iterator>
#include <initializer_list>

namespace i::core::type::basic
{
    template <typename Type>
    class numberArray_const_iterator
    {
        using self = numberArray_const_iterator<Type>;
        using element = number<Type>;
        using pointer = const element*;
        using reference = const element&;

    public:
        numberArray_const_iterator()
            : ptr(nullptr) {}
        numberArray_const_iterator(number<int>* iter)
            : ptr(iter) {}
        
        bool operator==(const self& other) const { return ptr == other.ptr; }
        reference operator* () const { return *ptr; }
        pointer operator->() const { return ptr; }

        self& operator++()
        {
            ptr++;
            return *this;
        }

        self operator++(int)
        {
            self tmp = *this;
            ++(*this);
            return tmp;
        }

        self& operator--()
        {
            ptr--;
            return *this;
        }

        self operator--(int)
        {
            self tmp = *this;
            --(*this);
            return tmp;
        }
    private:
        element* ptr;
    };

    template <typename Type>
    class numberArray_iterator
    {
        using self = numberArray_iterator<Type>;
        using element = number<Type>;
        using pointer = element*;
        using reference = element&;
    public:
        numberArray_iterator(number<Type>* iter)
            : ptr(iter) {}
        
        bool operator==(const self& other) const { return ptr == other.ptr; }
        reference operator* () { return *ptr; }
        pointer operator->() { return ptr; }

        self& operator++()
        {
            ptr++;
            return *this;
        }

        self operator++(int)
        {
            self tmp = *this;
            ++(*this);
            return tmp;
        }

        self& operator--()
        {
            ptr--;
            return *this;
        }

        self operator--(int)
        {
            self tmp = *this;
            --(*this);
            return tmp;
        }
        private:
            element* ptr;
    };

    template <typename Type, std::size_t Size>
    class numberArray
    {
        using iterator = numberArray_iterator<Type>;
        using const_iterator = numberArray_const_iterator<Type>;
        using element = number<Type>;
    public:
        numberArray()
            : _arr(new element[Size](0)) {}
        numberArray(std::initializer_list<Type> init_list)
            : _arr(new element[Size](0))
        {
            iterator iter = begin();
            auto list_iter = init_list.begin();
            if (init_list.size() <= Size)
            {
                for (; list_iter != init_list.end(); list_iter++, iter++)
                    *iter = number<Type>(*list_iter);
            }
            else
            {
                for (; iter != end(); list_iter++, iter++)
                {
                    *iter = number<Type>(*list_iter);
                }
            }
        }

        ~numberArray()
        {
            delete[] _arr;
            _arr = nullptr;
        }

        iterator begin() { return iterator(_arr); }
        iterator end() { return iterator(_arr + Size); }
        const_iterator cbegin() { return const_iterator(_arr); }
        const_iterator cend() { return const_iterator(_arr + Size); }
    private:
        number<Type>* _arr;
    };
}

namespace std
{
    template <typename T>
    using numberArray_iterator = i::core::type::basic::numberArray_iterator<T>;
    
    template <typename T>
    using numberArray_const_iterator = i::core::type::basic::numberArray_const_iterator<T>;

    template <typename T>
    using basic_number = i::core::type::basic::number<T>;

    template <typename T>
    numberArray_iterator<T> begin(const basic_number<T>& obj) { return obj.begin(); };

    template <typename T>
    numberArray_iterator<T> end(const basic_number<T>& obj) { return obj.end(); };

    template <typename T>
    numberArray_iterator<T> cbegin(const basic_number<T>& obj) { return obj.cbegin(); };

    template <typename T>
    numberArray_iterator<T> cend(const basic_number<T>& obj) { return obj.cend(); };

}