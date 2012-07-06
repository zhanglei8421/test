//---------------------------------------------------------------------------

//2012-7-6
#pragma hdrstop

#include "ver.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

int GetVersion(WORD &v1, WORD &v2, WORD &v3, WORD &v4)
{
    char t[512];
    GetModuleFileName(NULL, t, 512);
    if(GetFileVersionInfo(t, 0, 512, t))
    {
        VS_FIXEDFILEINFO *pFileInfo;
        UINT n = 0;
        VerQueryValue(t, (LPTSTR)("\\"), (void**)&pFileInfo, &n);
        v1 = HIWORD(pFileInfo->dwFileVersionMS);
        v2 = LOWORD(pFileInfo->dwFileVersionMS),
        v3 = HIWORD(pFileInfo->dwFileVersionLS);
        v4 = LOWORD(pFileInfo->dwFileVersionLS);
        return 0;
    }
    return -1;
}