#include <arrayfire.h>
#include <vector>
class Node
{
public:
  float _x;
  float _y;
  float _z;
  float _value;
  float _index;
  Node() : _x(0.0f), _y(0.0f), _z(0.0f), _value(0.0f), _index(0.0f){}
};

class Element
{
public:
  std::vector<Node> _nodes;
  int _number;
  int _num_nodes_in_an_element;

  Element():_number(0),_num_nodes_in_an_element(0){}
  
  Element(int num_node):
    _number(0),
    _num_nodes_in_an_element(num_node),
    _nodes(num_node,Node())
    {}
};

class FEM2D{
public:
    
};

int main(void)
{
    int size = 300;
    int grid = 300 * 300 * 2;
    Mesh mesh = createMesh(size, size, grid);
    af::array problem = buildProblem(Mesh,b,size);
}
