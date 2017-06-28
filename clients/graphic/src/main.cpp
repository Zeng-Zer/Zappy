#include <iostream>
#include "Graph.hpp"

int			main()
{
  Graph			*g;

  try {
    g = new Graph(7, 7, "Zappy");
    g->run();
  }
  catch(std::exception e){
    std::cerr << e.what() << std::endl;
  }
  delete g;
}
