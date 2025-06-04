#include "Window.hpp"
#include "ui_Window.h"

#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>

#include <QGraphicsPixmapItem>

#include <iostream>

Window::Window( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::Window ),
    model( 0 ),
    player( 0 ),
    scene( 0 ),
    img( 0 ),
    surface( 0 )
{
    ui->setupUi(this);
    player = new SoundPlayer( this );

    ui->act_Random->setCheckable( true );
    ui->act_Sequence->setCheckable( true );
        ui->act_Sequence->setChecked( true );
    ui->act_RepeatAll->setCheckable( true );
    ui->act_Loop->setCheckable( true );

    connect( ui->btn_PlayPause, SIGNAL(clicked(bool)), this, SLOT(PlayPause()) );
    connect( ui->btn_Mode, SIGNAL(clicked(bool)), this, SLOT(ChangePlayMode()) );
    connect( ui->btn_Stop, SIGNAL(clicked(bool)), this, SLOT(StopPlaying()) );

    connect( ui->btn_AddFile, SIGNAL(clicked(bool)), this, SLOT(AddFile()) );
    connect( ui->btn_PlayCurrent, SIGNAL(clicked(bool)), this, SLOT(PlayCurrent()) );
    connect( ui->btn_RemoveFile, SIGNAL(clicked(bool)), this, SLOT(RemoveFile()) );
    connect( ui->btn_EmptyList, SIGNAL(clicked(bool)), this, SLOT(EmptyList()) );

    connect( ui->btn_Previous, SIGNAL(clicked(bool)), this, SLOT(PreviousFile()) );
    connect( ui->btn_Next, SIGNAL(clicked(bool)), this, SLOT(NextFile()) );

    connect( ui->act_PlayPause, SIGNAL(triggered(bool)), this, SLOT(PlayPause()) );
    connect( ui->act_QAbout, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()) );

    connect( ui->act_Random, SIGNAL(triggered(bool)), this, SLOT(ChangePlayMode()) );
    connect( ui->act_Sequence, SIGNAL(triggered(bool)), this, SLOT(ChangePlayMode()) );
    connect( ui->act_RepeatAll, SIGNAL(triggered(bool)), this, SLOT(ChangePlayMode()) );
    connect( ui->act_Loop, SIGNAL(triggered(bool)), this, SLOT(ChangePlayMode()) );

    connect( ui->act_Previous, SIGNAL(triggered(bool)), this, SLOT(PreviousFile()) );
    connect( ui->act_Next, SIGNAL(triggered(bool)), this, SLOT(NextFile()) );


    model = new QStringListModel;
    ui->playList->setModel( model );

    scene = new QGraphicsScene;
    ui->visualizer->setScene( scene );
    ui->visualizer->setSceneRect( 0, 0, 256, 192 );

    surface = SDL_CreateSurface( 256, 192, SDL_PIXELFORMAT_RGB24 );
    SDL_ClearSurface( surface, 0.0f, 0.0f, 0.0f, 1.0f );
    img = scene->addPixmap( QPixmap::fromImage( QImage( (uchar*) surface->pixels, 256, 192, QImage::Format_RGB888 ) ).scaled( 256, 192, Qt::KeepAspectRatio ) );
}

Window::~Window()
{
    if( surface )
    {
        SDL_DestroySurface( surface );
    }
    delete player;
    delete model;
    delete ui;
}

Ui::Window* Window::GetUi() const
{
    return ui;
}

void Window::PlayPause()
{
    if( list.size() == 0 )
    {
        return ;
    }
    if( player->GetPlayState() == PlayState_Stopped )
    {
        QString title = list[0];
        ui->txt_Title->setText( title.section( '/', title.lastIndexOf( '\\' ) ) );
        player->StartPlaying();
        return ;
    }
    else
    {
        player->PlayPause();
    }
    if( player->GetPlayState() == PlayState_Playing || player->GetPlayState() == PlayState_Stopped )
    {
        ui->btn_PlayPause->setIcon( QIcon( ":/icons/icons/pause.png" ) );
        ui->btn_PlayPause->setToolTip( tr( "Relancer la lecture" ) );

        ui->act_PlayPause->setText( tr( "Jouer" ) );
        ui->act_PlayPause->setToolTip( tr( "Relancer la lecture" ) );
    }
    else
    {
        ui->btn_PlayPause->setIcon( QIcon( ":/icons/icons/play.png" ) );
        ui->btn_PlayPause->setToolTip( tr( "Mettre la lecture en pause" ) );

        ui->act_PlayPause->setText( tr( "Pause" ) );
        ui->act_PlayPause->setToolTip( tr( "Mettre la lecture en pause" ) );
    }

}

