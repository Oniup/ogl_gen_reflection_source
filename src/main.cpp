#include "input_args.hpp"
#include <iostream>

int main(int argc, char** argv) {
    Input input{};
    if (!read_args(input, argc, argv)) {
        return -1;
    }

    SourceDestination sources{};
    if (!get_source_locations(sources, input)) {
        return -1;
    }

    return 0;
}
