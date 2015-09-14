#ifndef utility_hpp
#define utility_hpp

#include <assert.h>

#if defined(__GNUC__) || defined(__clang__)
#define HLS_INLINE_STEP inline __attribute__((always_inline))
#define HLS_NO_RETURN __attribute__((noreturn))

#else
#define HLS_INLINE_STEP inline 
#define HLS_NO_RETURN 
#endif

#include <time.h>

namespace hls_recurse
{
    
/*! Used in situations where it is a fundamental error if the
    function ever gets called. In debug builds will assert,
    in release builds will try to indicate to the optimiser
    that the code can't be reached
*/
HLS_INLINE_STEP HLS_NO_RETURN logic_error_if_reachable() 
{
    assert(0);
#if defined(__GNUC__) || defined(__clang__)
    __builtin_unreachable();
#else
    // Scream "UB!" at the compiler
    int x=5/0;
    *(static_cast<int*>(0)) = 0;
#endif
}

uint64_t time_now()
{
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return uint64_t(tp.tv_sec)*1000000000 + tp.tv_nsec;
}

double time_delta(uint64_t begin, uint64_t end)
{
    int64_t diff=end-begin;
    
    return diff*1e-9;
}

}; // hls_recurse

#endif