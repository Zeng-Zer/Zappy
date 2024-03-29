#ifndef TOOLS_HPP_
# define TOOLS_HPP_

# include <string>
# include <sstream>

# include <iostream>

namespace Tools {

  template<typename T>
  T parseStream(std::stringstream& ss) {
    T value;
    ss >> value;
    if (ss.fail()) {
      return 0;
    }
    std::cout << "Value: " << value << std::endl;
    return value;
  }

  std::string parseStreamString(std::stringstream&);
}

#endif /* !TOOLS_HPP_ */
