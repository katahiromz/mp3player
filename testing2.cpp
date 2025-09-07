#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

int main(void)
{
    int result;
    result = mciSendString(TEXT("open \".\\sample.mp3\" type mpegvideo alias myaudio"), NULL, 0, 0);
    printf("result: %d\n", result);
    result = mciSendString(TEXT("play myaudio wait"), NULL, 0, 0);
    printf("result: %d\n", result);
    result = mciSendString(TEXT("close myaudio"), NULL, 0, 0);
    printf("result: %d\n", result);
    return 0;
}
