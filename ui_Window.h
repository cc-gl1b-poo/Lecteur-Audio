/********************************************************************************
** Form generated from reading UI file 'Window.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QAction *act_About;
    QAction *act_AddFile;
    QAction *act_PlayPause;
    QAction *act_Previous;
    QAction *act_Next;
    QAction *act_Stop;
    QAction *act_Random;
    QAction *act_Sequence;
    QAction *act_RepeatAll;
    QAction *act_QAbout;
    QAction *act_Loop;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QGraphicsView *visualizer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLCDNumber *lcd_min;
    QLCDNumber *lcd_Sec;
    QLabel *txtTitleInfo;
    QLabel *txt_Title;
    QHBoxLayout *horizontalLayout_4;
    QLabel *txt_DurationInfo;
    QLabel *txt_Time;
    QSlider *timeline;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_Stop;
    QPushButton *btn_Previous;
    QPushButton *btn_PlayPause;
    QPushButton *btn_Next;
    QPushButton *btn_Mode;
    QSpacerItem *horizontalSpacer_4;
    QListView *playList;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_AddFile;
    QPushButton *btn_PlayCurrent;
    QPushButton *btn_RemoveFile;
    QPushButton *btn_EmptyList;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuLecture;
    QMenu *menuMode_de_lecture;
    QMenu *menuAide;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(479, 583);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Window->setWindowIcon(icon);
        act_About = new QAction(Window);
        act_About->setObjectName(QStringLiteral("act_About"));
        act_AddFile = new QAction(Window);
        act_AddFile->setObjectName(QStringLiteral("act_AddFile"));
        act_PlayPause = new QAction(Window);
        act_PlayPause->setObjectName(QStringLiteral("act_PlayPause"));
        act_Previous = new QAction(Window);
        act_Previous->setObjectName(QStringLiteral("act_Previous"));
        act_Next = new QAction(Window);
        act_Next->setObjectName(QStringLiteral("act_Next"));
        act_Stop = new QAction(Window);
        act_Stop->setObjectName(QStringLiteral("act_Stop"));
        act_Random = new QAction(Window);
        act_Random->setObjectName(QStringLiteral("act_Random"));
        act_Sequence = new QAction(Window);
        act_Sequence->setObjectName(QStringLiteral("act_Sequence"));
        act_RepeatAll = new QAction(Window);
        act_RepeatAll->setObjectName(QStringLiteral("act_RepeatAll"));
        act_QAbout = new QAction(Window);
        act_QAbout->setObjectName(QStringLiteral("act_QAbout"));
        act_Loop = new QAction(Window);
        act_Loop->setObjectName(QStringLiteral("act_Loop"));
        centralWidget = new QWidget(Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        visualizer = new QGraphicsView(centralWidget);
        visualizer->setObjectName(QStringLiteral("visualizer"));
        visualizer->setMinimumSize(QSize(260, 200));
        visualizer->setMaximumSize(QSize(260, 200));

        horizontalLayout_5->addWidget(visualizer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lcd_min = new QLCDNumber(centralWidget);
        lcd_min->setObjectName(QStringLiteral("lcd_min"));

        horizontalLayout_3->addWidget(lcd_min);

        lcd_Sec = new QLCDNumber(centralWidget);
        lcd_Sec->setObjectName(QStringLiteral("lcd_Sec"));

        horizontalLayout_3->addWidget(lcd_Sec);


        verticalLayout->addLayout(horizontalLayout_3);

        txtTitleInfo = new QLabel(centralWidget);
        txtTitleInfo->setObjectName(QStringLiteral("txtTitleInfo"));
        QFont font;
        font.setPointSize(12);
        txtTitleInfo->setFont(font);

        verticalLayout->addWidget(txtTitleInfo);

        txt_Title = new QLabel(centralWidget);
        txt_Title->setObjectName(QStringLiteral("txt_Title"));

        verticalLayout->addWidget(txt_Title);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        txt_DurationInfo = new QLabel(centralWidget);
        txt_DurationInfo->setObjectName(QStringLiteral("txt_DurationInfo"));
        QFont font1;
        font1.setPointSize(11);
        txt_DurationInfo->setFont(font1);

        horizontalLayout_4->addWidget(txt_DurationInfo);

        txt_Time = new QLabel(centralWidget);
        txt_Time->setObjectName(QStringLiteral("txt_Time"));
        QFont font2;
        font2.setPointSize(16);
        txt_Time->setFont(font2);

        horizontalLayout_4->addWidget(txt_Time);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_5);

        timeline = new QSlider(centralWidget);
        timeline->setObjectName(QStringLiteral("timeline"));
        timeline->setPageStep(1);
        timeline->setOrientation(Qt::Horizontal);
        timeline->setTickPosition(QSlider::NoTicks);

        verticalLayout_2->addWidget(timeline);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_Stop = new QPushButton(centralWidget);
        btn_Stop->setObjectName(QStringLiteral("btn_Stop"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Stop->setIcon(icon1);
        btn_Stop->setIconSize(QSize(32, 32));
        btn_Stop->setFlat(false);

        horizontalLayout_2->addWidget(btn_Stop);

        btn_Previous = new QPushButton(centralWidget);
        btn_Previous->setObjectName(QStringLiteral("btn_Previous"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Previous->setIcon(icon2);
        btn_Previous->setIconSize(QSize(32, 32));
        btn_Previous->setFlat(false);

        horizontalLayout_2->addWidget(btn_Previous);

        btn_PlayPause = new QPushButton(centralWidget);
        btn_PlayPause->setObjectName(QStringLiteral("btn_PlayPause"));
        btn_PlayPause->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_PlayPause->setIcon(icon3);
        btn_PlayPause->setIconSize(QSize(32, 32));
        btn_PlayPause->setFlat(false);

        horizontalLayout_2->addWidget(btn_PlayPause);

        btn_Next = new QPushButton(centralWidget);
        btn_Next->setObjectName(QStringLiteral("btn_Next"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Next->setIcon(icon4);
        btn_Next->setIconSize(QSize(32, 32));
        btn_Next->setFlat(false);

        horizontalLayout_2->addWidget(btn_Next);

        btn_Mode = new QPushButton(centralWidget);
        btn_Mode->setObjectName(QStringLiteral("btn_Mode"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/sequential.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Mode->setIcon(icon5);
        btn_Mode->setIconSize(QSize(32, 32));
        btn_Mode->setFlat(false);

        horizontalLayout_2->addWidget(btn_Mode);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        playList = new QListView(centralWidget);
        playList->setObjectName(QStringLiteral("playList"));
        playList->setMinimumSize(QSize(0, 192));

        verticalLayout_2->addWidget(playList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_AddFile = new QPushButton(centralWidget);
        btn_AddFile->setObjectName(QStringLiteral("btn_AddFile"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_AddFile->setIcon(icon6);
        btn_AddFile->setIconSize(QSize(32, 32));
        btn_AddFile->setFlat(false);

        horizontalLayout->addWidget(btn_AddFile);

        btn_PlayCurrent = new QPushButton(centralWidget);
        btn_PlayCurrent->setObjectName(QStringLiteral("btn_PlayCurrent"));
        btn_PlayCurrent->setIcon(icon3);
        btn_PlayCurrent->setIconSize(QSize(32, 32));
        btn_PlayCurrent->setFlat(false);

        horizontalLayout->addWidget(btn_PlayCurrent);

        btn_RemoveFile = new QPushButton(centralWidget);
        btn_RemoveFile->setObjectName(QStringLiteral("btn_RemoveFile"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_RemoveFile->setIcon(icon7);
        btn_RemoveFile->setIconSize(QSize(32, 32));
        btn_RemoveFile->setFlat(false);

        horizontalLayout->addWidget(btn_RemoveFile);

        btn_EmptyList = new QPushButton(centralWidget);
        btn_EmptyList->setObjectName(QStringLiteral("btn_EmptyList"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/icons/empty.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_EmptyList->setIcon(icon8);
        btn_EmptyList->setIconSize(QSize(32, 32));
        btn_EmptyList->setFlat(false);

        horizontalLayout->addWidget(btn_EmptyList);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 479, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuLecture = new QMenu(menuBar);
        menuLecture->setObjectName(QStringLiteral("menuLecture"));
        menuMode_de_lecture = new QMenu(menuLecture);
        menuMode_de_lecture->setObjectName(QStringLiteral("menuMode_de_lecture"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        Window->setMenuBar(menuBar);
        statusBar = new QStatusBar(Window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Window->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuLecture->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(act_AddFile);
        menuLecture->addAction(act_PlayPause);
        menuLecture->addAction(act_Previous);
        menuLecture->addAction(act_Next);
        menuLecture->addAction(act_Stop);
        menuLecture->addAction(menuMode_de_lecture->menuAction());
        menuMode_de_lecture->addAction(act_Random);
        menuMode_de_lecture->addAction(act_Sequence);
        menuMode_de_lecture->addAction(act_RepeatAll);
        menuMode_de_lecture->addAction(act_Loop);
        menuAide->addAction(act_About);
        menuAide->addAction(act_QAbout);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Audio", 0));
        act_About->setText(QApplication::translate("Window", "A propos de Audio ...", 0));
        act_AddFile->setText(QApplication::translate("Window", "Ouvrir un fichier", 0));
        act_PlayPause->setText(QApplication::translate("Window", "Jouer", 0));
#ifndef QT_NO_TOOLTIP
        act_PlayPause->setToolTip(QApplication::translate("Window", "Lancer la lecture", 0));
#endif // QT_NO_TOOLTIP
        act_Previous->setText(QApplication::translate("Window", "Pr\303\251c\303\251dent", 0));
        act_Next->setText(QApplication::translate("Window", "Suivant", 0));
        act_Stop->setText(QApplication::translate("Window", "Arr\303\252ter", 0));
        act_Random->setText(QApplication::translate("Window", "Al\303\251atoire", 0));
        act_Sequence->setText(QApplication::translate("Window", "S\303\251quence", 0));
        act_RepeatAll->setText(QApplication::translate("Window", "R\303\251p\303\251ter Tout", 0));
        act_QAbout->setText(QApplication::translate("Window", "A propos de Qt ...", 0));
        act_Loop->setText(QApplication::translate("Window", "Lire en boucle", 0));
        txtTitleInfo->setText(QApplication::translate("Window", "Morceau Actuel :", 0));
        txt_Title->setText(QApplication::translate("Window", "Aucun", 0));
        txt_DurationInfo->setText(QApplication::translate("Window", "Dur\303\251e du morceau :", 0));
        txt_Time->setText(QApplication::translate("Window", "00:00", 0));
#ifndef QT_NO_TOOLTIP
        btn_Stop->setToolTip(QApplication::translate("Window", "Arr\303\252ter la lecture", 0));
#endif // QT_NO_TOOLTIP
        btn_Stop->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_Previous->setToolTip(QApplication::translate("Window", "Fichier pr\303\251c\303\251dent", 0));
#endif // QT_NO_TOOLTIP
        btn_Previous->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_PlayPause->setToolTip(QApplication::translate("Window", "Jouer", 0));
#endif // QT_NO_TOOLTIP
        btn_PlayPause->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_Next->setToolTip(QApplication::translate("Window", "Fichier Suivant", 0));
#endif // QT_NO_TOOLTIP
        btn_Next->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_Mode->setToolTip(QApplication::translate("Window", "Lecture s\303\251quentielle", 0));
#endif // QT_NO_TOOLTIP
        btn_Mode->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_AddFile->setToolTip(QApplication::translate("Window", "Ajouter un fichier", 0));
#endif // QT_NO_TOOLTIP
        btn_AddFile->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_PlayCurrent->setToolTip(QApplication::translate("Window", "Jouer le morceau s\303\251lectionn\303\251", 0));
#endif // QT_NO_TOOLTIP
        btn_PlayCurrent->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_RemoveFile->setToolTip(QApplication::translate("Window", "Retirer ce fichier", 0));
#endif // QT_NO_TOOLTIP
        btn_RemoveFile->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_EmptyList->setToolTip(QApplication::translate("Window", "Vider la liste de lecture", 0));
#endif // QT_NO_TOOLTIP
        btn_EmptyList->setText(QString());
        menuFichier->setTitle(QApplication::translate("Window", "Fichier", 0));
        menuLecture->setTitle(QApplication::translate("Window", "Lecture", 0));
        menuMode_de_lecture->setTitle(QApplication::translate("Window", "Mode de lecture", 0));
        menuAide->setTitle(QApplication::translate("Window", "Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
