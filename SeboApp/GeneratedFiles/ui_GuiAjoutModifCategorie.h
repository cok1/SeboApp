/********************************************************************************
** Form generated from reading UI file 'GuiAjoutModifCategorie.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIAJOUTMODIFCATEGORIE_H
#define UI_GUIAJOUTMODIFCATEGORIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
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

class Ui_GuiAjoutModifCategorie
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblLibelle;
    QLineEdit *leSaisieLibelle;
    QLabel *lblTauxTVA;
    QDoubleSpinBox *spTauxTva;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnValider;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *GuiAjoutModifCategorie)
    {
        if (GuiAjoutModifCategorie->objectName().isEmpty())
            GuiAjoutModifCategorie->setObjectName(QStringLiteral("GuiAjoutModifCategorie"));
        GuiAjoutModifCategorie->setWindowModality(Qt::ApplicationModal);
        GuiAjoutModifCategorie->resize(236, 135);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiAjoutModifCategorie->setFont(font);
        verticalLayout = new QVBoxLayout(GuiAjoutModifCategorie);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lblLibelle = new QLabel(GuiAjoutModifCategorie);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblLibelle->sizePolicy().hasHeightForWidth());
        lblLibelle->setSizePolicy(sizePolicy);
        lblLibelle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, lblLibelle);

        leSaisieLibelle = new QLineEdit(GuiAjoutModifCategorie);
        leSaisieLibelle->setObjectName(QStringLiteral("leSaisieLibelle"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leSaisieLibelle);

        lblTauxTVA = new QLabel(GuiAjoutModifCategorie);
        lblTauxTVA->setObjectName(QStringLiteral("lblTauxTVA"));
        sizePolicy.setHeightForWidth(lblTauxTVA->sizePolicy().hasHeightForWidth());
        lblTauxTVA->setSizePolicy(sizePolicy);
        lblTauxTVA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, lblTauxTVA);

        spTauxTva = new QDoubleSpinBox(GuiAjoutModifCategorie);
        spTauxTva->setObjectName(QStringLiteral("spTauxTva"));
        spTauxTva->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spTauxTva->setMaximum(50);
        spTauxTva->setValue(20);

        formLayout->setWidget(2, QFormLayout::FieldRole, spTauxTva);

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

        btnValider = new QPushButton(GuiAjoutModifCategorie);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon);

        horizontalLayout->addWidget(btnValider);

        btnAnnuler = new QPushButton(GuiAjoutModifCategorie);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon1);

        horizontalLayout->addWidget(btnAnnuler);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GuiAjoutModifCategorie);
        QObject::connect(btnAnnuler, SIGNAL(clicked()), GuiAjoutModifCategorie, SLOT(close()));

        QMetaObject::connectSlotsByName(GuiAjoutModifCategorie);
    } // setupUi

    void retranslateUi(QWidget *GuiAjoutModifCategorie)
    {
        GuiAjoutModifCategorie->setWindowTitle(QApplication::translate("GuiAjoutModifCategorie", "Ajout d'une cat\303\251gorie", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("GuiAjoutModifCategorie", "Libell\303\251 :", Q_NULLPTR));
        lblTauxTVA->setText(QApplication::translate("GuiAjoutModifCategorie", "Taux Tva :", Q_NULLPTR));
        spTauxTva->setSuffix(QApplication::translate("GuiAjoutModifCategorie", " %", Q_NULLPTR));
        btnValider->setText(QApplication::translate("GuiAjoutModifCategorie", "Valider", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("GuiAjoutModifCategorie", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiAjoutModifCategorie: public Ui_GuiAjoutModifCategorie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIAJOUTMODIFCATEGORIE_H
