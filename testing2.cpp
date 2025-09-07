#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

int main(void)
{
    int result;
    result = mciSendString(TEXT("open sample.mp3 type mpegvideo"), NULL, 0, 0);
    printf("result: %d\n", result);
    result = mciSendString(TEXT("play sample.mp3 wait"), NULL, 0, 0);
    printf("result: %d\n", result);
    result = mciSendString(TEXT("close sample.mp3"), NULL, 0, 0);
    printf("result: %d\n", result);
    return 0;
}
