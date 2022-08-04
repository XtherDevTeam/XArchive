//
// Created by chou on 22-8-3.
//

#ifndef XARCHIVE_ISNOTDIRECTORY_HPP
#define XARCHIVE_ISNOTDIRECTORY_HPP


#include <exception>
#include "XArchiveFormatException.hpp"

class IsNotDirectory : XArchiveFormatException {
public:
    IsNotDirectory(const std::string &path);

    const char * what() const noexcept override;
};


#endif //XARCHIVE_ISNOTDIRECTORY_HPP
