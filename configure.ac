#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([rcp], [0.0.1], [hguo1@nantian.com.cn])
AM_INIT_AUTOMAKE([-Wall foreign])
AM_PROG_AR
LT_INIT
AC_CONFIG_SRCDIR([include/rcp.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([
 		 Makefile
		 doc/Makefile
		 etc/Makefile
		 etc/tradeapi/Makefile
		 include/Makefile
		 include/tradeapi/Makefile
		 src/Makefile
		 src/EchoRunner/Makefile
		 src/EchoStrategy/Makefile
		 src/MarketProxy/Makefile
		 src/rcp/Makefile
		 src/rcpApi/Makefile
		 src/strategy1/Makefile
		 src/StrategyRunner/Makefile
		 src/StrategyServer/Makefile
		 src/units/Makefile
		 bin/Makefile
		 lib/Makefile
		 third/Makefile
		 ])
AC_OUTPUT
