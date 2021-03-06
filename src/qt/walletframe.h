// Copyright (c) 2011-2013 The Bitcredit Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCREDIT_QT_WALLETFRAME_H
#define BITCREDIT_QT_WALLETFRAME_H

#include <QFrame>
#include <QMap>

class BitcreditGUI;
class ClientModel;
class SendCoinsRecipient;
class WalletModel;
class WalletView;
class BlockBrowser;
class BankStatisticsPage;
class BanknodeManager;
QT_BEGIN_NAMESPACE
class QStackedWidget;
QT_END_NAMESPACE

class WalletFrame : public QFrame
{
    Q_OBJECT

public:
    explicit WalletFrame(BitcreditGUI *_gui = 0);
    ~WalletFrame();

    void setClientModel(ClientModel *clientModel);

    bool addWallet(const QString& name, WalletModel *walletModel);
    bool setCurrentWallet(const QString& name);
    bool removeWallet(const QString &name);
    void removeAllWallets();

    bool handlePaymentRequest(const SendCoinsRecipient& recipient);

    void showOutOfSyncWarning(bool fShow);

private:
    QStackedWidget *walletStack;
    BitcreditGUI *gui;
    ClientModel *clientModel;
    QMap<QString, WalletView*> mapWalletViews;

    bool bOutOfSync;

    WalletView *currentWalletView();

public slots:
    /** Switch to overview (home) page */
    void gotoOverviewPage();
    /** Switch to history (transactions) page */
    void gotoHistoryPage();
	/** Switch to chat page */
    void gotoChatPage();
	/** Switch to exchange browser page */
    void gotoExchangeBrowserPage();	
    /** Switch to receive coins page */
    void gotoReceiveCoinsPage();
    /** Switch to send coins page */
    void gotoSendCoinsPage(QString addr = "");
    /** Switch to send coins page */
    void gotoTestPage();
    /** Show Sign/Verify Message dialog and switch to sign message tab */
    void gotoSignMessageTab(QString addr = "");
    /** Show Sign/Verify Message dialog and switch to verify message tab */
    void gotoVerifyMessageTab(QString addr = "");
	void gotoBlockBrowser();
	void gotoBankStatisticsPage();
	void gotoSendMessagesPage();
    /** Switch to send anonymous messages page */
    /** Switch to view messages page */
    void gotoMessagesPage();
    /** Switch to invoices page */
    void gotoInvoicesPage();
    /** Switch to receipt page */
    void gotoReceiptPage();
    /** Encrypt the wallet */
    void encryptWallet(bool status);
    /** Backup the wallet */
    void backupWallet();
    /** Change encrypted wallet passphrase */
    void changePassphrase();
    void gotoBanknodeManagerPage();
    /** Ask for passphrase to unlock wallet temporarily */
    void unlockWallet();
	void printPaperWallets();
    /** Show used sending addresses */
    void usedSendingAddresses();
    /** Show used receiving addresses */
    void usedReceivingAddresses();
};

#endif // BITCREDIT_QT_WALLETFRAME_H
