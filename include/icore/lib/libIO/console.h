/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：console.h
* @创建时间：2022.6.18.10:21
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I__LIBIO_CONSOLE___
#define ___MIRACLEFOREST_I__LIBIO_CONSOLE___

#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <mutex>
#include <memory>
#include "../../family/imacrofamily.h"
#include <format>
#include "../../type/istring.hpp"

SPACE(i) {
    SPACE(core) {
        SPACE(libIO) {
            enum class ConsoleType
            {
                Normal,
                Page
            };

            template <ConsoleType type = ConsoleType::Page>
            class IAPI Console {};

            /**
             * 模板特化，普通Console类
             */
            template <>
            class IAPI Console<ConsoleType::Normal> {
            public:
                // 默认缓冲区大小
                static const size_t default_console_buffer_size = 1024;
                enum class BufferType {
                    LineBuffer,
                    FullBuffer,
                    NoBuffer
                };
            public:
                // 单例模式，确保只有一个 Console 类
                static Console& getConsole()
                {
                    if ( !_console_instance ) {
                        std::lock_guard<std::mutex> lock(_mutex);
                        if ( nullptr == _console_instance ) {
                            _console_instance = new Console();
                        }
                    }
                    return *_console_instance;
                }
                static Console* getConsolePtr()
                {
                    if ( !_console_instance ) {
                        std::lock_guard<std::mutex> lock(_mutex);
                        if ( nullptr == _console_instance ) {
                            _console_instance = new Console();
                        }
                    }
                    return _console_instance;
                }

                /**
                * @author Ticks
                * @since 22-7-8 下午1:05
                *
                * @brief 编写函数描述
                *
                * @param 编写参数 注释
                * @tparam 编写模板参数 注释
                * @retval 编写函数返回值 注释
                * @future 编写未来计划
                * @throws 编写函数抛出异常
                *
                * @note
                * 编写注意事项
                * @endnote
                * @pre 编写函数使用前提
                * @code
                * 编写代码示例
                * @endcode
                *
                * @include 包含头文件
                * @details
                *
                * @enddetails
                *
                * @warning
                * @bug
                *
                * @other
                *
                **/
                void setOutBufferType(BufferType type)
                {
                    switch ( type ) {
                    case BufferType::NoBuffer:
                        fflush(stdout);
                        this->_out_buf_type = BufferType::NoBuffer;
                        std::setvbuf(stdout, nullptr, _IONBF, 0);
                        break;
                    case BufferType::LineBuffer:
                        fflush(stdout);
                        this->_out_buf_type = BufferType::LineBuffer;
                        std::setvbuf(stdout, this->_out_buf, _IOLBF, this->_out_buf_size);
                        break;
                    case BufferType::FullBuffer:
                        fflush(stdout);
                        this->_out_buf_type = BufferType::FullBuffer;
                        std::setvbuf(stdout, this->_out_buf, _IOFBF, this->_out_buf_size);
                        break;
                    }
                }
                void setInBufferType(BufferType type)
                {
                    switch ( type ) {
                    case BufferType::NoBuffer:
                        fflush(stdin);
                        this->_out_buf_type = BufferType::NoBuffer;
                        std::setvbuf(stdin, nullptr, _IONBF, 0);
                        break;
                    case BufferType::LineBuffer:
                        fflush(stdin);
                        this->_out_buf_type = BufferType::LineBuffer;
                        std::setvbuf(stdin, this->_out_buf, _IOLBF, this->_out_buf_size);
                        break;
                    case BufferType::FullBuffer:
                        fflush(stdin);
                        this->_out_buf_type = BufferType::FullBuffer;
                        std::setvbuf(stdin, this->_out_buf, _IOFBF, this->_out_buf_size);
                        break;
                    }
                }

                /**
                * @author Ticks
                * @since 22-7-8 下午1:05
                *
                * @brief 编写函数描述
                *
                * @param 编写参数 注释
                * @tparam 编写模板参数 注释
                * @retval 编写函数返回值 注释
                * @future 编写未来计划
                * @throws 编写函数抛出异常
                *
                * @note
                * 编写注意事项
                * @endnote
                * @pre 编写函数使用前提
                * @code
                * 编写代码示例
                * @endcode
                *
                * @include 包含头文件
                * @details
                *
                * @enddetails
                *
                * @warning
                * @bug
                *
                * @other
                *
                **/
                void setOutBufferSize(size_t size)
                {
                    if ( size == 0 ) {
                        this->setOutBufferType(BufferType::NoBuffer);
                        this->_out_buf_size = 0;
                        delete[] this->_out_buf;
                        this->_out_buf = nullptr;
                        return;
                    }
                    if ( this->_out_buf_size == 0 ) {
                        this->_out_buf_size = size;
                        char* tmp_buf = this->_out_buf;
                        this->_out_buf = new char[this->_out_buf_size];
                        if ( tmp_buf ) {
                            std::memcpy(this->_out_buf, tmp_buf, this->_out_buf_size);
                            delete[] tmp_buf;
                        }
                        this->setOutBufferType(BufferType::FullBuffer);
                        return;
                    }
                    this->_out_buf_size = size;
                    char* tmp_buf = this->_out_buf;
                    this->_out_buf = new char[this->_out_buf_size];
                    if ( tmp_buf ) {
                        std::memcpy(this->_out_buf, tmp_buf, this->_out_buf_size);
                        delete[] tmp_buf;
                    }
                    this->setOutBufferType(this->_out_buf_type);
                }

                void setInBufferSize(size_t size)
                {
                    if ( size == 0 ) {
                        this->setInBufferType(BufferType::NoBuffer);
                        this->_in_buf_size = 0;
                        delete[] this->_in_buf;
                        this->_in_buf = nullptr;
                        return;
                    }
                    if ( this->_in_buf_size == 0 ) {
                        this->_in_buf_size = size;
                        char* tmp_buf = this->_in_buf;
                        this->_in_buf = new char[this->_in_buf_size];
                        if ( tmp_buf ) {
                            std::memcpy(this->_in_buf, tmp_buf, this->_in_buf_size);
                            delete[] tmp_buf;
                        }
                        this->setInBufferType(BufferType::FullBuffer);
                        return;
                    }
                    this->_in_buf_size = size;
                    char* tmp_buf = this->_in_buf;
                    this->_in_buf = new char[this->_in_buf_size];
                    if ( tmp_buf ) {
                        std::memcpy(this->_in_buf, tmp_buf, this->_in_buf_size);
                        delete[] tmp_buf;
                    }
                    this->setInBufferType(this->_in_buf_type);
                }

                Console& write(CPtr<char> format, ...)
                {
                    va_list list = new char;
                    vprintf(format, list);
                    return *this;
                }
                Console& write(CRef<type::istring> str)
                {
#ifdef __WINDOWS__
                    printf_s("%s", str.data());
#else
                    printf("%s", str.data());
#endif
                    return *this;
                }
                Console& writeLine(CRef<type::istring> str)
                {
#ifdef __WINDOWS__
                    printf_s("%s\n", str.data());
#else
                    printf("%s\n", str.data());
#endif
                    return *this;
                }

                char read()
                {
                    return (char) getchar();
                }
                Console& readLine(char* buf, size_t buf_len)
                {
                    size_t read_len = 0;
                    int tmp;
                    while ( read_len < buf_len && (tmp = getchar()) != '\n' ) {
                        buf[read_len++] = (char) tmp;
                    }
                    buf[read_len] = '\0';
                    return *this;
                }

                type::istring readLine()
                {
                    type::istring str;
                    int tmp;
                    while ( (tmp = getchar()) != '\n' ) {
                        str.pushBack((char) tmp);
                    }
                    return str;
                }

            public:
                Console& operator = (const Console&) = delete;
                Console(const Console&) = delete;

                Console& operator << (CPtr<char> str)
                {
                    return this->write("%s", str);
                }
                Console& operator << (CRef<type::istring> str)
                {
                    return this->write(str);
                }

                Console& operator >> (Ref<char> ch)
                {
                    ch = this->read();
                    return *this;
                }
                Console& operator >> (Ref<type::istring> buf)
                {
                    buf.assign(this->readLine());
                    return *this;
                }

            private:
                Console()
                    : _out_buf_size(default_console_buffer_size)
                    , _out_buf(new char[default_console_buffer_size])
                    , _out_buf_type(BufferType::LineBuffer)
                    , _in_buf_size(default_console_buffer_size)
                    , _in_buf(new char[default_console_buffer_size])
                    , _in_buf_type(BufferType::LineBuffer)
                {
                    this->setOutBufferType(this->_out_buf_type);
                    this->setInBufferType(this->_in_buf_type);
                }

                ~Console()
                {
                    fflush(stdin);
                    delete[] this->_in_buf;
                    this->_in_buf = nullptr;
                    this->_in_buf_size = 0;
                    this->setInBufferType(this->_in_buf_type);

                    fflush(stdout);
                    delete[] this->_out_buf;
                    this->_out_buf = nullptr;
                    this->_out_buf_size = 0;
                    this->setOutBufferType(this->_out_buf_type);
                }

            private:
                static Console* _console_instance;
                static std::mutex _mutex;
            private:
                char* _out_buf;              // 输出缓冲区地址
                char* _in_buf;               // 输入缓冲区地址
                size_t _out_buf_size;        // 输出缓冲区大小
                size_t _in_buf_size;         // 输入缓冲区大小
                BufferType _out_buf_type;    // 输出缓冲类型
                BufferType _in_buf_type;     // 输入缓冲类型

            }; // class Console<Normal>
            Console<ConsoleType::Normal>* Console<ConsoleType::Normal>::_console_instance = nullptr;
            std::mutex Console<ConsoleType::Normal>::_mutex;


        } // namespace libIO
    } // namespace core
} // namespace i



#endif //!___MIRACLEFOREST_I__LIBIO_CONSOLE___