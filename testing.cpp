#include "mp3player.h"

int main(void)
{
    mp3player_t player;
    player.LoadMp3FromFile(TEXT("sample.mp3"));
    player.PlayAndWait();
    return 0;
}
