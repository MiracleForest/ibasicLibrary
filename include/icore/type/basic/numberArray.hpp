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
#include <exception>

namespace i::core::type::basic
{

    template <typename Type, std::size_t Size>
    class numberArray_const_iterator
    {
    public:
        using self = numberArray_const_iterator<Type, Size>;
        using element = number<Type>;


        using value_type = Type;
        using difference_type = ptrdiff_t;
        using pointer = const element*;
        using reference = const element&;
        using iterator_concept = std::contiguous_iterator_tag;
        using iterator_category = std::random_access_iterator_tag;

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

    template <typename Type, std::size_t Size>
    class numberArray_iterator
    {
    public:
        using self = numberArray_iterator<Type, Size>;
        using element = number<Type>;

        using value_type = Type;
        using difference_type = ptrdiff_t;
        using pointer = element*;
        using reference = element&;
        using iterator_concept = std::contiguous_iterator_tag;
        using iterator_category = std::random_access_iterator_tag;

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
    public:
        using iterator = numberArray_iterator<Type, Size>;
        using const_iterator = numberArray_const_iterator<Type, Size>;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
        using value_type = Type;
        using element = number<Type>;
        using pointer = element*;

        numberArray()
            : _arr({0}) {}
        numberArray(std::initializer_list<Type> init_list)
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

        numberArray(const numberArray&) = default;

        ~numberArray() = default;

        element& at(std::size_t index)
        {
            if (!(index < size()))
                throw std::out_of_range("Index is out of number array bound");
            else
                return _arr[index];
        }

        std::size_t size()
        { return Size; }

        element& operator[](std::size_t index)
        { return _arr[index]; }

        pointer data()
        { return _arr; }

        iterator begin()
        { return iterator(_arr); }

        iterator end()
        { return iterator(_arr + Size); }

        element& front()
        { return *begin(); }

        element& back()
        { return *end(); }

        const_iterator cbegin()
        { return const_iterator(_arr); }

        const_iterator cend()
        { return const_iterator(_arr + Size); }

        reverse_iterator rbegin()
        { return reverse_iterator(end()); }

        reverse_iterator rend()
        { return reverse_iterator(begin()); }

        const_reverse_iterator crbegin()
        { return const_reverse_iterator(end()); }

        const_reverse_iterator crend()
        { return const_reverse_iterator(begin()); }
    private:
        number<Type> _arr[Size] {0};
    };
}

namespace std
{
    template <typename T, std::size_t S>
    using numberArray_iterator = i::core::type::basic::numberArray_iterator<T, S>;
    
    template <typename T, std::size_t S>
    using numberArray_const_iterator = i::core::type::basic::numberArray_const_iterator<T, S>;

    template <typename T>
    using basic_number = i::core::type::basic::number<T>;

    template <typename T, std::size_t S>
    numberArray_iterator<T, S> begin(const basic_number<T>& obj) { return obj.begin(); };

    template <typename T, std::size_t S>
    numberArray_iterator<T, S> end(const basic_number<T>& obj) { return obj.end(); };

    template <typename T, std::size_t S>
    numberArray_const_iterator<T, S> cbegin(const basic_number<T>& obj) { return obj.cbegin(); };

    template <typename T, std::size_t S>
    numberArray_const_iterator<T, S> cend(const basic_number<T>& obj) { return obj.cend(); };

}