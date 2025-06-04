#include "Visualize.hpp"

extern "C"
{

void SDLCALL Visualize(void *data, Uint8* stream, int len)
{
    Uint8* val = (Uint8*) data;

    *val = 0;
    int in = 0;
    for( int i = 0; i < len; i++ )
    {
        in += stream[i];
    }

    *val = in / len;
}

}
