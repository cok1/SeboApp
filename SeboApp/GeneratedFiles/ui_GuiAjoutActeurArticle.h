/********************************************************************************
** Form generated from reading UI file 'GuiAjoutActeurArticle.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIAJOUTACTEURARTICLE_H
#define UI_GUIAJOUTACTEURARTICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiAjoutActeurArticle
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lblActeursDispos;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblFiltrerRole;
    QComboBox *cbFiltrerRoles;
    QPushButton *btnToutAfficher;
    QTableView *tvActeursDispos;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnGererActeurs;
    QPushButton *btnGererRoles;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnAjouter;
    QPushButton *btnRetirer;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblActeursLies;
    QTableView *tvActeursLies;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnValider;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *GuiAjoutActeurArticle)
    {
        if (GuiAjoutActeurArticle->objectName().isEmpty())
            GuiAjoutActeurArticle->setObjectName(QStringLiteral("GuiAjoutActeurArticle"));
        GuiAjoutActeurArticle->setWindowModality(Qt::ApplicationModal);
        GuiAjoutActeurArticle->resize(753, 358);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiAjoutActeurArticle->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        GuiAjoutActeurArticle->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(GuiAjoutActeurArticle);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblActeursDispos = new QLabel(GuiAjoutActeurArticle);
        lblActeursDispos->setObjectName(QStringLiteral("lblActeursDispos"));
        lblActeursDispos->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblActeursDispos);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lblFiltrerRole = new QLabel(GuiAjoutActeurArticle);
        lblFiltrerRole->setObjectName(QStringLiteral("lblFiltrerRole"));
        lblFiltrerRole->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lblFiltrerRole);

        cbFiltrerRoles = new QComboBox(GuiAjoutActeurArticle);
        cbFiltrerRoles->setObjectName(QStringLiteral("cbFiltrerRoles"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbFiltrerRoles->sizePolicy().hasHeightForWidth());
        cbFiltrerRoles->setSizePolicy(sizePolicy);
        cbFiltrerRoles->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(cbFiltrerRoles);

        btnToutAfficher = new QPushButton(GuiAjoutActeurArticle);
        btnToutAfficher->setObjectName(QStringLiteral("btnToutAfficher"));
        btnToutAfficher->setMinimumSize(QSize(27, 27));
        btnToutAfficher->setMaximumSize(QSize(27, 27));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/toutAfficher.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToutAfficher->setIcon(icon1);

        horizontalLayout_3->addWidget(btnToutAfficher);


        verticalLayout->addLayout(horizontalLayout_3);

        tvActeursDispos = new QTableView(GuiAjoutActeurArticle);
        tvActeursDispos->setObjectName(QStringLiteral("tvActeursDispos"));
        tvActeursDispos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvActeursDispos->setAlternatingRowColors(true);
        tvActeursDispos->setSelectionMode(QAbstractItemView::MultiSelection);
        tvActeursDispos->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvActeursDispos->setSortingEnabled(true);
        tvActeursDispos->horizontalHeader()->setVisible(false);
        tvActeursDispos->horizontalHeader()->setStretchLastSection(true);
        tvActeursDispos->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tvActeursDispos);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnGererActeurs = new QPushButton(GuiAjoutActeurArticle);
        btnGererActeurs->setObjectName(QStringLiteral("btnGererActeurs"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/modifier2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGererActeurs->setIcon(icon2);

        horizontalLayout_5->addWidget(btnGererActeurs);

        btnGererRoles = new QPushButton(GuiAjoutActeurArticle);
        btnGererRoles->setObjectName(QStringLiteral("btnGererRoles"));
        btnGererRoles->setIcon(icon2);

        horizontalLayout_5->addWidget(btnGererRoles);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btnAjouter = new QPushButton(GuiAjoutActeurArticle);
        btnAjouter->setObjectName(QStringLiteral("btnAjouter"));

        verticalLayout_3->addWidget(btnAjouter);

        btnRetirer = new QPushButton(GuiAjoutActeurArticle);
        btnRetirer->setObjectName(QStringLiteral("btnRetirer"));

        verticalLayout_3->addWidget(btnRetirer);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblActeursLies = new QLabel(GuiAjoutActeurArticle);
        lblActeursLies->setObjectName(QStringLiteral("lblActeursLies"));
        lblActeursLies->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblActeursLies);

        tvActeursLies = new QTableView(GuiAjoutActeurArticle);
        tvActeursLies->setObjectName(QStringLiteral("tvActeursLies"));
        tvActeursLies->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvActeursLies->setAlternatingRowColors(true);
        tvActeursLies->setSelectionMode(QAbstractItemView::MultiSelection);
        tvActeursLies->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvActeursLies->setSortingEnabled(true);
        tvActeursLies->horizontalHeader()->setVisible(false);
        tvActeursLies->horizontalHeader()->setStretchLastSection(true);
        tvActeursLies->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tvActeursLies);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnValider = new QPushButton(GuiAjoutActeurArticle);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/SeboApp/Resources/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon3);

        horizontalLayout_4->addWidget(btnValider);

        btnAnnuler = new QPushButton(GuiAjoutActeurArticle);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/SeboApp/Resources/Annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon4);

        horizontalLayout_4->addWidget(btnAnnuler);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(GuiAjoutActeurArticle);
        QObject::connect(btnAnnuler, SIGNAL(clicked()), GuiAjoutActeurArticle, SLOT(close()));

        QMetaObject::connectSlotsByName(GuiAjoutActeurArticle);
    } // setupUi

    void retranslateUi(QWidget *GuiAjoutActeurArticle)
    {
        GuiAjoutActeurArticle->setWindowTitle(QApplication::translate("GuiAjoutActeurArticle", "Gestion des acteurs par article", Q_NULLPTR));
        lblActeursDispos->setText(QApplication::translate("GuiAjoutActeurArticle", "Acteurs disponibles :", Q_NULLPTR));
        lblFiltrerRole->setText(QApplication::translate("GuiAjoutActeurArticle", "Filtrer par r\303\264les :", Q_NULLPTR));
        btnToutAfficher->setText(QString());
        btnGererActeurs->setText(QApplication::translate("GuiAjoutActeurArticle", "G\303\251rer les acteurs", Q_NULLPTR));
        btnGererRoles->setText(QApplication::translate("GuiAjoutActeurArticle", "G\303\251rer les r\303\264les", Q_NULLPTR));
        btnAjouter->setText(QApplication::translate("GuiAjoutActeurArticle", "---->", Q_NULLPTR));
        btnRetirer->setText(QApplication::translate("GuiAjoutActeurArticle", "<----", Q_NULLPTR));
        lblActeursLies->setText(QApplication::translate("GuiAjoutActeurArticle", "Acteurs li\303\251s \303\240 l'article :", Q_NULLPTR));
        btnValider->setText(QApplication::translate("GuiAjoutActeurArticle", "Valider", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("GuiAjoutActeurArticle", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiAjoutActeurArticle: public Ui_GuiAjoutActeurArticle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIAJOUTACTEURARTICLE_H
