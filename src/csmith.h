#pragma once
#if HAVE_CONFIG_H
#  include <config.h>
#endif

#ifdef WIN32
#pragma warning(disable : 4786)   /* Disable annoying warning messages */
#endif

#include <ostream>
#include <fstream>
#include <cstring>
#include <cstdio>

#include "Common.h"

#include "CGOptions.h"
#include "AbsProgramGenerator.h"

#include "git_version.h"
#include "platform.h"
#include "random.h"

using namespace std;

//#define PACKAGE_STRING "csmith 1.1.1"
///////////////////////////////////////////////////////////////////////////////

// ----------------------------------------------------------------------------
// Globals

// Program seed - allow user to regenerate the same program on different
// platforms.
static unsigned long g_Seed = 0;

// ----------------------------------------------------------------------------
static void
print_version(void);

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
bool parse_string_arg(const char *arg, string &s);
static bool
parse_int_arg(char *arg, unsigned long *ret);

static void print_help();
void arg_check(int argc, int i);

extern "C" {
int gen_csmith(int argc, char **argv);
}