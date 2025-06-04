#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <QGraphicsScene>
#include <SDL3/SDL.h>

#include "SoundPlayer.hpp"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();

    QStringList& GetPlaylist();

    Ui::Window* GetUi() const;

    void SetColor( Uint8 col );

    void IndexChange( int idx );

private slots:
    void PlayPause();
    void ChangePlayMode();
    void NextFile();
    void PreviousFile();
    void StopPlaying();
    void AddFile();
    void RemoveFile();
    void EmptyList();

    void PlayCurrent();

private:
    Ui::Window *ui;
    QStringListModel* model;
    SoundPlayer* player;

        // Pour le visualiseur
    QGraphicsScene* scene;
    QGraphicsPixmapItem* img;
    SDL_Surface* surface;

        // Pour la lecture
    QStringList list;
};

#endif // WINDOW_HPP
