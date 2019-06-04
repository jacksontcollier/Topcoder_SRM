#include <algorithm>
#include <set>
#include <vector>

class WildSequence
{
public:
    std::vector<int> construct(int head, std::vector<int> rest);
private:
    bool sequence_is_wild(std::vector<int>& seq);
};

std::vector<int> WildSequence::construct(int head, std::vector<int> rest)
{
    std::set<int>::iterator sit;

    for (int i = 0; i < 2; i++) {
        std::vector<int> seq;
        seq.push_back(head);
        std::set<int> trest(rest.begin(), rest.end());
        bool get_max = (i == 0);
        while (trest.size()) {
            if (get_max) {
                sit = std::max_element(trest.begin(), trest.end());
                if (*sit > seq[seq.size()-1]) {
                    seq.push_back(*sit);
                    trest.erase(sit);
                }
            } else {
                sit = std::min_element(trest.begin(), trest.end());
                if (*sit < seq[seq.size()-1]) {
                    seq.push_back(*sit);
                    trest.erase(sit);
                }
            }
            get_max = !get_max;
        }

        if (sequence_is_wild(seq)) {
            return seq;
        }
    }

    return std::vector<int>();
}

bool WildSequence::sequence_is_wild(std::vector<int>& seq)
{
    bool is_wild = true;
    
    for (size_t i = 2; i < seq.size(); i++) {
        if ((seq[i] - seq[i-1] < 0) && (seq[i-1] - seq[i-2] < 0)) {
            is_wild = false;
            break;
        } else if ((seq[i] - seq[i-1] > 0) && (seq[i-1] - seq[i-2] > 0)) {
            is_wild = false;
            break;
        }
    }

    return is_wild;
}

