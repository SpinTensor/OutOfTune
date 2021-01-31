# ===========================================================================
#      https://www.gnu.org/software/autoconf-archive/ax_prog_cc_mpi.html
# ===========================================================================
#
# SYNOPSIS
#
#   AX_GMP_LIBRARY
#
# DESCRIPTION
#
#   This macro checks if the gmp library is properly included
#

AC_DEFUN([AX_GMP_LIBRARY], [
   AC_LANG(C)
   AC_PREREQ(2.50)
   AC_ARG_WITH([gmp_inc],
               [AC_HELP_STRING([--with-gmp-inc=DIR],
                               [gmp include directory])],
               [CFLAGS="-I${withval} ${CFLAGS}"])
   AC_ARG_WITH([gmp_lib],
               [AC_HELP_STRING([--with-gmp-lib=DIR],
                               [gmp lib directory])],
               [LDFLAGS="-L$withval -lgmp $LDFLAGS"])
   AC_CHECK_LIB([gmp],
       [__gmpz_init], ,
       [AC_MSG_FAILURE([unable to find gmp library])])
   AC_CHECK_HEADER([gmp.h], ,
          [AC_MSG_FAILURE([unable to find gmp headers])])
])
