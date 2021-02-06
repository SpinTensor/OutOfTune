bin_PROGRAMS = outoftune

noinst_LTLIBRARIES = librandom.la \
		     libperm.la \
		     libcmd_opt.la \
		     libinterval.la \
		     libsequence.la

outoftune_SOURCES = outoftune.c
outoftune_CFLAGS = -O3
outoftune_LDFLAGS = -lm
outoftune_LDADD = libsequence.la \
		  libinterval.la \
		  libperm.la \
		  librandom.la \
		  libcmd_opt.la

librandom_la_SOURCES = random.c
librandom_la_CFLAGS = -O3

libperm_la_SOURCES = permutations.c \
		     in_list.c
libperm_la_CFLAGS = -O3

libcmd_opt_la_SOURCES = cmd_options.c
libcmd_opt_la_CFLAGS = -O3

libinterval_la_SOURCES = intervals.c \
			 interval_list_properties.c
libinterval_la_CFLAGS = -O3

libsequence_la_SOURCES = sequences.c \
			 sequence_properties.c \
			 opt_sequence.c
libsequence_la_CFLAGS = -O3
