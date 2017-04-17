#include "FileDownloader.h"

FileDownloader::FileDownloader(QUrl imageUrl, QObject *parent)
	: QObject(parent)
{
	// Connexion au signal de fin de t�l�chargement
	connect(&m_WebCtrl, SIGNAL(finished(QNetworkReply*)), this, SLOT(fileDownloaded(QNetworkReply*)));

	// Lancement du t�l�chargement
	QNetworkRequest request(imageUrl);
	m_WebCtrl.get(request);
}

FileDownloader::~FileDownloader()
{
}

void FileDownloader::fileDownloaded(QNetworkReply* pReply)
{
	// Enregistrement des infos t�l�charg�es
	m_DownloadedData = pReply->readAll();
	pReply->deleteLater();

	// �mission du signal de fin de t�l�chargement
	emit downloaded();
}

QByteArray FileDownloader::downloadedData() const
{
	// retour des donn�es t�l�charg�es
	return m_DownloadedData;
}