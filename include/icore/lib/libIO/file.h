/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:file.h
* @creation time:2022.6.12.12:44
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I__LIBIO_FILE___
#define ___MIRACLEFOREST_I__LIBIO_FILE___

#include "../../family/imacrofamily.h"
#include "../../type/istring.hpp"
#include "../../type/time.hpp"

#include "../../../cppstd/format"
#include "../../../cppstd/vector"
#include "../../../cppstd/map"
#include "../../../cppstd/memory"
#if __CPP_17__
#include "../../../cppstd/filesystem"
#endif//__CPP_17_
#include "../../../cppstd/fstream"
#include "../../../cppstd/optional"

#if __WINDOWS__
#include <io.h>
#endif

SPACE(i) {
    SPACE(core) {
        SPACE(libIO) {

            struct iFileInfo {
                type::istring name;//文件名
                type::istring fname;//文件名（含扩展名）
                type::istring path;//文件路径
                type::istring extensionName;//扩展名
                size_t size;//文件大小
                int lineCount;//文件行数
                type::time createTime;//创建时间
                type::time modifyTime;//修改时间
                __unk_type__ md5;//md5
                __unk_type__ authority;//权限
                type::time lastVisitTime;//最后访问时间
            };

            class IAPI File {
            public:
                File();
                ~File();
            public:

                public C_STATIC :

                    /****
                        * @author Lovelylavender4
                        * @brief NULL
                        * @param filePath 文件路径
                        * @param isBinary = false 是否是二进制
                        * @future NULL
                        * @retval std::optional<std::string>
                        * @throws NULL
                        * @note
                        * @par Example
                        * @code
                        * NULL
                        * @endcode
                        * @warning NULL
                        * @bug NULL
                        * @include <optional>,<fstream>,<filesystem>,istring,
                        ****/
                    static std::optional<type::istring> readAllFile(const type::istring& filePath, bool isBinary = false) {
                    std::ifstream fRead;

                    std::ios_base::openmode mode = std::ios_base::in;
                    if (isBinary) {
                        mode |= std::ios_base::binary;
                    }
                    fRead.open(type::istring::str2wstr(filePath.data()), mode);
                    if (!fRead.is_open()) {
                        return std::nullopt;
                    }
                    type::istring data(
                        (std::istreambuf_iterator<char>(fRead)),
                        std::istreambuf_iterator<char>()
                    );
                    fRead.close();
                    return data;
                }

                /****
                    * @author Lovelylavender4
                    * @brief NULL
                    * @param filePath 文件路径
                    * @param content 内容
                    * @param isBinary = false 是否是二进制
                    * @future NULL
                    * @retval bool
                    * @throws NULL
                    * @note NULL
                    * @par Example
                    * @code
                    * NULL
                    * @endcode
                    * @warning NULL
                    * @bug NULL
                    * @include NULL
                    ****/
                static bool writeAllFile(const std::string& filePath, const std::string& content, bool isBinary = false) {
                    std::ofstream fWrite;

                    std::ios_base::openmode mode = std::ios_base::out;
                    if (isBinary)
                        mode |= std::ios_base::binary;

                    fWrite.open(i::core::type::istring::str2wstr(filePath), mode);
                    if (!fWrite.is_open()) {
                        return false;
                    }
                    fWrite << content;
                    fWrite.close();
                    return true;
                }

#if __CPP_17__
                /****
                * @author Lovelylavender4
                * @since 2022.6.24.12:30
                * @brief 获取目标目录下文件名列表
                *
                * @param dir 目标目录
                * @future 实现在C++17以下可使用
                * @retval 文件名列表
                * @throws 抛出的异常
                *
                * @note
                * 注意事项
                * @endnote
                * @pre 代码使用的前提条件
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
                static std::vector<std::string> getFileNameList(const std::string& dir)
                {
                    std::filesystem::directory_entry d(dir);
                    if (!d.is_directory())
                        return {};

                    std::vector<std::string> list;
                    std::filesystem::directory_iterator deps(d);
                    for (auto& i : deps)
                    {
                        list.push_back(i.path().filename().string());
                    }
                    return list;
                }

                /****
                * @author Lovelylavender4
                * @brief NULL
                * @param NULL NULL
                * @tparam NULL NULL
                * @future NULL
                * @retval NULL
                * @throws NULL
                * @note NULL
                * @par Example
                * @code
                * NULL
                * @endcode
                * @warning NULL
                * @bug NULL
                * @include NULL
                ****/
                static bool createDirs(const std::string path)
                {
                    std::error_code ec;
                    return std::filesystem::create_directories(std::filesystem::path(i::core::type::istring::str2wstr(path)).remove_filename(), ec);
                }

#endif//__CPP_17__

            protected:
            private:

            };

            SPACE(_function) {

            }

        }//namespace libIO
    }//namespace core
}//namespace i

#endif //!___MIRACLEFOREST_I__LIBIO_FILE___