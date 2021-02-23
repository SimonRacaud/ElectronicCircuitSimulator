#ifndef OPEN_FILE_HPP_
#define OPEN_FILE_HPP_

#include "Error/Error.hpp"

class OpenFileException : public ManageError {
  public:
    OpenFileException(std::string const &message = "Standard", std::string const &component = "Initialisation") : ManageError(message, component)
    {
    }
};

#endif