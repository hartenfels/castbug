PHP_ARG_ENABLE(castbug, enable castbug extension,
[ --enable-castbug Enable castbug extension])

if test "$PHP_CASTBUG" != "no"; then
    AC_DEFINE(HAVE_CASTBUG, 1, [Whether you have Castbug])
    PHP_NEW_EXTENSION(castbug, castbug.c, $ext_shared)
fi
