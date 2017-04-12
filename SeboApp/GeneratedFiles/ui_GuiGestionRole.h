/********************************************************************************
** Form generated from reading UI file 'GuiGestionRole.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIGESTIONROLE_H
#define UI_GUIGESTIONROLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiGestionRole
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *GuiGestionRole)
    {
        if (GuiGestionRole->objectName().isEmpty())
            GuiGestionRole->setObjectName(QStringLiteral("GuiGestionRole"));
        GuiGestionRole->resize(263, 300);
        verticalLayout = new QVBoxLayout(GuiGestionRole);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(GuiGestionRole);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView = new QTableView(GuiGestionRole);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_3 = new QPushButton(GuiGestionRole);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(GuiGestionRole);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(GuiGestionRole);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiGestionRole);

        QMetaObject::connectSlotsByName(GuiGestionRole);
    } // setupUi

    void retranslateUi(QWidget *GuiGestionRole)
    {
        GuiGestionRole->setWindowTitle(QApplication::translate("GuiGestionRole", "GuiGestionRole", Q_NULLPTR));
        label->setText(QApplication::translate("GuiGestionRole", "TextLabel", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("GuiGestionRole", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("GuiGestionRole", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GuiGestionRole", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGestionRole: public Ui_GuiGestionRole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGESTIONROLE_H
