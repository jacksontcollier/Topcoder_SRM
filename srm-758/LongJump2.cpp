#include <string>
#include <vector>
class LongJump2
{
public:
    int countNewLeaders(int N, std::vector<int> jumpLengths);
};

int LongJump2::countNewLeaders(int N, std::vector<int> jumpLengths)
{
    int leader_count = 0;
    int current_leader_length = -1;
    int current_leader_index = -1;
    int leader_index = 0;

    for (size_t i = 0; i < jumpLengths.size(); i++) {
        leader_index = i % N;
        if (jumpLengths[i] > current_leader_length) {
            current_leader_length = jumpLengths[i];
            if (current_leader_index != leader_index) {
                current_leader_index = leader_index;
                leader_count++;
            }
        }
    }

    return leader_count;
}
