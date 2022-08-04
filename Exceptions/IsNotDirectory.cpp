//
// Created by chou on 22-8-3.
//

#include "IsNotDirectory.hpp"

const char *IsNotDirectory::what() const noexcept {
    return XArchiveFormatException::what();
}

IsNotDirectory::IsNotDirectory(const std::string &path) : XArchiveFormatException(path + " is not a directory.") {

}
