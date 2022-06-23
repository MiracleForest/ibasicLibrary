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

namespace i {
    namespace core {
        namespace libIO {

            struct iFileInfo {
                type::istring name;//�ļ���
                type::istring fname;//�ļ���������չ����
                type::istring path;//�ļ�·��
                type::istring extensionName;//��չ��
                size_t size;//�ļ���С
                int lineCount;//�ļ�����
                __unk_type__ createTime;//����ʱ��
                __unk_type__ modifyTime;//�޸�ʱ��
                __unk_type__ md5;//md5
                __unk_type__ authority;//Ȩ��
                __unk_type__ lastVisitTime;//������ʱ��
                HICON icon;//ͼ��
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
                * @param filePath �ļ�·��
                * @param isBinary = false �Ƿ��Ƕ�����
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
                * @param filePath �ļ�·��
                * @param content ����
                * @param isBinary = false �Ƿ��Ƕ�����
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

                    fWrite.open(type::istring::str2wstr(filePath), mode);
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
                * @since ��д�˴����ʱ���汾
                * @brief ����
                *
                * @param dir Ŀ��Ŀ¼
                * @future δ��Ҫ��������
                * @retval �ļ����б�
                * @throws �׳����쳣
                *
                * @note
                * ע������
                * @endnote
                * @pre ����ʹ�õ�ǰ������
                * @par Example
                * @code
                * ����ʾ��
                * @endcode
                *
                * @warning ����
                * @bug ���ڵ�©��
                * @include ��Ҫ������ͷ�ļ�
                * @details
                * ��ϸ����
                * @enddetails
                * @other ����
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
                    return std::filesystem::create_directories(std::filesystem::path(type::istring::str2wstr(path)).remove_filename(), ec);
                }
#endif//__CPP_17__
            protected:
            private:

            };

        }//namespace libIO
    }//namespace core
}//namespace i

#endif //!___MIRACLEFOREST_I__LIBIO_FILE___