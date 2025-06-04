#include "SoundPlayer.hpp"
#include <QMessageBox>
#include <QApplication>

#include "Window.hpp"
#include "ui_Window.h"

#include "Utils.hpp"
#include <SDL3/SDL_stdinc.h>
#include "Visualize.hpp"

Uint32 flags = MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_MID;

SoundPlayer::SoundPlayer(QObject *parent) :
    QObject(parent),
    timer( 0 ),
    state( PlayState_Stopped ),
    mode( PlayMode_Sequential ),
    val( 0 ),
    music( 0 ),
    t( 0 ),
    idx( -1 )
{
    if( !SDL_InitSubSystem( SDL_INIT_AUDIO ) || !( Mix_Init( flags ) & MIX_INIT_MP3 ) )
    {
        QMessageBox::critical(
                qobject_cast<QWidget*>( parent ),
                tr( "Erreur fatale" ),
                tr( "Echec de l'initialisation audio :\n" ) + SDL_GetError()
            );
        //exit( EXIT_FAILURE );
    }

    int dc = 0, i = 0;
    SDL_AudioDeviceID* ids = SDL_GetAudioPlaybackDevices( &dc );
    SDL_AudioSpec spec;
    spec.channels = MIX_DEFAULT_CHANNELS;
    spec.format = MIX_DEFAULT_FORMAT;
    spec.freq = MIX_DEFAULT_FREQUENCY;
    /*if( !Mix_QuerySpec( &spec.freq, &spec.format, &spec.channels ) )
    {
        spec.channels = MIX_DEFAULT_CHANNELS;
        spec.format = MIX_DEFAULT_FORMAT;
        spec.freq = MIX_DEFAULT_FREQUENCY;
    }*/
    for( i = 0; i < dc; i++ )
    {
        if( Mix_OpenAudio( ids[i], &spec) )
        {
            break;
        }
    }

    if( i == dc )
    {
        QMessageBox::critical(
                qobject_cast<QWidget*>( parent ),
                tr( "Erreur fatale" ),
                tr( "Echec de l'initialisation du périphérique audio :\n" ) + SDL_GetError()
            );
        exit( EXIT_FAILURE );
    }

    Mix_SetPostMix( Visualize, &val );

    timer = new QTimer;
    connect( timer, SIGNAL(timeout()), this, SLOT(UpdateProgression()) );
}

SoundPlayer::~SoundPlayer()
{
    if( music )
    {
        Mix_FreeMusic( music );
    }
    delete timer;
    SDL_QuitSubSystem( SDL_INIT_AUDIO );
    Mix_CloseAudio();
    Mix_Quit();
}

PlayState SoundPlayer::GetPlayState() const
{
    return state;
}

PlayMode SoundPlayer::GetPlayMode() const
{
    return mode;
}

void SoundPlayer::UpdateProgression()
{
    Window* win = qobject_cast<Window*>( parent() );
    double dpos = Mix_GetMusicPosition( music );

    if( dpos >= t )
    {
        timer->stop();
        int ne = 0;
        switch( mode )
        {
        case PlayMode_Sequential:
            if( idx >= win->GetPlaylist().size() - 1 )
            {
                return ;
            }
            NextFile();
            win->IndexChange( idx );
            break;
        case PlayMode_Random:
            ne = SDL_rand( win->GetPlaylist().size() );
            StartWithIndex( ne );
            win->IndexChange( idx );
            break;
        case PlayMode_Loop:
            if( idx >= win->GetPlaylist().size() - 1 )
            {
                StartWithIndex( 0 );
            }
            win->IndexChange( idx );
            break;
        default:
            StartWithIndex( idx );
            win->IndexChange( idx );
            break;
        }
        return ;
    }

    int ti = dpos;
    int m = ti / 60;
    int s = ti % 60;

    float pos = 100.0f * ( float ) ( dpos / t );

    win->GetUi()->timeline->setValue( pos );
    win->GetUi()->lcd_min->display( m );
    win->GetUi()->lcd_Sec->display( s );
    win->SetColor( val );
}

void SoundPlayer::UpdateList()
{
    //
}

void SoundPlayer::StartPlaying()
{
    StartWithIndex( 0 );
}

void SoundPlayer::StartWithIndex(int index)
{
    Window* win = qobject_cast<Window*>( parent() );

    idx = index;

    if( music != 0 )
    {
        Mix_FreeMusic( music );
    }

    music = Mix_LoadMUS( win->GetPlaylist()[idx].toLatin1().constData() );

    if( music == 0 )
    {
        QMessageBox::warning(
                win,
                tr( "Erreur" ),
                tr( "Echec du chargement du fichier :\n" ) + SDL_GetError()
            );
        return ;
    }
    t = Mix_MusicDuration( music );

    win->GetUi()->btn_PlayPause->setIcon( QIcon( ":/icons/icons/pause.png" ) );

    int t = Mix_MusicDuration( music );
    int m = t / 60;
    int s = t % 60;
    QString dur = ToString( m ) + QString( " : " ) + ToString( s );
    win->GetUi()->txt_Time->setText( dur );

    Mix_PlayMusic( music, 1 );
    state = PlayState_Playing;
    timer->start( 40 );
}

void SoundPlayer::PlayPause()
{
    if( state == PlayState_Stopped )
    {
        StartPlaying();
    }
    else if( state == PlayState_Paused )
    {
        state = PlayState_Playing;
        Mix_ResumeMusic();
        timer->start(1000);
    }
    else
    {
        state = PlayState_Paused;
        Mix_PauseMusic();
        timer->stop();
    }
}

void SoundPlayer::ChangePlayMode()
{
    switch ( mode ) {
    case PlayMode_Sequential:
        mode = PlayMode_Random;
        break;
    case PlayMode_Random:
        mode = PlayMode_Loop;
        break;
    case PlayMode_Loop:
        mode = PlayMode_Repeat;
        break;
    default:
        mode = PlayMode_Sequential;
        break;
    }

    //
}

void SoundPlayer::PreviousFile()
{
    StartWithIndex( idx - 1 );
}

void SoundPlayer::NextFile()
{
    StartWithIndex( idx + 1 );
}

void SoundPlayer::StopPlaying()
{
    timer->stop();
    state = PlayState_Stopped;
    Mix_FreeMusic( music );
}
