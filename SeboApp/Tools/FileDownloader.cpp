#include "FileDownloader.h"

FileDownloader::FileDownloader(QUrl imageUrl, QObject *parent)
	: QObject(parent)
{
	// Connexion au signal de fin de téléchargement
	connect(&m_WebCtrl, SIGNAL(finished(QNetworkReply*)), this, SLOT(fileDownloaded(QNetworkReply*)));

	// Lancement du téléchargement
	QNetworkRequest request(imageUrl);
	m_WebCtrl.get(request);
}

FileDownloader::~FileDownloader()
{
}

void FileDownloader::fileDownloaded(QNetworkReply* pReply)
{
	// Enregistrement des infos téléchargées
	m_DownloadedData = pReply->readAll();
	pReply->deleteLater();

	// Émission du signal de fin de téléchargement
	emit downloaded();
}

QByteArray FileDownloader::downloadedData() const
{
	// retour des données téléchargées
	return m_DownloadedData;
}