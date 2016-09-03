#ifndef WEBVIEWHANDLER_H
#define WEBVIEWHANDLER_H

#include <QDialog>
#include <QUrl>
#include <QBuffer>
#include <QPixmap>
#include <QTextBrowser>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

class WebViewHandler : public QObject
{
  Q_OBJECT
public:
  WebViewHandler();
  void setWebView(QTextBrowser *webViewIn, QString address);
  void loadPage(QUrl url);

public slots:
  void loadMainPage();
  void htmlReply();
  void imgReply();

private:
  QNetworkAccessManager netManager;
  QNetworkRequest req;
  QPixmap pmap;
  QTextBrowser *webView;
  QUrl mainUrl;
  QUrl url;
};

#endif // WEBVIEWHANDLER_H
