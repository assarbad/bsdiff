///////////////////////////////////////////////////////////////////////////////
///
/// Written 2009, Oliver Schneider (assarbad.net) - PUBLIC DOMAIN/CC0
///
/// Defines for the version information in the resource file
///
///////////////////////////////////////////////////////////////////////////////
#ifndef __EXEVERSION_H_VERSION__
#define __EXEVERSION_H_VERSION__ 2012121904

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "buildnumber.h"

// ---------------------------------------------------------------------------
// Several defines have to be given before including this file. These are:
// ---------------------------------------------------------------------------
#define TEXT_AUTHOR            Colin Percival // author (optional value)
#define PRD_MAJVER             4 // major product version
#define PRD_MINVER             3 // minor product version
#define PRD_BUILD              0 // build number for product
#define FILE_MAJVER            4 // major file version
#define FILE_MINVER            3 // minor file version
#define FILE_BUILD             _FILE_VERSION_BUILD // build number
#define TEXT_WEBSITE           http:/##/www.daemonology.net/bsdiff/ // website
#define TEXT_PRODUCTNAME       PROJNAME // product's name
#define TEXT_FILEDESC          Binary delta algorithm bsdiff/bspatch, originally written for FreeBSD, ported to Win32 (Unicode) // component description
#define TEXT_COMPANY           Oliver Schneider (assarbad.net) // company
#define TEXT_MODULE            PROJNAME // module name
#define TEXT_COPYRIGHT         Copyright 2003-2005 Colin Percival, Portions Copyright 1996-2010 Julian R Seward [bzip2], 2012 Oliver Schneider [bsdiff Win32 port] // copyright information
#define TEXT_INTERNALNAME      PROJNAME##.exe // copyright information

#endif // __EXEVERSION_H_VERSION__
