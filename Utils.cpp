#include "Utils.hpp"
#include <cmath>

QString ToString(int nbr)
{
    if( nbr == 0 )
    {
        return "00";
    }

    QString out = "";

    int in = abs( nbr );

    while( in != 0 )
    {
        int u = in % 10;

        switch ( u ) {
        case 0:
            out = QString( "0" ) + out;
            break;
        case 1:
            out = QString( "1" ) + out;
            break;
        case 2:
            out = QString( "2" ) + out;
            break;
        case 3:
            out = QString( "3" ) + out;
            break;
        case 4:
            out = QString( "4" ) + out;
            break;
        case 5:
            out = QString( "5" ) + out;
            break;
        case 6:
            out = QString( "6" ) + out;
            break;
        case 7:
            out = QString( "7" ) + out;
            break;
        case 8:
            out = QString( "8" ) + out;
            break;
        default:
            out = QString( "9" ) + out;
            break;
        }

        in -= u;
        in /= 10;
    }

    if( nbr < 0 )
    {
        return QString( "-" ) + out;
    }
    else
    {
        return out;
    }
}
