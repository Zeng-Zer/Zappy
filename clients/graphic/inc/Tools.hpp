#ifndef TOOLS_HPP_
# define TOOLS_HPP_

# include <string>
# include <sstream>

namespace Tools {
  unsigned parseStreamUnsignedInt(std::stringstream&);
  int parseStreamInt(std::stringstream&);
  std::string parseStreamString(std::stringstream&);
}

#endif /* !TOOLS_HPP_ */
