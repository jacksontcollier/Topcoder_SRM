#include <algorithm>
#include <cmath>
#include <vector>

const int MAX_COLOR_VALUE = 255;
const int MIN_DISTINGUISH_RANGE = 32;
const int MEDIAN_COLOR_VALUE = 128;

class RGBColor
{
public:
  std::vector<int> getComplement(std::vector<int> rgb);
};

std::vector<int> RGBColor::getComplement(std::vector<int> rgb)
{
  bool should_form_alternate_complement = true;
  std::vector<int> complement;

  for (int i = 0; i < rgb.size(); i++) {
    int component_complement = MAX_COLOR_VALUE - rgb[i];
    if (component_complement > MIN_DISTINGUISH_RANGE) {
      should_form_alternate_complement = false;
    }
    complement.push_back(component_complement);
  }

  if (should_form_alternate_complement) {
    for (int i = 0; i < complement.size(); i++) {
      complement[i] = std::max(rgb[i] - MEDIAN_COLOR_VALUE, rgb[i] + MEDIAN_COLOR_VALUE);
    }
  }

  return complement;
}
