///////////////////////////////////////////////////////////////////////////////
///
/// Written 2009, Oliver Schneider (assarbad.net) - PUBLIC DOMAIN/CC0
///
/// Defines for the version information in the resource file
///
///////////////////////////////////////////////////////////////////////////////
#ifndef __EXEVERSION_H_VERSION__
#define __EXEVERSION_H_VERSION__ 2012121901

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
#define EXE_YEAR               2003-2005 // current year or timespan (e.g. 2003-2007)
#define TEXT_WEBSITE           http:/##/www.daemonology.net/bsdiff/ // website
#define TEXT_PRODUCTNAME       bsdiff // product's name
#define TEXT_FILEDESC          Binary differ // component description
#define TEXT_COMPANY           Oliver Schneider (assarbad.net) // company
#define TEXT_MODULE            bsdiff // module name
#define TEXT_COPYRIGHT         Copyright EXE_YEAR TEXT_COMPANY // copyright information
#define TEXT_INTERNALNAME      bsdiff.exe // copyright information

#endif // __EXEVERSION_H_VERSION__
