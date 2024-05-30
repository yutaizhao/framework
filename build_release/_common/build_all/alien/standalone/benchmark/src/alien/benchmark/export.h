
#ifndef ALIEN_BENCHMARK_EXPORT_H
#define ALIEN_BENCHMARK_EXPORT_H

#ifdef ALIEN_BENCHMARK_STATIC_DEFINE
#  define ALIEN_BENCHMARK_EXPORT
#  define ALIEN_BENCHMARK_NO_EXPORT
#else
#  ifndef ALIEN_BENCHMARK_EXPORT
#    ifdef alien_benchmark_EXPORTS
        /* We are building this library */
#      define ALIEN_BENCHMARK_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ALIEN_BENCHMARK_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ALIEN_BENCHMARK_NO_EXPORT
#    define ALIEN_BENCHMARK_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ALIEN_BENCHMARK_DEPRECATED
#  define ALIEN_BENCHMARK_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ALIEN_BENCHMARK_DEPRECATED_EXPORT
#  define ALIEN_BENCHMARK_DEPRECATED_EXPORT ALIEN_BENCHMARK_EXPORT ALIEN_BENCHMARK_DEPRECATED
#endif

#ifndef ALIEN_BENCHMARK_DEPRECATED_NO_EXPORT
#  define ALIEN_BENCHMARK_DEPRECATED_NO_EXPORT ALIEN_BENCHMARK_NO_EXPORT ALIEN_BENCHMARK_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ALIEN_BENCHMARK_NO_DEPRECATED
#    define ALIEN_BENCHMARK_NO_DEPRECATED
#  endif
#endif

#endif /* ALIEN_BENCHMARK_EXPORT_H */
