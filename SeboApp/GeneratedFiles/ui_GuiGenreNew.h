/********************************************************************************
** Form generated from reading UI file 'GuiGenreNew.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIGENRENEW_H
#define UI_GUIGENRENEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiGenreNew
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *LblTitre;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblLibelle;
    QLineEdit *leLibelleGenre;
    QLabel *lblCategorie;
    QComboBox *cbCategorie;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAnnuler;
    QPushButton *btnValider;
    QTableView *tvGenre;

    void setupUi(QWidget *GuiGenreNew)
    {
        if (GuiGenreNew->objectName().isEmpty())
            GuiGenreNew->setObjectName(QStringLiteral("GuiGenreNew"));
        GuiGenreNew->resize(400, 300);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        GuiGenreNew->setFont(font);
        verticalLayout = new QVBoxLayout(GuiGenreNew);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        LblTitre = new QLabel(GuiGenreNew);
        LblTitre->setObjectName(QStringLiteral("LblTitre"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        LblTitre->setFont(font1);

        verticalLayout->addWidget(LblTitre);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblLibelle = new QLabel(GuiGenreNew);
        lblLibelle->setObjectName(QStringLiteral("lblLibelle"));
        lblLibelle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblLibelle);

        leLibelleGenre = new QLineEdit(GuiGenreNew);
        leLibelleGenre->setObjectName(QStringLiteral("leLibelleGenre"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leLibelleGenre->sizePolicy().hasHeightForWidth());
        leLibelleGenre->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(leLibelleGenre);

        lblCategorie = new QLabel(GuiGenreNew);
        lblCategorie->setObjectName(QStringLiteral("lblCategorie"));
        lblCategorie->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblCategorie);

        cbCategorie = new QComboBox(GuiGenreNew);
        cbCategorie->setObjectName(QStringLiteral("cbCategorie"));

        horizontalLayout_2->addWidget(cbCategorie);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAnnuler = new QPushButton(GuiGenreNew);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon);

        horizontalLayout->addWidget(btnAnnuler);

        btnValider = new QPushButton(GuiGenreNew);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/Ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon1);

        horizontalLayout->addWidget(btnValider);


        verticalLayout->addLayout(horizontalLayout);

        tvGenre = new QTableView(GuiGenreNew);
        tvGenre->setObjectName(QStringLiteral("tvGenre"));

        verticalLayout->addWidget(tvGenre);


        retranslateUi(GuiGenreNew);

        QMetaObject::connectSlotsByName(GuiGenreNew);
    } // setupUi

    void retranslateUi(QWidget *GuiGenreNew)
    {
        GuiGenreNew->setWindowTitle(QApplication::translate("GuiGenreNew", "GuiGenreNew", Q_NULLPTR));
        LblTitre->setText(QApplication::translate("GuiGenreNew", "Cr\303\251ation d'un genre :", Q_NULLPTR));
        lblLibelle->setText(QApplication::translate("GuiGenreNew", "Libell\303\251 du genre :", Q_NULLPTR));
        lblCategorie->setText(QApplication::translate("GuiGenreNew", "Cat\303\251gorie :", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("GuiGenreNew", "Annuler", Q_NULLPTR));
        btnValider->setText(QApplication::translate("GuiGenreNew", "Valider", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGenreNew: public Ui_GuiGenreNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGENRENEW_H
