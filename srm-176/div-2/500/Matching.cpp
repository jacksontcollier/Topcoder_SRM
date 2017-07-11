#include <set>
#include <string>
#include <vector>

class Matching
{
public:
  std::vector<std::string> findMatch(std::vector<std::string> first,
      std::vector<std::string> second);
};

std::vector<std::string> Matching::findMatch(std::vector<std::string> first,
    std::vector<std::string> second)
{
  std::set<std::string> card_symbols { "CIRCLE", "SQUIGGLE", "DIAMOND" };
  std::set<std::string> card_colors { "RED", "BLUE", "GREEN" };
  std::set<std::string> card_fills { "SOLID", "STRIPED", "EMPTY" };
  std::set<std::string> card_symbols_occurrences { "ONE", "TWO", "THREE" };
  std::vector<std::set<std::string>> card_characteristics {
    card_symbols, card_colors, card_fills, card_symbols_occurrences
  };

  std::vector<std::string> third;

  for (int i = 0; i < first.size(); i++) {
    if (first[i] == second[i]) {
      third.push_back(first[i]);
    } else {
      std::set<std::string>::iterator sit = card_characteristics[i].find(first[i]);
      card_characteristics[i].erase(sit);

      sit = card_characteristics[i].find(second[i]);
      card_characteristics[i].erase(sit);

      sit = card_characteristics[i].begin();
      third.push_back(*sit);
    }
  }

  return third;
}
