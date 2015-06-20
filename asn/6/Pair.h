#ifndef PAIR_H
#define PAIR_H

#include <string>

template<typename HashedObj, typename Object>
class Pair
{
public:
  Pair() {}
  Pair(const HashedObj & key, const Object & def) : key(key), def(def) {}

  bool operator ==(const Pair<HashedObj, Object> & rhs) const
  {return key == rhs.key;}

  bool operator !=(const Pair<HashedObj, Object> & rhs) const
  {return !(*this == rhs);}

  HashedObj get_key() const {return key;}

  const HashedObj & get_def() const {return def;}

private:
  HashedObj key;
  Object    def;
};

int hash(const Pair<std::string, std::string> & key);

#endif
