#include "input_args.hpp"

int main(int argc, char** argv) {
    Input input{};
    if (!read_args(input, argc, argv)) {
        return -1;
    }

    return 0;
}
