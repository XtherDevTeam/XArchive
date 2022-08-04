//
// Created by chou on 22-8-3.
//

#ifndef XARCHIVE_XARCHIVEFORMATEXCEPTION_HPP
#define XARCHIVE_XARCHIVEFORMATEXCEPTION_HPP


#include <exception>
#include <string>

class XArchiveFormatException : std::exception {
    std::string s;
public:
    XArchiveFormatException(std::string str);

    const char * what() const noexcept override;
};


#endif //XARCHIVE_XARCHIVEFORMATEXCEPTION_HPP
