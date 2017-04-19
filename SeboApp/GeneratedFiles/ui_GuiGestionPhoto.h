/********************************************************************************
** Form generated from reading UI file 'GuiGestionPhoto.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIGESTIONPHOTO_H
#define UI_GUIGESTIONPHOTO_H

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

class Ui_GuiGestionPhoto
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblUrl;
    QLineEdit *leSaisieUrl;
    QPushButton *btnChargerPhoto;
    QLabel *lblPhoto;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnValider;
    QPushButton *btnAnnuler;

    void setupUi(QWidget *GuiGestionPhoto)
    {
        if (GuiGestionPhoto->objectName().isEmpty())
            GuiGestionPhoto->setObjectName(QStringLiteral("GuiGestionPhoto"));
        GuiGestionPhoto->resize(601, 597);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        GuiGestionPhoto->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SeboApp/Resources/favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        GuiGestionPhoto->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(GuiGestionPhoto);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblUrl = new QLabel(GuiGestionPhoto);
        lblUrl->setObjectName(QStringLiteral("lblUrl"));

        horizontalLayout->addWidget(lblUrl);

        leSaisieUrl = new QLineEdit(GuiGestionPhoto);
        leSaisieUrl->setObjectName(QStringLiteral("leSaisieUrl"));

        horizontalLayout->addWidget(leSaisieUrl);

        btnChargerPhoto = new QPushButton(GuiGestionPhoto);
        btnChargerPhoto->setObjectName(QStringLiteral("btnChargerPhoto"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SeboApp/Resources/toutAfficher.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnChargerPhoto->setIcon(icon1);

        horizontalLayout->addWidget(btnChargerPhoto);


        verticalLayout->addLayout(horizontalLayout);

        lblPhoto = new QLabel(GuiGestionPhoto);
        lblPhoto->setObjectName(QStringLiteral("lblPhoto"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblPhoto->sizePolicy().hasHeightForWidth());
        lblPhoto->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(28);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lblPhoto->setFont(font1);
        lblPhoto->setPixmap(QPixmap(QString::fromUtf8(":/SeboApp/Resources/pas_image_petit.jpg")));
        lblPhoto->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblPhoto);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnValider = new QPushButton(GuiGestionPhoto);
        btnValider->setObjectName(QStringLiteral("btnValider"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/SeboApp/Resources/valider.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnValider->setIcon(icon2);

        horizontalLayout_2->addWidget(btnValider);

        btnAnnuler = new QPushButton(GuiGestionPhoto);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/SeboApp/Resources/Annuler.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAnnuler->setIcon(icon3);

        horizontalLayout_2->addWidget(btnAnnuler);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(GuiGestionPhoto);

        QMetaObject::connectSlotsByName(GuiGestionPhoto);
    } // setupUi

    void retranslateUi(QWidget *GuiGestionPhoto)
    {
        GuiGestionPhoto->setWindowTitle(QApplication::translate("GuiGestionPhoto", "Saisie de l'url de la photo", Q_NULLPTR));
        lblUrl->setText(QApplication::translate("GuiGestionPhoto", "Adresse URL :", Q_NULLPTR));
        lblPhoto->setText(QString());
        btnValider->setText(QApplication::translate("GuiGestionPhoto", "Valider", Q_NULLPTR));
        btnAnnuler->setText(QApplication::translate("GuiGestionPhoto", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GuiGestionPhoto: public Ui_GuiGestionPhoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIGESTIONPHOTO_H
