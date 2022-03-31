#include "suff_automaton.h"

SuffAutomaton::SuffAutomaton() {
  last_ = 0;
  vertex_.emplace_back(0, -1);
}

void SuffAutomaton::Insert(const std::string &s) {
  for (char i: s) {
    AddSym(i);
  }
}

size_t SuffAutomaton::Find(const std::string &s) {
  int i = 0, v = 0;
  while (i < s.size()) {
    auto it = vertex_[v].to.find(s[i++]);
    if (it == vertex_[v].to.end()) {
      return 0;
    }
    v = it->second;
  }
  return vertex_[v].first_pos - s.size() + 2;
}

void SuffAutomaton::AddSym(char c) {
  int cur = vertex_.size();
  vertex_.emplace_back(vertex_[last_].l + 1);

  vertex_[cur].first_pos = vertex_[cur].l - 1;

  int p;
  for (p = last_; p != -1 && !vertex_[p].to.count(c); p = vertex_[p].link) {
    vertex_[p].to[c] = cur;
  }
  if (p == -1) {
    vertex_[cur].link = 0;
  } else {
    int q = vertex_[p].to[c];
    if (vertex_[p].l + 1 == vertex_[q].l) {
      vertex_[cur].link = q;
    } else {
      int clone = vertex_.size();
      vertex_.emplace_back(vertex_[p].l + 1);

      vertex_[clone].link = vertex_[q].link;
      vertex_[clone].to = vertex_[q].to;
      vertex_[clone].first_pos = vertex_[q].first_pos;

      while (p != -1 && vertex_[p].to[c] == q) {
        vertex_[p].to[c] = clone;
        p = vertex_[p].link;
      }
      vertex_[q].link = clone;
      vertex_[cur].link = clone;
    }
  }
  last_ = cur;
}