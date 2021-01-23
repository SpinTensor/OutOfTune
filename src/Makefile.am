bin_PROGRAMS = outoftune

noinst_LTLIBRARIES = libfrac.la \
		     libcmd_opt.la

outoftune_SOURCES = outoftune.c
outoftune_CFLAGS = -O3
outoftune_LDFLAGS =
outoftune_LDADD = libfrac.la \
		  libcmd_opt.la

libfrac_la_SOURCES = gcd.c \
		     lcm.c \
		     int_pow.c \
		     fractions.c
libfrac_la_CFLAGS = -O3

libcmd_opt_la_SOURCES = cmd_options.c
libcmd_opt_la_CFLAGS = -O3
