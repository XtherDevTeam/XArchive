//
// Created by chou on 22-8-3.
//

#ifndef XARCHIVE_ARCHIVEFORMAT_HPP
#define XARCHIVE_ARCHIVEFORMAT_HPP

#include <cstddef>
#include <cstdio>
#include <string>
#include <filesystem>

namespace XArchive {

    class ArchiveFormat {
        FILE* FilePointer;

        void WriteFileInfo(const std::string &expect_dirpath, const std::filesystem::path &path);
    public:
        void CompressDirectory(const std::string &expect_dirpath, const std::filesystem::path &dir,
                               const std::filesystem::path &output_filename);

        void DecompressToDirectory(const std::filesystem::path &file_path, const std::filesystem::path &dir);
    };

} // XArchive

#endif //XARCHIVE_ARCHIVEFORMAT_HPP
