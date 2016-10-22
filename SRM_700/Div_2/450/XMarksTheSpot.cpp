#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

class XMarksTheSpot
{
public:
  int countArea(std::vector <std::string> board);
};

int XMarksTheSpot::countArea(std::vector <std::string> board)
{
  size_t T = -1;
  size_t B = -1;
  size_t L = -1;
  size_t R = -1;
  std::vector< std::pair<size_t, size_t> > q_locations;
  unsigned long long num_treasure_squares = 0;
  
  // Get extremum landmarks: topmost, bottommost, rightmost, leftmost
  // Store location of question marks in q_locations
  for (size_t i = 0; i < board.size(); i++) {
    for (size_t j = 0; j < board[i].size(); j++) {
      if (board[i][j] == 'O') {
        if (T == -1 || i < T) T = i;
        if (B == -1 || i > B) B = i;
        if (L == -1 || j < L) L = j;
        if (R == -1 || j > R) R = j;
      }
      if (board[i][j] == '?') q_locations.push_back(std::make_pair(i, j));
    }
  }

  // Bit-shift enumerate all possible q combinations. 0 = '.', 1 = '?'
  long double num_combinations_float = pow((long double) 2,
      (long double) q_locations.size());
  
  long num_combinations = (long) num_combinations_float;

  // Bit-shift enumerate all possible q combinations. 0 = '.', 1 = '?'
  for (long i = 0; i < num_combinations; i++) {
    size_t max_t = T;
    size_t max_b = B;
    size_t max_l = L;
    size_t max_r = R;
    size_t q_entry = 0;
    // Compute area for each possibility
    for (long j = i; j > 0; j = j >> 1) {
      if (j & 1) {
        max_t = std::min(q_locations[q_entry].first, max_t);
        max_b = std::max(q_locations[q_entry].first, max_b);
        max_l = std::min(q_locations[q_entry].second, max_l);
        max_r = std::max(q_locations[q_entry].second, max_r);
      }
      q_entry++;
    }
    num_treasure_squares += ((max_b - max_t) + 1) * ((max_r - max_l) + 1);
  }

  return num_treasure_squares;
}
