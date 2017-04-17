#pragma once

#include <QObject>
#include <QtNetwork>
#include <QByteArray>
#include <QtNetwork\qnetworkaccessmanager.h>
#include <QtNetwork\qnetworkrequest.h>
#include <QtNetwork\qnetworkreply.h>

/// <summary>
/// Cette classe permet de lancer un téléchargement de données de façon asynchrone
/// </summary>
class FileDownloader : public QObject
{
	Q_OBJECT

public:
	/// <summary>
	/// Constructeur paramétré
	/// </summary>
	/// <param name="imageUrl">adresse url de l'image à télécharger</param>
	/// <param name="parent">Objet parent (par défaut aucun)</param>
	explicit FileDownloader(QUrl imageUrl, QObject *parent = 0);

	/// <summary>
	/// Destructeur par défaut
	/// </summary>
	virtual ~FileDownloader();

	/// <summary>
	/// Cette fonction permet de récupérer les données téléchargées
	/// </summary>
	/// <returns>un tableau de bytes qui a été téléchargé</returns>
	QByteArray downloadedData() const;

signals:
	/// <summary>
	/// Signal émit lors de la fin du téléchargement des données
	/// </summary>
	void downloaded();

private slots:
	/// <summary>
	/// Permet de lancer le téléchargement des données
	/// </summary>
	void fileDownloaded(QNetworkReply* pReply);

private:
	/// <summary>
	/// Contrôleur de téléchargement
	/// </summary>
	QNetworkAccessManager m_WebCtrl;

	/// <summary>
	/// Données téléchargées
	/// </summary>
	QByteArray m_DownloadedData;
};
