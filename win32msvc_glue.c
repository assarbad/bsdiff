/*-
 * Copyright 2012 Oliver Schneider
 * All rights reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted providing that the following conditions 
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <Windows.h>
#include <tchar.h>
#include <io.h>
#include <stdarg.h>

static off_t ftello(FILE *stream)
{
    return (off_t)_ftelli64(stream);
}

static int fseeko(FILE *stream, off_t offset, int whence)
{
    return _fseeki64(stream, offset, whence);
}

static const _TCHAR* get_program_name()
{
    return _T("bsdiff"); /* faking it for now */
}

#ifdef _UNICODE
/* We use wchar_t here to force warnings if whoever changes this(including the
   future me) attempts something silly ;) */
static wchar_t* get_tchar_from_char(const char* fmt)
{
    if(fmt)
    {
        size_t i;
        size_t const len = strlen(fmt);
        wchar_t* wfmt = calloc(len + 1, sizeof(wchar_t));

        if(!wfmt)
            return NULL;

        for(i = 0; i < len; i++)
        {
            /* That's right, we ass-u-me that the original string is always
               ASCII or EASCII and will get bitten by changes that don't adhere
               to this assumption. */
            wfmt[i] = (wchar_t)fmt[i];
        }
        return wfmt;
    }
    return NULL;
}

#define open _topen
/* Own concoction to handle this special case in the least intrusive manner. */
#define fopen win32bsdiff_fopen

static FILE* win32bsdiff_fopen(const wchar_t *filename, const char* mode)
{
    _TCHAR* tmode = get_tchar_from_char(mode);
    if(tmode)
    {
        FILE* retval = _tfopen(filename, tmode);
        free(tmode);
        return retval;
    }
    return NULL;
}
#else
#   define get_tchar_from_char(x) x
#endif // _UNICODE

static void wrap_err_T(int x, int eval, const char *fmt, ...)
{
    const int local_errno = errno; // TODO: _doserrno
    const _TCHAR* progname = get_program_name();
    _TCHAR* tfmt = get_tchar_from_char(fmt);

    (void)_ftprintf(stderr, _T("%s: "), progname);
    if (fmt != NULL)
    {
        va_list ap;

        va_start(ap, fmt);
        (void)_vftprintf(stderr, tfmt, ap);
        va_end(ap);
    }
    if(!x)
        (void)_ftprintf(stderr, _T(": %s\n"), _tcserror(local_errno));
    else
        (void)_ftprintf(stderr, _T("\n"));
    if(fmt != (const char*)tfmt)
    {
        free(tfmt);
    }
    exit(eval);
}
#define err(eval, fmt, ...) wrap_err_T(0, eval, fmt, __VA_ARGS__)
#define errx(eval, fmt, ...) wrap_err_T(1, eval, fmt, __VA_ARGS__)

#pragma warning(disable: 4244) // possible loss of data inside offtout()
