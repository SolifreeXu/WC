/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *codeLabel;
    QLineEdit *codeEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *wordLabel;
    QLineEdit *wordEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lineLabel;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *codeLineLabel;
    QLineEdit *codeLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *blankLineLabel;
    QLineEdit *blankLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *commentLineLabel;
    QLineEdit *commentLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *dirButton;
    QPushButton *fileButton;
    QPushButton *exitButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        codeLabel = new QLabel(Widget);
        codeLabel->setObjectName(QStringLiteral("codeLabel"));

        horizontalLayout_6->addWidget(codeLabel);

        codeEdit = new QLineEdit(Widget);
        codeEdit->setObjectName(QStringLiteral("codeEdit"));

        horizontalLayout_6->addWidget(codeEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        wordLabel = new QLabel(Widget);
        wordLabel->setObjectName(QStringLiteral("wordLabel"));

        horizontalLayout_3->addWidget(wordLabel);

        wordEdit = new QLineEdit(Widget);
        wordEdit->setObjectName(QStringLiteral("wordEdit"));

        horizontalLayout_3->addWidget(wordEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineLabel = new QLabel(Widget);
        lineLabel->setObjectName(QStringLiteral("lineLabel"));

        horizontalLayout_4->addWidget(lineLabel);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        codeLineLabel = new QLabel(Widget);
        codeLineLabel->setObjectName(QStringLiteral("codeLineLabel"));

        horizontalLayout_5->addWidget(codeLineLabel);

        codeLineEdit = new QLineEdit(Widget);
        codeLineEdit->setObjectName(QStringLiteral("codeLineEdit"));

        horizontalLayout_5->addWidget(codeLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        blankLineLabel = new QLabel(Widget);
        blankLineLabel->setObjectName(QStringLiteral("blankLineLabel"));

        horizontalLayout_2->addWidget(blankLineLabel);

        blankLineEdit = new QLineEdit(Widget);
        blankLineEdit->setObjectName(QStringLiteral("blankLineEdit"));

        horizontalLayout_2->addWidget(blankLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        commentLineLabel = new QLabel(Widget);
        commentLineLabel->setObjectName(QStringLiteral("commentLineLabel"));

        horizontalLayout->addWidget(commentLineLabel);

        commentLineEdit = new QLineEdit(Widget);
        commentLineEdit->setObjectName(QStringLiteral("commentLineEdit"));

        horizontalLayout->addWidget(commentLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        dirButton = new QPushButton(Widget);
        dirButton->setObjectName(QStringLiteral("dirButton"));

        horizontalLayout_7->addWidget(dirButton);

        fileButton = new QPushButton(Widget);
        fileButton->setObjectName(QStringLiteral("fileButton"));

        horizontalLayout_7->addWidget(fileButton);

        exitButton = new QPushButton(Widget);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout_7->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        codeLabel->setText(QApplication::translate("Widget", "\345\255\227 \347\254\246 \346\225\260\357\274\232", Q_NULLPTR));
        wordLabel->setText(QApplication::translate("Widget", "\345\215\225 \350\257\215 \346\225\260\357\274\232", Q_NULLPTR));
        lineLabel->setText(QApplication::translate("Widget", "\350\241\214    \346\225\260\357\274\232", Q_NULLPTR));
        codeLineLabel->setText(QApplication::translate("Widget", "\344\273\243\347\240\201\350\241\214\346\225\260\357\274\232", Q_NULLPTR));
        blankLineLabel->setText(QApplication::translate("Widget", "\347\251\272 \350\241\214 \346\225\260\357\274\232", Q_NULLPTR));
        commentLineLabel->setText(QApplication::translate("Widget", "\346\263\250\351\207\212\350\241\214\346\225\260\357\274\232", Q_NULLPTR));
        dirButton->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\347\233\256\345\275\225", Q_NULLPTR));
        fileButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
