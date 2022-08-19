#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>

class DownLoadManager : public QObject
{
	Q_OBJECT

public:
	DownLoadManager(QObject *parent = 0);
	~DownLoadManager();

	void downloadFile(QString url);
	void setDownInto(bool isSupportBreakPoint);
	void stopDownload();
	void closeDownload();
	QString getDownloadUrl();
	void reset();
private:	
	void stopWork();
	void removeFile(QString fileName);
	std::unique_ptr<QFile> openFileForWrite(const QString& fileName);

signals:
	void signalDownloadProcess(qint64, qint64);
	void signalReplyFinished(int);
	void signalDownloadError();
private slots:
	void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
	void onReadyRead();
	void onFinished();
	void onError(QNetworkReply::NetworkError code);
private:
	QNetworkAccessManager* m_networkManager;
	QNetworkReply* m_reply;
	QUrl m_url;
	QString m_fileName;
	std::unique_ptr<QFile> m_file = nullptr;

	bool m_isSupportBreakPoint;
	qint64 m_bytesCurrentReceived;			//当前已下载字节数
	bool m_isStop;
};

#endif // DOWNLOADMANAGER_H