void Window::ChangePlayMode()
{
    PlayMode mode = player->GetPlayMode();
    player->ChangePlayMode();
    QAction* act = qobject_cast<QAction*>( sender() );
    if( act != 0 )
    {
        ui->act_Random->setChecked( false );
        ui->act_Sequence->setChecked( false );
        ui->act_RepeatAll->setChecked( false );
        ui->act_Loop->setChecked( false );
        act->setChecked( true );

        if( act == ui->act_Random )
        {
            ui->btn_Mode->setIcon( QIcon( ":/icons/icons/random.png" ) );
            ui->btn_Mode->setToolTip( tr( "Lecture aléatoire" ) );
        }
        else if( act == ui->act_Sequence )
        {
            ui->btn_Mode->setIcon( QIcon( ":/icons/icons/sequential.png" ) );
            ui->btn_Mode->setToolTip( tr( "Lecture Séquentielle" ) );
        }
        else if( act == ui->act_RepeatAll )
        {
            ui->btn_Mode->setIcon( QIcon( ":/icons/icons/listLoop.png" ) );
            ui->btn_Mode->setToolTip( tr( "Répéter la liste en boucle" ) );
        }
        else
        {
            ui->btn_Mode->setIcon( QIcon( ":/icons/icons/loop.png" ) );
            ui->btn_Mode->setToolTip( tr( "Répéter le morceau en boucle" ) );
        }

        return ;
    }
    switch( mode )
    {
    case PlayMode_Sequential:
        ui->btn_Mode->setIcon( QIcon( ":/icons/icons/random.png" ) );
        ui->btn_Mode->setToolTip( tr( "Lecture aléatoire" ) );
        break;

    case PlayMode_Random:
        ui->btn_Mode->setIcon( QIcon( ":/icons/icons/loop.png" ) );
        ui->btn_Mode->setToolTip( tr( "Répéter le morceau en boucle" ) );
        break;

    case PlayMode_Loop:
        ui->btn_Mode->setIcon( QIcon( ":/icons/icons/listLoop.png" ) );
        ui->btn_Mode->setToolTip( tr( "Répéter la liste en boucle" ) );
        break;

    default :
        ui->btn_Mode->setIcon( QIcon( ":/icons/icons/sequential.png" ) );
        ui->btn_Mode->setToolTip( tr( "Lecture Séquentielle" ) );
        break;
    }
}

void Window::NextFile()
{
    if( player->CurrentIndex() >= list.size() - 1 )
    {
        return ;
    }
    player->NextFile();
    QString title = list[player->CurrentIndex()];
    ui->txt_Title->setText( title.section( '/', title.lastIndexOf( '\\' ) ) );
}

void Window::PreviousFile()
{
    if( player->CurrentIndex() == 0 )
    {
        return ;
    }
    player->PreviousFile();
    QString title = list[player->CurrentIndex()];
    ui->txt_Title->setText( title.section( '/', title.lastIndexOf( '\\' ) ) );
}

void Window::StopPlaying()
{
    player->StopPlaying();
    ui->txt_Title->setText( "Aucun" );
    ui->btn_PlayPause->setIcon( QIcon( ":/icons/icons/play.png" ) );
}

void Window::AddFile()
{
    QString str = QFileDialog::getOpenFileName( this,
                                                tr("Ajouter un fichier à la liste de lecture"), QString(),
                                                tr("Fichiers de musiques(*.mp3 *.ogg *.mod *.mid)") );

    if( !str.isEmpty() )
    {
        list << str;
        model->setStringList( list );
    }

    player->UpdateList();
}

void Window::RemoveFile()
{
    QItemSelectionModel* selMod = ui->playList->selectionModel();
    QModelIndex idx = selMod->currentIndex();
    list.removeAt( idx.row() );
    model->setStringList( list );

    player->UpdateList();
}

void Window::EmptyList()
{
    StopPlaying();
    while( list.size() != 0 )
    {
        list.removeFirst();
    }
    model->setStringList( list );
}

void Window::PlayCurrent()
{
    QItemSelectionModel* selMod = ui->playList->selectionModel();
    QModelIndex idx = selMod->currentIndex();
    if( idx.row() >= -1 )
    {
        QString title = list[idx.row()];
        ui->txt_Title->setText( title.section( '/', title.lastIndexOf( '\\' ) ) );
        player->StartWithIndex( idx.row() );
    }
}

QStringList& Window::GetPlaylist()
{
    return list;
}

void Window::SetColor(Uint8 col)
{
    float c = ( float ) col / 255.0f;
    SDL_ClearSurface( surface, 0, 0, 0, 1 );
    SDL_Rect rect;
        rect.w = 256;
        rect.h = c * 192;
        rect.x = 0;
        rect.y = 192 - rect.h;
    Uint32 color;
    if( c <= 0.25f )
    {
            //  La couleur est entre le noir et le rouge
        //SDL_ClearSurface( surface, c, 0, 0, 1 );
        color = SDL_MapRGB(
                    SDL_GetPixelFormatDetails( surface->format ),
                    0, col, 0, 0 );
    }
    else if( c <= 0.50f )
    {
            //  La couleur est entre le rouge et le vert
        //SDL_ClearSurface( surface, 1 - c, c, 0, 1 );
        color = SDL_MapRGB(
                    SDL_GetPixelFormatDetails( surface->format ),
                    0, 255 - col, col, 0 );
    }
    else if( c <= 0.75f )
    {
        //  La couleur est entre le vert et le bleu
        //SDL_ClearSurface( surface, 0, 1 - c, c, 1 );
        color = SDL_MapRGB(
                    SDL_GetPixelFormatDetails( surface->format ),
                    0, 0, 255 - col, col );
    }
    else
    {
        //  La couleur est entre le bleu et le rouge
        //SDL_ClearSurface( surface, c, 0, 1 - c, 1 );
        color = SDL_MapRGB(
                    SDL_GetPixelFormatDetails( surface->format ),
                    0, col, 0, 255 - col );
    }
    SDL_FillSurfaceRect( surface, &rect, color );
    img->setPixmap( QPixmap::fromImage( QImage( (uchar*) surface->pixels, 256, 192, QImage::Format_RGB888 ) ).scaled( 256, 192, Qt::KeepAspectRatio ) );
}

void Window::IndexChange(int idx)
{
    QString title = list[idx];
    ui->txt_Title->setText( title.section( '/', title.lastIndexOf( '\\' ) ) );
}
