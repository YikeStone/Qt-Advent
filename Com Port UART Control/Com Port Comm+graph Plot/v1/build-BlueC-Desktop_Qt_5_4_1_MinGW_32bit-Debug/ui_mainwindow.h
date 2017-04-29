/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QSlider *horizontalSlider_2;
    QLineEdit *lineEdit_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QSlider *horizontalSlider_6;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_6;
    QSlider *horizontalSlider_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QSlider *horizontalSlider_7;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_8;
    QSlider *horizontalSlider_5;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_3;
    QSlider *horizontalSlider_8;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_7;
    QSlider *horizontalSlider_4;
    QLineEdit *lineEdit_4;
    QTextBrowser *textBrowser;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QCustomPlot *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(691, 513);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 671, 441));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 671, 121));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 75));
        label->setMaximumSize(QSize(16777215, 75));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalSlider = new QSlider(horizontalLayoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMaximumSize(QSize(16777215, 22));
        horizontalSlider->setMaximum(510);
        horizontalSlider->setValue(255);
        horizontalSlider->setSliderPosition(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMaximumSize(QSize(35, 35));
        lineEdit->setMaxLength(4);
        lineEdit->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_5->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 75));
        label_2->setMaximumSize(QSize(16777215, 75));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalSlider_2 = new QSlider(horizontalLayoutWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        sizePolicy.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy);
        horizontalSlider_2->setMaximumSize(QSize(16777215, 22));
        horizontalSlider_2->setMaximum(510);
        horizontalSlider_2->setValue(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_2);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMaximumSize(QSize(35, 35));
        lineEdit_2->setMaxLength(4);
        lineEdit_2->setClearButtonEnabled(false);

        horizontalLayout_5->addWidget(lineEdit_2);


        verticalLayout_6->addLayout(horizontalLayout_5);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 120, 671, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMaximumSize(QSize(16777215, 35));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_4);

        horizontalSlider_6 = new QSlider(verticalLayoutWidget);
        horizontalSlider_6->setObjectName(QStringLiteral("horizontalSlider_6"));
        horizontalSlider_6->setMaximumSize(QSize(50, 16777215));
        horizontalSlider_6->setMaximum(99);
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(horizontalSlider_6);

        lineEdit_8 = new QLineEdit(verticalLayoutWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setMaximumSize(QSize(50, 16777215));
        lineEdit_8->setMaxLength(3);

        horizontalLayout_9->addWidget(lineEdit_8);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSlider_3 = new QSlider(verticalLayoutWidget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setMaximum(10000000);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setTickPosition(QSlider::NoTicks);

        horizontalLayout_6->addWidget(horizontalSlider_3);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy3);
        lineEdit_3->setMaximumSize(QSize(100, 35));
        lineEdit_3->setMaxLength(20);

        horizontalLayout_6->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMaximumSize(QSize(16777215, 35));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_5);

        horizontalSlider_7 = new QSlider(verticalLayoutWidget);
        horizontalSlider_7->setObjectName(QStringLiteral("horizontalSlider_7"));
        horizontalSlider_7->setMaximumSize(QSize(50, 16777215));
        horizontalSlider_7->setMaximum(99);
        horizontalSlider_7->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(horizontalSlider_7);

        lineEdit_7 = new QLineEdit(verticalLayoutWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setMaximumSize(QSize(50, 16777215));
        lineEdit_7->setMaxLength(3);

        horizontalLayout_10->addWidget(lineEdit_7);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSlider_5 = new QSlider(verticalLayoutWidget);
        horizontalSlider_5->setObjectName(QStringLiteral("horizontalSlider_5"));
        horizontalSlider_5->setMaximum(10000000);
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSlider_5);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy3.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy3);
        lineEdit_5->setMaximumSize(QSize(100, 35));
        lineEdit_5->setMaxLength(20);

        horizontalLayout_8->addWidget(lineEdit_5);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMaximumSize(QSize(16777215, 35));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_3);

        horizontalSlider_8 = new QSlider(verticalLayoutWidget);
        horizontalSlider_8->setObjectName(QStringLiteral("horizontalSlider_8"));
        horizontalSlider_8->setMaximumSize(QSize(50, 16777215));
        horizontalSlider_8->setMaximum(99);
        horizontalSlider_8->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(horizontalSlider_8);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setMaximumSize(QSize(50, 16777215));
        lineEdit_6->setMaxLength(3);

        horizontalLayout_11->addWidget(lineEdit_6);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSlider_4 = new QSlider(verticalLayoutWidget);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setMaximum(10000000);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider_4);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy3.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy3);
        lineEdit_4->setMaximumSize(QSize(100, 35));
        lineEdit_4->setMaxLength(20);

        horizontalLayout_7->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_7);

        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 410, 671, 31));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 360, 671, 41));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        radioButton_2 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setLayoutDirection(Qt::LeftToRight);
        radioButton_2->setChecked(true);

        horizontalLayout_12->addWidget(radioButton_2);

        radioButton = new QRadioButton(horizontalLayoutWidget_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(false);

        horizontalLayout_12->addWidget(radioButton);

        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(679, 9, 1091, 581));
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        widget->raise();
        textBrowser->raise();
        radioButton_2->raise();
        radioButton->raise();
        horizontalLayoutWidget_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 691, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "PWM_Left", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "0", 0));
        label_2->setText(QApplication::translate("MainWindow", "PWM_Right", 0));
        lineEdit_2->setText(QApplication::translate("MainWindow", "0", 0));
        label_4->setText(QApplication::translate("MainWindow", "KP", 0));
        lineEdit_8->setText(QApplication::translate("MainWindow", "0", 0));
        lineEdit_3->setText(QApplication::translate("MainWindow", "0", 0));
        label_5->setText(QApplication::translate("MainWindow", "KI", 0));
        lineEdit_7->setText(QApplication::translate("MainWindow", "0", 0));
        lineEdit_5->setText(QApplication::translate("MainWindow", "0", 0));
        label_3->setText(QApplication::translate("MainWindow", "KD", 0));
        lineEdit_6->setText(QApplication::translate("MainWindow", "0", 0));
        lineEdit_4->setText(QApplication::translate("MainWindow", "0", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "Key Mode", 0));
        radioButton->setText(QApplication::translate("MainWindow", "PWM/ PID mode", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
