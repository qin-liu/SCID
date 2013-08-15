#ifndef _TRANSFER_H_
#define _TRANSFER_H_
#include "malloc.h"

#ifdef UNICODE
#define tcharToUtf8  unicodeToUtf8
#define Utf8Totchar  utf8ToUnicode
#else
#define tcharToUtf8 mbcsToUtf8
#define Utf8Totchar utf8ToMbcs
#endif

//×Ö·û×ª»»º¯Êý
inline char *unicodeToUtf8(const WCHAR *zWideFilename)
{
	int nByte;
	char *zFilename;
	nByte = WideCharToMultiByte(CP_UTF8, 0, zWideFilename, -1, 0, 0, 0, 0);
	zFilename = (char*)malloc(nByte + 1);
	if(zFilename == 0)
		return 0;
	nByte = WideCharToMultiByte(CP_UTF8, 0, zWideFilename, -1, zFilename, nByte + 1, 0, 0);
	if(nByte == 0)
	{
		free(zFilename);
		zFilename = 0;
	}
	return zFilename;
}

inline static WCHAR *utf8ToUnicode(const char *zFilename)
{
	int nChar;
	WCHAR *zWideFilename;
	nChar = MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, NULL, 0);
	zWideFilename = (WCHAR*)malloc( nChar*sizeof(zWideFilename[0]) );
	if( zWideFilename==0 )
		return 0;
	nChar = MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, zWideFilename, nChar);
	if( nChar==0)
	{
		free(zWideFilename);
		zWideFilename = 0;
	}
	return zWideFilename;
}

inline WCHAR *mbcsToUnicode(const char *zFilename)
{
	int nByte;
	WCHAR *zMbcsFilename;
	int codepage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;

	nByte = MultiByteToWideChar(codepage, 0, zFilename, -1, NULL,0)*sizeof(WCHAR);
	zMbcsFilename = (WCHAR*)malloc(nByte*sizeof(zMbcsFilename[0]));
	if(zMbcsFilename == 0)
		return 0;
	nByte = MultiByteToWideChar(codepage, 0, zFilename, -1, zMbcsFilename, nByte);
	if(nByte == 0)
	{
		free(zMbcsFilename);
		zMbcsFilename = 0;
	}
	return zMbcsFilename;
}

inline static char *unicodeToMbcs(const WCHAR *zWideFilename)
{
	int nByte;
	char *zFilename;
	int codepage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;

	nByte = WideCharToMultiByte(codepage, 0, zWideFilename, -1, 0, 0, 0, 0);
	zFilename = (char*)malloc( nByte );
	if( zFilename==0 )
		return 0;
	nByte = WideCharToMultiByte(codepage, 0, zWideFilename, -1, zFilename, nByte,0, 0);
	if( nByte == 0 )
	{
		free(zFilename);
		zFilename = 0;
	}
	return zFilename;
}

inline char* utf8ToMbcs(const char *zFilename)
{
	char *zFilenameMbcs;
	WCHAR *zTmpWide;
	zTmpWide = utf8ToUnicode(zFilename);
	if(zTmpWide == 0)
		return 0;
	zFilenameMbcs = unicodeToMbcs(zTmpWide);
	free(zTmpWide);
	return zFilenameMbcs;
}

inline char *mbcsToUtf8(const char *zFilename)
{
	char *zFilenameUtf8;
	WCHAR *zTmpWide;
	
	zTmpWide = mbcsToUnicode(zFilename);
	if(zTmpWide==0)
		return 0;
	zFilenameUtf8 = unicodeToUtf8(zTmpWide);
	free(zTmpWide);
	return zFilenameUtf8;
}

inline void FreeStr(char* pStrBuf)
{
	if (pStrBuf)
	{
		free(pStrBuf);
	}
}
	
#endif