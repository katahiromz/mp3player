// MFile.h --- File manipulator
// License: MIT
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <assert.h>

static inline PBYTE
MFile_GetContents(LPCTSTR pszFile, size_t *pcb)
{
    *pcb = 0;

    DWORD dwShare = FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE;
    HANDLE hFile = CreateFile(pszFile, GENERIC_READ, dwShare, NULL, OPEN_EXISTING,
                              FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        assert(0);
        return NULL;
    }

    DWORD dwSize = GetFileSize(hFile, NULL);
    if (dwSize == 0xFFFFFFFF)
    {
        assert(0);
        CloseHandle(hFile);
        return NULL;
    }

    PBYTE pb = (PBYTE)malloc(dwSize);
    if (!pb)
    {
        assert(0);
        CloseHandle(hFile);
        return NULL;
    }

    DWORD cbRead;
    if (!ReadFile(hFile, pb, dwSize, &cbRead, NULL) || cbRead != dwSize)
    {
        assert(0);
        free(pb);
        pb = NULL;
        dwSize = 0;
    }

    CloseHandle(hFile);

    *pcb = dwSize;
    return pb;
}

static inline BOOL
MFile_PutContents(LPCTSTR pszFile, LPCVOID pv, size_t cb)
{
    HANDLE hFile = CreateFile(pszFile, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS,
                              FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        assert(0);
        return NULL;
    }

    DWORD cbWritten;
    BOOL ok = WriteFile(hFile, pv, (DWORD)cb, &cbWritten, NULL) && cb == cbWritten;
    CloseHandle(hFile);

    return ok;
}
