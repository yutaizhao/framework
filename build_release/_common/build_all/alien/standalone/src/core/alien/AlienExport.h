
#ifndef ALIEN_EXPORT_H
#define ALIEN_EXPORT_H

#ifdef ALIEN_CORE_STATIC_DEFINE
#  define ALIEN_EXPORT
#  define ALIEN_CORE_NO_EXPORT
#else
#  ifndef ALIEN_EXPORT
#    ifdef alien_core_EXPORTS
        /* We are building this library */
#      define ALIEN_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ALIEN_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ALIEN_CORE_NO_EXPORT
#    define ALIEN_CORE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ALIEN_CORE_DEPRECATED
#  define ALIEN_CORE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ALIEN_CORE_DEPRECATED_EXPORT
#  define ALIEN_CORE_DEPRECATED_EXPORT ALIEN_EXPORT ALIEN_CORE_DEPRECATED
#endif

#ifndef ALIEN_CORE_DEPRECATED_NO_EXPORT
#  define ALIEN_CORE_DEPRECATED_NO_EXPORT ALIEN_CORE_NO_EXPORT ALIEN_CORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ALIEN_CORE_NO_DEPRECATED
#    define ALIEN_CORE_NO_DEPRECATED
#  endif
#endif

#endif /* ALIEN_EXPORT_H */
