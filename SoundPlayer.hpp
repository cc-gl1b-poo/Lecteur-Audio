#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include<SDL3_mixer/SDL_mixer.h>

enum PlayState{
    PlayState_Playing,
    PlayState_Paused,
    PlayState_Stopped
};

enum PlayMode{
    PlayMode_Sequential,
    PlayMode_Random,
    PlayMode_Loop,
    PlayMode_Repeat
};

class SoundPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SoundPlayer(QObject *parent = 0);
    ~SoundPlayer();

    PlayState GetPlayState() const;
    PlayMode GetPlayMode() const;

    void UpdateList();

    void StartPlaying();
    void StartWithIndex( int index );

    int CurrentIndex() const
    {
        return idx;
    }

    QTimer* timer;
    
signals:
    
public slots:
    void PlayPause();
    void ChangePlayMode();
    void PreviousFile();
    void NextFile();
    void StopPlaying();

    void UpdateProgression();

private:
    PlayState state;
    PlayMode mode;
    Uint8 val;

    Mix_Music* music;
    double t;
    int idx;
};

#endif // SOUNDPLAYER_H
