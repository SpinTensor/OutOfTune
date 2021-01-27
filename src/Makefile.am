bin_PROGRAMS = outoftune

noinst_LTLIBRARIES = librandom.la \
		     libfrac.la \
		     libcmd_opt.la \
		     libinterval.la \
		     libsequence.la

outoftune_SOURCES = outoftune.c
outoftune_CFLAGS = -O3
outoftune_LDFLAGS =
outoftune_LDADD = libsequence.la \
		  libinterval.la \
		  libfrac.la \
		  librandom.la \
		  libcmd_opt.la

librandom_la_SOURCES = random.c
librandom_la_CFLAGS = -O3

libfrac_la_SOURCES = gcd.c \
		     lcm.c \
		     int_pow.c \
		     fractions.c
libfrac_la_CFLAGS = -O3

libcmd_opt_la_SOURCES = cmd_options.c
libcmd_opt_la_CFLAGS = -O3

libinterval_la_SOURCES = intervals.c \
			 interval_list_properties.c
libinterval_la_CFLAGS = -O3

libsequence_la_SOURCES = sequences.c \
			 sequence_properties.c
libsequence_la_CFLAGS = -O3
