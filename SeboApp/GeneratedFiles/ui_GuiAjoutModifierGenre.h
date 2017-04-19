/********************************************************************************
** Form generated from reading UI file 'GuiAjoutModifierGenre.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIAJOUTMODIFIERGENRE_H
#define UI_GUIAJOUTMODIFIERGENRE_H

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

class Ui_GuiAjoutModifierGenre
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblLibelle;
    QLineEdit *leSaisieLibelle;
    QLabel *lblCategorie;
    QComboBox *cbCategorie;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnValider;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *GuiAjoutModifierGenre)
    {
        if (GuiAjoutModifierGenre->objectName().isEmpty())
            GuiAjoutModifierGenre->setObjectName(QStringLiteral("GuiAjoutModifierGenre"));
        GuiAjoutModifierGenre->setWindowModality(Qt::ApplicationModal);
        GuiAjoutModifierGenre->resize(237, 138);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiAjoutModifierGenre->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        GuiAjoutModifierGenre->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(GuiAjoutModifierGenre);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lblLibelle = new QLabel(GuiAjoutModifierGenre);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblLibelle);

        leSaisieLibelle = new QLineEdit(GuiAjoutModifierGenre);
        leSaisieLibelle->setObjectName(QStringLiteral("leSaisieLibelle"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leSaisieLibelle);

        lblCategorie = new QLabel(GuiAjoutModifierGenre);
        lblCategorie->setObjectName(QStringLiteral("lblCategorie"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblCategorie);

        cbCategorie = new QComboBox(GuiAjoutModifierGenre);
        cbCategorie->setObjectName(QStringLiteral("cbCategorie"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cbCategorie);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer_2);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnValider = new QPushButton(GuiAjoutModifierGenre);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon1);

        horizontalLayout->addWidget(btnValider);

        btnAnnuler = new QPushButton(GuiAjoutModifierGenre);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/Annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon2);

        horizontalLayout->addWidget(btnAnnuler);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiAjoutModifierGenre);
        QObject::connect(btnAnnuler, SIGNAL(clicked()), GuiAjoutModifierGenre, SLOT(close()));

        QMetaObject::connectSlotsByName(GuiAjoutModifierGenre);
    } // setupUi

    void retranslateUi(QWidget *GuiAjoutModifierGenre)
    {
        GuiAjoutModifierGenre->setWindowTitle(QApplication::translate("GuiAjoutModifierGenre", "Modification d'un genre", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("GuiAjoutModifierGenre", "Libell\303\251 :", Q_NULLPTR));
        lblCategorie->setText(QApplication::translate("GuiAjoutModifierGenre", "Cat\303\251gorie :", Q_NULLPTR));
        btnValider->setText(QApplication::translate("GuiAjoutModifierGenre", "Valider", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("GuiAjoutModifierGenre", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiAjoutModifierGenre: public Ui_GuiAjoutModifierGenre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIAJOUTMODIFIERGENRE_H
