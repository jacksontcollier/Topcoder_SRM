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

private:
  std::vector<int> FormComplement(std::vector<int>& component_values);
  std::vector<int> FormAlternateComplement(std::vector<int>& component_values);
  bool ShouldFormAlternateComplement(std::vector<int>& component_values);
};

std::vector<int> RGBColor::getComplement(std::vector<int> rgb)
{
  if (ShouldFormAlternateComplement(rgb)) {
    return FormAlternateComplement(rgb);
  }

  return FormComplement(rgb);
}

std::vector<int> RGBColor::FormComplement(std::vector<int>& component_values)
{
  std::vector<int> complement;

  for (auto component = component_values.begin(); component != component_values.end();
      component++) {
    complement.push_back(MAX_COLOR_VALUE - *component);
  }

  return complement;
}

std::vector<int> RGBColor::FormAlternateComplement(std::vector<int>& component_values)
{
  std::vector<int> alternate_complement;

  for (auto component = component_values.begin(); component != component_values.end();
      component++) {
    alternate_complement.push_back(*component >= MEDIAN_COLOR_VALUE ?
        *component - MEDIAN_COLOR_VALUE : *component + MEDIAN_COLOR_VALUE);
  }

  return alternate_complement;
}

bool RGBColor::ShouldFormAlternateComplement(std::vector<int>& component_values)
{
  for (auto component = component_values.begin(); component != component_values.end();
      component++) {
    if (std::abs(*component - (MAX_COLOR_VALUE - *component)) > MIN_DISTINGUISH_RANGE) {
      return false;
    }
  }

  return true;
}
