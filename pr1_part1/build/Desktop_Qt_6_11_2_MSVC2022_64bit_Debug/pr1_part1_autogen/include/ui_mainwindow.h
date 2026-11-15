/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *action_9;
    QAction *action_10;
    QAction *action_11;
    QAction *action_12;
    QAction *action_13;
    QAction *action_14;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *videoLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QSpacerItem *horizontalSpacer;
    QSlider *horizontalSlider_2;
    QLabel *label_4;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QMenu *menu_7;
    QMenu *menu_8;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 638);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        action_5 = new QAction(MainWindow);
        action_5->setObjectName("action_5");
        action_6 = new QAction(MainWindow);
        action_6->setObjectName("action_6");
        action_7 = new QAction(MainWindow);
        action_7->setObjectName("action_7");
        action_8 = new QAction(MainWindow);
        action_8->setObjectName("action_8");
        action_9 = new QAction(MainWindow);
        action_9->setObjectName("action_9");
        action_10 = new QAction(MainWindow);
        action_10->setObjectName("action_10");
        action_11 = new QAction(MainWindow);
        action_11->setObjectName("action_11");
        action_12 = new QAction(MainWindow);
        action_12->setObjectName("action_12");
        action_13 = new QAction(MainWindow);
        action_13->setObjectName("action_13");
        action_14 = new QAction(MainWindow);
        action_14->setObjectName("action_14");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        videoLabel = new QLabel(centralwidget);
        videoLabel->setObjectName("videoLabel");
        videoLabel->setStyleSheet(QString::fromUtf8("background-color: black;"));
        videoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/conus.png")));
        videoLabel->setScaledContents(false);
        videoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(videoLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");

        horizontalLayout_2->addWidget(toolButton);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        toolButton_2 = new QToolButton(centralwidget);
        toolButton_2->setObjectName("toolButton_2");

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(centralwidget);
        toolButton_3->setObjectName("toolButton_3");

        horizontalLayout_2->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(centralwidget);
        toolButton_4->setObjectName("toolButton_4");

        horizontalLayout_2->addWidget(toolButton_4);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        toolButton_5 = new QToolButton(centralwidget);
        toolButton_5->setObjectName("toolButton_5");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/rastyanut.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_5->setIcon(icon);

        horizontalLayout_2->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(centralwidget);
        toolButton_6->setObjectName("toolButton_6");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/ecvalaizer.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_6->setIcon(icon1);

        horizontalLayout_2->addWidget(toolButton_6);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        toolButton_7 = new QToolButton(centralwidget);
        toolButton_7->setObjectName("toolButton_7");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/list.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_7->setIcon(icon2);

        horizontalLayout_2->addWidget(toolButton_7);

        toolButton_8 = new QToolButton(centralwidget);
        toolButton_8->setObjectName("toolButton_8");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/repeat.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_8->setIcon(icon3);

        horizontalLayout_2->addWidget(toolButton_8);

        toolButton_9 = new QToolButton(centralwidget);
        toolButton_9->setObjectName("toolButton_9");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/shuffle.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_9->setIcon(icon4);

        horizontalLayout_2->addWidget(toolButton_9);

        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(70, 20));
        label_3->setMaximumSize(QSize(70, 20));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/Photoroom.png")));
        label_3->setScaledContents(true);

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName("menu_5");
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName("menu_6");
        menu_7 = new QMenu(menubar);
        menu_7->setObjectName("menu_7");
        menu_8 = new QMenu(menubar);
        menu_8->setObjectName("menu_8");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_6->menuAction());
        menubar->addAction(menu_7->menuAction());
        menubar->addAction(menu_8->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu_2->addAction(action_3);
        menu_2->addAction(action_4);
        menu_3->addAction(action_5);
        menu_3->addAction(action_6);
        menu_4->addAction(action_7);
        menu_4->addAction(action_8);
        menu_5->addAction(action_9);
        menu_5->addAction(action_10);
        menu_6->addAction(action_11);
        menu_6->addAction(action_12);
        menu_7->addAction(action_13);
        menu_8->addAction(action_14);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\264\320\270\320\260\320\277\321\200\320\276\320\270\320\263\321\200\321\213\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\320\260\320\277\320\272\321\203", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\320\260\320\277\320\272\321\203", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        action_5->setText(QCoreApplication::translate("MainWindow", "\320\243\320\262\320\265\320\273\320\270\321\207\320\270\321\202\321\214 \320\263\321\200\320\276\320\274\320\272\320\276\321\201\321\202\321\214", nullptr));
        action_6->setText(QCoreApplication::translate("MainWindow", "\320\243\320\274\320\265\320\275\321\214\321\210\320\270\321\202\321\214 \320\263\321\200\320\276\320\274\320\272\320\276\321\201\321\202\321\214", nullptr));
        action_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\276\321\215\320\272\321\200\320\260\320\275\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", nullptr));
        action_8->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\201\320\275\320\270\320\274\320\276\320\272 \320\272\320\260\320\264\321\200\320\260", nullptr));
        action_9->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\201\321\203\320\261\321\202\320\270\321\202\321\200\321\213", nullptr));
        action_10->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\201\321\203\320\261\321\202\320\270\321\202\321\200\321\213", nullptr));
        action_11->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        action_12->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\274\320\265\320\264\320\270\320\260", nullptr));
        action_13->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202", nullptr));
        action_14->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265...", nullptr));
        videoLabel->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "\342\226\266", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "\342\227\200\342\227\200", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "\342\226\240", nullptr));
        toolButton_4->setText(QCoreApplication::translate("MainWindow", "\342\226\266\342\226\266", nullptr));
        toolButton_5->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_6->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_8->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_9->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "50%", nullptr));
        label_3->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\264\320\270\320\260", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\276\321\201\320\277\321\200\320\276\320\270\320\267\320\262\320\265\320\264\320\265\320\275\320\270\320\265", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\220\321\203\320\264\320\270\320\276", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\265\320\276", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\261\321\202\320\270\321\202\321\200\321\213", nullptr));
        menu_6->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213", nullptr));
        menu_7->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264", nullptr));
        menu_8->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
