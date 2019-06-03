#ifndef QUAMODBUSCLIENTWIDGET_H
#define QUAMODBUSCLIENTWIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

namespace Ui {
class QUaModbusClientWidget;
}

class QUaModbusClient;
class QUaModbusClientList;
class QUaModbusClientDialog;
class QUaModbusDataBlock;

class QUaModbusClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QUaModbusClientWidget(QWidget *parent = nullptr);
    ~QUaModbusClientWidget();

	QUaModbusClientList * clientList() const;
	void setClientList(QUaModbusClientList * listClients);

	// tree headers
	enum class Headers
	{
		Objects = 0, 
		Status  = 1,
		Actions = 2,
		Invalid = 3
	};
	Q_ENUM(Headers)

private slots:
    void on_pushButtonAddClient_clicked();

private:
    Ui::QUaModbusClientWidget *ui;
	QUaModbusClientList * m_listClients;
	QStandardItemModel    m_modelClients;
	QSortFilterProxyModel m_proxyClients;

	void showNewClientDialog(QUaModbusClientDialog &dialog);
	void handleClientAdded  (QUaModbusClient * client);
	void showNewBlockDialog (QUaModbusClient * client, QUaModbusClientDialog &dialog);
	void handleBlockAdded   (QUaModbusClient * client, QStandardItem * parent, const QString &strBlockId);
	void showNewValueDialog (QUaModbusDataBlock * block, QUaModbusClientDialog &dialog);
	void handleValueAdded   (QUaModbusDataBlock * block, QStandardItem * parent, const QString &strValueId);
};

#endif // QUAMODBUSCLIENTWIDGET_H