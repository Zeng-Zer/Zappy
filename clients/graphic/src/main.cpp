#include <iostream>
#include "Graph.hpp"

int			main()
{
  Graph			*g;

  try {
    g = new Graph(29, 29, "Zappy");
    g->run();
  }
  catch(std::exception e){
    std::cerr << e.what() << std::endl;
  }
  delete g;
}
