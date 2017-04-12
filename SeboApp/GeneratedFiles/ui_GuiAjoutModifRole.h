/********************************************************************************
** Form generated from reading UI file 'GuiAjoutModifRole.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIAJOUTMODIFROLE_H
#define UI_GUIAJOUTMODIFROLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiAjoutModifRole
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblLibelle;
    QLineEdit *leSaisieLibelle;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnValider;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *GuiAjoutModifRole)
    {
        if (GuiAjoutModifRole->objectName().isEmpty())
            GuiAjoutModifRole->setObjectName(QStringLiteral("GuiAjoutModifRole"));
        GuiAjoutModifRole->setWindowModality(Qt::ApplicationModal);
        GuiAjoutModifRole->resize(235, 120);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiAjoutModifRole->setFont(font);
        verticalLayout = new QVBoxLayout(GuiAjoutModifRole);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lblLibelle = new QLabel(GuiAjoutModifRole);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblLibelle);

        leSaisieLibelle = new QLineEdit(GuiAjoutModifRole);
        leSaisieLibelle->setObjectName(QStringLiteral("leSaisieLibelle"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leSaisieLibelle);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer_2);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnValider = new QPushButton(GuiAjoutModifRole);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon);

        horizontalLayout->addWidget(btnValider);

        btnAnnuler = new QPushButton(GuiAjoutModifRole);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/Annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon1);

        horizontalLayout->addWidget(btnAnnuler);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiAjoutModifRole);
        QObject::connect(btnAnnuler, SIGNAL(clicked()), GuiAjoutModifRole, SLOT(close()));

        QMetaObject::connectSlotsByName(GuiAjoutModifRole);
    } // setupUi

    void retranslateUi(QWidget *GuiAjoutModifRole)
    {
        GuiAjoutModifRole->setWindowTitle(QApplication::translate("GuiAjoutModifRole", "Ajout r\303\264le", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("GuiAjoutModifRole", "Libell\303\251 :", Q_NULLPTR));
        btnValider->setText(QApplication::translate("GuiAjoutModifRole", "Valider", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("GuiAjoutModifRole", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiAjoutModifRole: public Ui_GuiAjoutModifRole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIAJOUTMODIFROLE_H
