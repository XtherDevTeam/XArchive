//
// Created by chou on 22-8-3.
//

#ifndef XARCHIVE_ARCHIVEFORMAT_HPP
#define XARCHIVE_ARCHIVEFORMAT_HPP

#include <cstddef>
#include <cstdio>
#include <string>
#include <filesystem>
#include <vector>

namespace XArchive {

    class ArchiveFormat {
        FILE* FilePointer;

        void WriteFileInfo(const std::filesystem::path &expect_dirpath, const std::filesystem::path &path);
    public:
        static std::vector<std::filesystem::path> MakeIgnoreFileList(const std::filesystem::path &dir, const std::vector<std::filesystem::path> &ignore_files);

        void CompressDirectory(const std::filesystem::path &expect_dirpath, const std::filesystem::path &dir,
                               const std::filesystem::path &output_filename, const std::vector<std::filesystem::path> &ignore_files);

        void DecompressToDirectory(const std::filesystem::path &file_path, const std::filesystem::path &dir);
    };

} // XArchive

#endif //XARCHIVE_ARCHIVEFORMAT_HPP
