//
// Created by chou on 22-8-3.
//

#include <iostream>
#include "ArchiveFormat.hpp"
#include "../Exceptions/IsNotDirectory.hpp"

namespace XArchive {
    void
    ArchiveFormat::CompressDirectory(const std::string &expect_dirpath, const std::filesystem::path &dir,
                                     const std::filesystem::path &output_filename) {
        if (!output_filename.empty())
            FilePointer = fopen(output_filename.c_str(), "wb+");
        if (std::filesystem::is_directory(dir)) {
            for (auto &Item: std::filesystem::directory_iterator(dir)) {
                if (Item.is_directory()) {
                    CompressDirectory(expect_dirpath / Item.path().filename(),
                                      Item.path(), "");
                } else {
                    if (Item.path() == output_filename or Item.path() == "." / output_filename)
                        continue;
                    WriteFileInfo(expect_dirpath, Item.path());
                }
            }
        } else {
            throw IsNotDirectory(dir);
        }
        if (!output_filename.empty())
            fclose(FilePointer);
    }

    void ArchiveFormat::WriteFileInfo(const std::string &expect_dirpath, const std::filesystem::path &path) {
        size_t dirpath_len = expect_dirpath.length();
        size_t filename_len = path.filename().string().length();
        size_t file_len = std::filesystem::file_size(path);
        fwrite(&dirpath_len, sizeof dirpath_len, 1, FilePointer);
        fwrite(expect_dirpath.data(), dirpath_len, 1, FilePointer);
        fwrite(&filename_len, sizeof filename_len, 1, FilePointer);
        fwrite(path.filename().string().data(), filename_len, 1, FilePointer);
        fwrite(&file_len, sizeof file_len, 1, FilePointer);

        FILE *fp = fopen(path.string().c_str(), "rb");
        std::string buffer(1048576, '\0');
        while (!feof(fp)) {
            size_t len = fread(buffer.data(), 1, buffer.size(), fp);
            fwrite(buffer.data(), len, 1, FilePointer);
        }
        fclose(fp);
    }

    void
    ArchiveFormat::DecompressToDirectory(const std::filesystem::path &file_path, const std::filesystem::path &dir) {
        FilePointer = fopen(file_path.string().c_str(), "rb");
        if (std::filesystem::is_directory(dir)) {
            while (!feof(FilePointer)) {
                size_t tempVal;
                std::string expect_dir;
                fread(&tempVal, sizeof tempVal, 1, FilePointer);
                expect_dir.resize(tempVal);
                fread(expect_dir.data(), tempVal, 1, FilePointer);

                std::string filename;
                fread(&tempVal, sizeof tempVal, 1, FilePointer);
                filename.resize(tempVal);
                fread(filename.data(), tempVal, 1, FilePointer);

                fread(&tempVal, sizeof tempVal, 1, FilePointer);

                if (feof(FilePointer))
                    break;

                std::filesystem::create_directories(dir / expect_dir);
                std::filesystem::path path = dir / expect_dir / filename;
                std::cout << "Path: " << path.string() << " \n" << std::endl;
                FILE *fp = fopen(path.string().c_str(), "wb");

                std::string buffer(1048576, '\0');
                while (tempVal) {
                    size_t read_size = 1048576 > tempVal ? tempVal : 1048576;
                    size_t size = fread(buffer.data(), 1, read_size, FilePointer);
                    fwrite(buffer.data(), size, 1, fp);
                    tempVal -= read_size;
                }
                fclose(fp);
            }
        } else {
            throw IsNotDirectory(dir);
        }
        fclose(FilePointer);
    }
} // XArchive