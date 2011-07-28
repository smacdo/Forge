#ifndef FORGE_LOGIN_WINDOW_H
#define FORGE_LOGIN_WINDOW_H

#include <QDialog>
#include <QHostAddress>

class QLabel;
class QLineEdit;
class QPushButton;
class QWidget;

class LoginWindow : public QDialog
{
    Q_OBJECT;

public:
    LoginWindow( QWidget *parent = 0 );

    bool wasRegisterRequested() const;
    QString username() const;
    QString password() const;
    QHostAddress server() const;

private slots:
    void login();
    void newaccount();

private:
    QLabel *m_usernameLabel;
    QLabel *m_passwordLabel;
    QLabel *m_serverLabel;
    QLineEdit *m_username;
    QLineEdit *m_password;
    QLineEdit *m_server;
    QPushButton *m_loginButton;
    QPushButton *m_registerButton;

    bool m_registerRequested;
    QHostAddress m_serverAddress;
};

#endif
