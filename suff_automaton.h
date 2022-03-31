#include <map>
#include <vector>

class SuffAutomaton {
 public:

  SuffAutomaton();

  void Insert(const std::string &s);

  size_t Find(const std::string &s);

  ~SuffAutomaton() = default;

 private:

  void AddSym(char c);

  struct Node {
    Node(int len = 0, int link = 0) : l(len), link(link) {}
    int l, link;
    std::map<char, int> to;
    int first_pos = 0;
  };

  std::vector<Node> vertex_;
  int last_;
};