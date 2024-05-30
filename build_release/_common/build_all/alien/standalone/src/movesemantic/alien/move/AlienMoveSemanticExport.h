
#ifndef ALIEN_MOVESEMANTIC_EXPORT_H
#define ALIEN_MOVESEMANTIC_EXPORT_H

#ifdef Alien_BUILT_AS_STATIC
#  define ALIEN_MOVESEMANTIC_EXPORT
#  define ALIEN_SEMANTIC_MOVE_NO_EXPORT
#else
#  ifndef ALIEN_MOVESEMANTIC_EXPORT
#    ifdef alien_semantic_move_EXPORTS
        /* We are building this library */
#      define ALIEN_MOVESEMANTIC_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ALIEN_MOVESEMANTIC_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ALIEN_SEMANTIC_MOVE_NO_EXPORT
#    define ALIEN_SEMANTIC_MOVE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ALIEN_SEMANTIC_MOVE_DEPRECATED
#  define ALIEN_SEMANTIC_MOVE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ALIEN_SEMANTIC_MOVE_DEPRECATED_EXPORT
#  define ALIEN_SEMANTIC_MOVE_DEPRECATED_EXPORT ALIEN_MOVESEMANTIC_EXPORT ALIEN_SEMANTIC_MOVE_DEPRECATED
#endif

#ifndef ALIEN_SEMANTIC_MOVE_DEPRECATED_NO_EXPORT
#  define ALIEN_SEMANTIC_MOVE_DEPRECATED_NO_EXPORT ALIEN_SEMANTIC_MOVE_NO_EXPORT ALIEN_SEMANTIC_MOVE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ALIEN_SEMANTIC_MOVE_NO_DEPRECATED
#    define ALIEN_SEMANTIC_MOVE_NO_DEPRECATED
#  endif
#endif

#endif /* ALIEN_MOVESEMANTIC_EXPORT_H */
