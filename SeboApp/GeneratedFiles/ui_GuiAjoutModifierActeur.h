/********************************************************************************
** Form generated from reading UI file 'GuiAjoutModifierActeur.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIAJOUTMODIFIERACTEUR_H
#define UI_GUIAJOUTMODIFIERACTEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_GuiAjoutModifierActeur
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblLibelle;
    QLineEdit *leSaisieLibelle;
    QLabel *lblCategorie;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QComboBox *cbRole;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnValider;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *GuiAjoutModifierActeur)
    {
        if (GuiAjoutModifierActeur->objectName().isEmpty())
            GuiAjoutModifierActeur->setObjectName(QStringLiteral("GuiAjoutModifierActeur"));
        GuiAjoutModifierActeur->setWindowModality(Qt::ApplicationModal);
        GuiAjoutModifierActeur->resize(238, 139);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiAjoutModifierActeur->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        GuiAjoutModifierActeur->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(GuiAjoutModifierActeur);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lblLibelle = new QLabel(GuiAjoutModifierActeur);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblLibelle);

        leSaisieLibelle = new QLineEdit(GuiAjoutModifierActeur);
        leSaisieLibelle->setObjectName(QStringLiteral("leSaisieLibelle"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leSaisieLibelle);

        lblCategorie = new QLabel(GuiAjoutModifierActeur);
        lblCategorie->setObjectName(QStringLiteral("lblCategorie"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblCategorie->sizePolicy().hasHeightForWidth());
        lblCategorie->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::LabelRole, lblCategorie);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer_2);

        cbRole = new QComboBox(GuiAjoutModifierActeur);
        cbRole->setObjectName(QStringLiteral("cbRole"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cbRole);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnValider = new QPushButton(GuiAjoutModifierActeur);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon1);

        horizontalLayout->addWidget(btnValider);

        btnAnnuler = new QPushButton(GuiAjoutModifierActeur);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/Annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon2);

        horizontalLayout->addWidget(btnAnnuler);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiAjoutModifierActeur);
        QObject::connect(btnAnnuler, SIGNAL(clicked()), GuiAjoutModifierActeur, SLOT(close()));

        QMetaObject::connectSlotsByName(GuiAjoutModifierActeur);
    } // setupUi

    void retranslateUi(QWidget *GuiAjoutModifierActeur)
    {
        GuiAjoutModifierActeur->setWindowTitle(QApplication::translate("GuiAjoutModifierActeur", "Modification Acteur", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("GuiAjoutModifierActeur", "Libell\303\251 :", Q_NULLPTR));
        lblCategorie->setText(QApplication::translate("GuiAjoutModifierActeur", "R\303\264le :", Q_NULLPTR));
        btnValider->setText(QApplication::translate("GuiAjoutModifierActeur", "Valider", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("GuiAjoutModifierActeur", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiAjoutModifierActeur: public Ui_GuiAjoutModifierActeur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIAJOUTMODIFIERACTEUR_H
