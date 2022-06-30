/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:matrix.hpp
* @creation time:2022.6.23.16:32
* @created by:ChenMiaoi
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I__LIBMATH_MATRIX___
#define ___MIRACLEFOREST_I__LIBMATH_MATRIX___

#include "../../family/imacrofamily.h"
#include "math.h"
#include "../../type/istring.hpp"
#include "../../../cppstd/vector"
#include "../../../cppstd/initializer_list"

namespace i{
    namespace core{
        namespace libmath{
            template <typename T>
            class Matrix{
            public:
                typedef size_t MATRIX_TYPE;
                typedef size_t MATRIX_NUM;

            public:
                Matrix() {
                    _rows_num = 0; _cols_num = 0; _size = _rows_num * _cols_num;
                    zeros();
                }

                Matrix(MATRIX_TYPE row, MATRIX_TYPE col)
                    : _rows_num(row)
                    , _cols_num(col)
                    , _size(_rows_num * _cols_num)
                { zeros(); }

                ~Matrix() {

                }

            public:
                void zeros() {
                    _matrix = {0};
                }

                void ones() {
                    for (size_t row = 0; row < _rows_num; row++) {
                        for (size_t col = 0; col < _cols_num; col++) {
                            _matrix[row][col] = 1;
                        }
                    }
                }

                Matrix& array(std::initializer_list<T> li) {
                    for (auto e : li) {
                        _matrix = e;
                    }
                    return _matrix;
                }

                Matrix& arange(size_t start, size_t end) {
                    if ((start * end) != _size) {
                        perror("The numbers can't get a matrix!");
                        exit(1);
                    }
                    for (size_t row = 0; row < _rows_num; row++){
                        for (size_t col = 0; col < _cols_num; col++) {
                            _matrix[row][col] = start;
                            if (start < end) {
                                start++;
                            }
                        }
                    }
                    return _matrix;
                }
            private:
                MATRIX_TYPE _cols_num;
                MATRIX_TYPE _rows_num;
                MATRIX_NUM _size;
                std::vector< std::vector<T> > _matrix;
            };
        }
    }
}


#endif // !___MIRACLEFOREST_I__LIBMATH_MATRIX___
