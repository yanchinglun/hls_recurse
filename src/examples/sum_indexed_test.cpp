#include "examples/sum_indexed.hpp"

#include <stdlib.h>

using namespace hls_recurse;

int main()
{
    if(!test_sum_indexed(r_sum_indexed)){
        fprintf(stderr, "STRASSEN/recursive failed.\n");
    }

    if(!test_sum_indexed(f_sum_indexed)){
        fprintf(stderr, "SUM_INDEXED/state failed.\n");
    }

    if(!test_sum_indexed(f2_sum_indexed)){
        fprintf(stderr, "SUM_INDEXED/state2 failed.\n");
    }

    return 0;
};