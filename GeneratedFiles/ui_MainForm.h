/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralwidget;
    QGroupBox *infoBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_1;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *filenameLabel;
    QLabel *bpsLabel;
    QLabel *byterateLabel;
    QLabel *durationLabel;
    QLabel *samplerateLabel;
    QGroupBox *setupBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QLabel *label_12;
    QComboBox *winfCombo;
    QLineEdit *widthEdit;
    QLabel *label_13;
    QPushButton *processBtn;
    QLineEdit *vecwidthEdit;
    QLabel *label_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *waveLayout;
    QScrollBar *timeScroll;
    QLabel *label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *predLayout;
    QLabel *label_7;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *distLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1036, 519);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(1036, 478));
        centralwidget->setMaximumSize(QSize(1036, 478));
        infoBox = new QGroupBox(centralwidget);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setGeometry(QRect(10, 10, 181, 141));
        gridLayoutWidget = new QWidget(infoBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 20, 181, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(gridLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setLayoutDirection(Qt::LeftToRight);
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        filenameLabel = new QLabel(gridLayoutWidget);
        filenameLabel->setObjectName(QStringLiteral("filenameLabel"));

        gridLayout->addWidget(filenameLabel, 0, 1, 1, 1);

        bpsLabel = new QLabel(gridLayoutWidget);
        bpsLabel->setObjectName(QStringLiteral("bpsLabel"));

        gridLayout->addWidget(bpsLabel, 3, 1, 1, 1);

        byterateLabel = new QLabel(gridLayoutWidget);
        byterateLabel->setObjectName(QStringLiteral("byterateLabel"));

        gridLayout->addWidget(byterateLabel, 2, 1, 1, 1);

        durationLabel = new QLabel(gridLayoutWidget);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));

        gridLayout->addWidget(durationLabel, 4, 1, 1, 1);

        samplerateLabel = new QLabel(gridLayoutWidget);
        samplerateLabel->setObjectName(QStringLiteral("samplerateLabel"));

        gridLayout->addWidget(samplerateLabel, 1, 1, 1, 1);

        setupBox = new QGroupBox(centralwidget);
        setupBox->setObjectName(QStringLiteral("setupBox"));
        setupBox->setEnabled(false);
        setupBox->setGeometry(QRect(0, 160, 191, 151));
        gridLayoutWidget_2 = new QWidget(setupBox);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(9, 19, 182, 129));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        winfCombo = new QComboBox(gridLayoutWidget_2);
        winfCombo->setObjectName(QStringLiteral("winfCombo"));

        gridLayout_2->addWidget(winfCombo, 0, 1, 1, 1);

        widthEdit = new QLineEdit(gridLayoutWidget_2);
        widthEdit->setObjectName(QStringLiteral("widthEdit"));

        gridLayout_2->addWidget(widthEdit, 1, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        processBtn = new QPushButton(gridLayoutWidget_2);
        processBtn->setObjectName(QStringLiteral("processBtn"));
        processBtn->setEnabled(false);
        processBtn->setDefault(true);

        gridLayout_2->addWidget(processBtn, 3, 0, 1, 1);

        vecwidthEdit = new QLineEdit(gridLayoutWidget_2);
        vecwidthEdit->setObjectName(QStringLiteral("vecwidthEdit"));

        gridLayout_2->addWidget(vecwidthEdit, 2, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 20, 61, 16));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(210, 40, 821, 131));
        waveLayout = new QVBoxLayout(verticalLayoutWidget);
        waveLayout->setObjectName(QStringLiteral("waveLayout"));
        waveLayout->setContentsMargins(0, 0, 0, 0);
        timeScroll = new QScrollBar(centralwidget);
        timeScroll->setObjectName(QStringLiteral("timeScroll"));
        timeScroll->setEnabled(false);
        timeScroll->setGeometry(QRect(210, 0, 821, 20));
        timeScroll->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 170, 91, 16));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(210, 190, 821, 131));
        predLayout = new QVBoxLayout(verticalLayoutWidget_2);
        predLayout->setObjectName(QStringLiteral("predLayout"));
        predLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 320, 81, 16));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(210, 340, 821, 131));
        distLayout = new QVBoxLayout(verticalLayoutWidget_3);
        distLayout->setObjectName(QStringLiteral("distLayout"));
        distLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1036, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LPCoding", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        infoBox->setTitle(QApplication::translate("MainWindow", "Info", 0));
        label_1->setText(QApplication::translate("MainWindow", "Filename:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Byte rate:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Duration:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Bits per sample:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Sample rate:", 0));
        filenameLabel->setText(QString());
        bpsLabel->setText(QString());
        byterateLabel->setText(QString());
        durationLabel->setText(QString());
        samplerateLabel->setText(QString());
        setupBox->setTitle(QApplication::translate("MainWindow", "LPC Setup", 0));
        label_11->setText(QApplication::translate("MainWindow", "Window function:", 0));
        label_12->setText(QApplication::translate("MainWindow", "Window width:", 0));
        label_13->setText(QApplication::translate("MainWindow", "Feature vector width:", 0));
        processBtn->setText(QApplication::translate("MainWindow", "Process", 0));
        label_6->setText(QApplication::translate("MainWindow", "Waveform", 0));
        label->setText(QApplication::translate("MainWindow", "Predicted samples", 0));
        label_7->setText(QApplication::translate("MainWindow", "Vector distance", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
