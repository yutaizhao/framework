
#ifndef ALIEN_REFSEMANTIC_EXPORT_H
#define ALIEN_REFSEMANTIC_EXPORT_H

#ifdef Alien_BUILT_AS_STATIC
#  define ALIEN_REFSEMANTIC_EXPORT
#  define ALIEN_SEMANTIC_REF_NO_EXPORT
#else
#  ifndef ALIEN_REFSEMANTIC_EXPORT
#    ifdef alien_semantic_ref_EXPORTS
        /* We are building this library */
#      define ALIEN_REFSEMANTIC_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ALIEN_REFSEMANTIC_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ALIEN_SEMANTIC_REF_NO_EXPORT
#    define ALIEN_SEMANTIC_REF_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ALIEN_SEMANTIC_REF_DEPRECATED
#  define ALIEN_SEMANTIC_REF_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ALIEN_SEMANTIC_REF_DEPRECATED_EXPORT
#  define ALIEN_SEMANTIC_REF_DEPRECATED_EXPORT ALIEN_REFSEMANTIC_EXPORT ALIEN_SEMANTIC_REF_DEPRECATED
#endif

#ifndef ALIEN_SEMANTIC_REF_DEPRECATED_NO_EXPORT
#  define ALIEN_SEMANTIC_REF_DEPRECATED_NO_EXPORT ALIEN_SEMANTIC_REF_NO_EXPORT ALIEN_SEMANTIC_REF_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ALIEN_SEMANTIC_REF_NO_DEPRECATED
#    define ALIEN_SEMANTIC_REF_NO_DEPRECATED
#  endif
#endif

#endif /* ALIEN_REFSEMANTIC_EXPORT_H */
