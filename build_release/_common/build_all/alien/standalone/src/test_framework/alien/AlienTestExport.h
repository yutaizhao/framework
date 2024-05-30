
#ifndef ALIEN_TEST_FRAMEWORK_EXPORT_H
#define ALIEN_TEST_FRAMEWORK_EXPORT_H

#ifdef ALIEN_TEST_FRAMEWORK_STATIC_DEFINE
#  define ALIEN_TEST_FRAMEWORK_EXPORT
#  define ALIEN_TEST_FRAMEWORK_NO_EXPORT
#else
#  ifndef ALIEN_TEST_FRAMEWORK_EXPORT
#    ifdef alien_test_framework_EXPORTS
        /* We are building this library */
#      define ALIEN_TEST_FRAMEWORK_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ALIEN_TEST_FRAMEWORK_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ALIEN_TEST_FRAMEWORK_NO_EXPORT
#    define ALIEN_TEST_FRAMEWORK_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ALIEN_TEST_FRAMEWORK_DEPRECATED
#  define ALIEN_TEST_FRAMEWORK_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ALIEN_TEST_FRAMEWORK_DEPRECATED_EXPORT
#  define ALIEN_TEST_FRAMEWORK_DEPRECATED_EXPORT ALIEN_TEST_FRAMEWORK_EXPORT ALIEN_TEST_FRAMEWORK_DEPRECATED
#endif

#ifndef ALIEN_TEST_FRAMEWORK_DEPRECATED_NO_EXPORT
#  define ALIEN_TEST_FRAMEWORK_DEPRECATED_NO_EXPORT ALIEN_TEST_FRAMEWORK_NO_EXPORT ALIEN_TEST_FRAMEWORK_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ALIEN_TEST_FRAMEWORK_NO_DEPRECATED
#    define ALIEN_TEST_FRAMEWORK_NO_DEPRECATED
#  endif
#endif

#endif /* ALIEN_TEST_FRAMEWORK_EXPORT_H */
