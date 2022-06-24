#include "../../../include/icore/lib/libIO/file.h"

i::core::libIO::File::File()
{
}

i::core::libIO::File::~File()
{
}

bool writeAllFile(const std::string& filePath, const std::string& content, bool isBinary) {
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

std::vector<std::string> getFileNameList(const std::string& dir)
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

bool createDirs(const std::string path)
{
    std::error_code ec;
    return std::filesystem::create_directories(std::filesystem::path(i::core::type::istring::str2wstr(path)).remove_filename(), ec);
}


#endif//__CPP_17__

