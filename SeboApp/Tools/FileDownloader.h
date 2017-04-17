#pragma once

#include <QObject>
#include <QtNetwork>
#include <QByteArray>
#include <QtNetwork\qnetworkaccessmanager.h>
#include <QtNetwork\qnetworkrequest.h>
#include <QtNetwork\qnetworkreply.h>

/// <summary>
/// Cette classe permet de lancer un t�l�chargement de donn�es de fa�on asynchrone
/// </summary>
class FileDownloader : public QObject
{
	Q_OBJECT

public:
	/// <summary>
	/// Constructeur param�tr�
	/// </summary>
	/// <param name="imageUrl">adresse url de l'image � t�l�charger</param>
	/// <param name="parent">Objet parent (par d�faut aucun)</param>
	explicit FileDownloader(QUrl imageUrl, QObject *parent = 0);

	/// <summary>
	/// Destructeur par d�faut
	/// </summary>
	virtual ~FileDownloader();

	/// <summary>
	/// Cette fonction permet de r�cup�rer les donn�es t�l�charg�es
	/// </summary>
	/// <returns>un tableau de bytes qui a �t� t�l�charg�</returns>
	QByteArray downloadedData() const;

signals:
	/// <summary>
	/// Signal �mit lors de la fin du t�l�chargement des donn�es
	/// </summary>
	void downloaded();

private slots:
	/// <summary>
	/// Permet de lancer le t�l�chargement des donn�es
	/// </summary>
	void fileDownloaded(QNetworkReply* pReply);

private:
	/// <summary>
	/// Contr�leur de t�l�chargement
	/// </summary>
	QNetworkAccessManager m_WebCtrl;

	/// <summary>
	/// Donn�es t�l�charg�es
	/// </summary>
	QByteArray m_DownloadedData;
};
