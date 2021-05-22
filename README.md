# OutOfTune

## About

OutOfTune is a program to search for specific sequences of musical notes in the just intonated system in order to find discrepancies between the notation in half steps and the real physical frequencies of the notes (e.g. Syntonic comma pump: https://en.wikipedia.org/wiki/Syntonic_comma#Comma_pump)

## Usage

```bash
   ./outoftune --help
```
gives an overview over all command line options and their function.

## Download

You can clone the current version of OutOfTune from github:
```bash
   git clone https://github.com/SpinTensor/OutOfTune.git
```

## Prereqisites & Installation

OutOfTune requires  the gmp library (https://gmplib.org/) for the fractional arithmetic.
OutOfTune utilizes GNU autotools for easy installation.
```bash
   autoreconf -i
   ./configure --prefix=<installpath> --with-gmp-inc=<libgmp_include_path> --with-gmp-lib=<libgmp_library_path>
   make
   make install
```
