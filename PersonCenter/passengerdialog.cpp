#include "passengerdialog.h"
#include "ui_passengerdialog.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>

PassengerDialog::PassengerDialog(int userId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassengerDialog)
{
    ui->setupUi(this);
    setWindowTitle("常用乘机人管理");
    resize(800, 600);
    m_userId = userId;

    initDatabase();
    setupLayout();
    loadPassengerData();
}

PassengerDialog::~PassengerDialog()
{
    delete ui;
}

void PassengerDialog::initDatabase()
{
    m_db = QSqlDatabase::addDatabase("QODBC", "PassengerDialogConnection");
    m_db.setDatabaseName("flightmanagesystem;CHARSET=utf8mb4;UID=root;PWD=20241402Ywl@");
    m_db.setConnectOptions("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3;CHARSET=utf8mb4");

    if (!m_db.open())
    {
        QMessageBox::warning(this, "Error", "ODBC connect failed: " + m_db.lastError().text());
        return;
    }

    QSqlQuery query(m_db);
    query.exec("SET NAMES utf8mb4;");
    query.exec("SET CHARACTER_SET_RESULTS=utf8mb4;");
}

void PassengerDialog::setupLayout()
{
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(layout());
    if (!mainLayout)
    {
        mainLayout = new QVBoxLayout(this);
        setLayout(mainLayout);
    }

    mainLayout->setContentsMargins(15, 15, 15, 15);
    mainLayout->setSpacing(15);

    ui->passengerTable->setStyleSheet(R"(
        QTableWidget { background:#ffffff; border:1px solid #e0e0e0; border-radius:8px; padding:5px; gridline-color:#f0f0f0; }
        QHeaderView::section { background:#f8f9fa; font-weight:bold; color:#333333; padding:8px; border:none; border-bottom:1px solid #e0e0e0; }
        QTableWidget::item:even { background:#fcfcfc; }
        QTableWidget::item:odd { background:#f9f9f9; }
        QTableWidget::item:hover { background:#e6f7ff; }
        QTableWidget::item { padding:6px; color:#333333; }
    )");
    mainLayout->addWidget(ui->passengerTable);
    mainLayout->setStretchFactor(ui->passengerTable, 1);

    QWidget *btnWidget = new QWidget();
    QHBoxLayout *btnLayout = new QHBoxLayout(btnWidget);
    btnLayout->setSpacing(20);
    btnLayout->setAlignment(Qt::AlignCenter);

    ui->addBtn->setFixedSize(120, 36);
    ui->addBtn->setStyleSheet("QPushButton { background:#409EFF; color:white; border:none; border-radius:6px; font-size:14px; }"
                              "QPushButton:hover { background:#66b1ff; }"
                              "QPushButton:pressed { background:#3a8ee6; }");
    btnLayout->addWidget(ui->addBtn);

    ui->editBtn->setFixedSize(120, 36);
    ui->editBtn->setStyleSheet("QPushButton { background:#FF9F43; color:white; border:none; border-radius:6px; font-size:14px; }"
                               "QPushButton:hover { background:#ffb86c; }"
                               "QPushButton:pressed { background:#e68a00; }");
    btnLayout->addWidget(ui->editBtn);

    ui->deleteBtn->setFixedSize(120, 36);
    ui->deleteBtn->setStyleSheet("QPushButton { background:#FF4757; color:white; border:none; border-radius:6px; font-size:14px; }"
                                 "QPushButton:hover { background:#ff6b81; }"
                                 "QPushButton:pressed { background:#e03140; }");
    btnLayout->addWidget(ui->deleteBtn);

    mainLayout->addWidget(btnWidget);

    ui->passengerTable->setWordWrap(true);
    ui->passengerTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->passengerTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->passengerTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->passengerTable->setColumnWidth(1, 180);
    ui->passengerTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->passengerTable->setColumnWidth(2, 120);
    ui->passengerTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->passengerTable->setColumnWidth(3, 80);
    ui->passengerTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void PassengerDialog::loadPassengerData()
{
    ui->passengerTable->setRowCount(0);

    QSqlQuery createQuery(m_db);
    const QString createSql = "CREATE TABLE IF NOT EXISTS passenger ("
                              "id INT PRIMARY KEY AUTO_INCREMENT,"
                              "user_id INT NOT NULL,"
                              "name VARCHAR(50) NOT NULL,"
                              "id_card VARCHAR(20) NOT NULL UNIQUE,"
                              "phone VARCHAR(20) NOT NULL,"
                              "FOREIGN KEY (user_id) REFERENCES user(id)"
                              ") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci";
    if (!createQuery.exec(createSql))
    {
        QMessageBox::warning(this, "Error", "Table create failed: " + createQuery.lastError().text());
        return;
    }

    QSqlQuery query(m_db);
    const QString sql = "SELECT HEX(name) AS name_hex, id_card, phone FROM passenger WHERE user_id=?";
    query.prepare(sql);
    query.addBindValue(m_userId);

    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", "Query failed: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next())
    {
        ui->passengerTable->insertRow(row);

        const QString nameHex = query.value("name_hex").toString();
        const QByteArray nameBytes = QByteArray::fromHex(nameHex.toUtf8());
        const QString name = QString::fromUtf8(nameBytes);

        const QString idCard = query.value("id_card").toString();
        const QString phone = query.value("phone").toString();

        ui->passengerTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->passengerTable->setItem(row, 1, new QTableWidgetItem(idCard));
        ui->passengerTable->setItem(row, 2, new QTableWidgetItem(phone));
        ui->passengerTable->setItem(row, 3, new QTableWidgetItem("--"));

        row++;
    }

    if (row == 0)
    {
        ui->passengerTable->setRowCount(1);
        QTableWidgetItem *emptyItem = new QTableWidgetItem("暂无常用乘机人，点击「添加」按钮新增");
        emptyItem->setTextAlignment(Qt::AlignCenter);
        ui->passengerTable->setSpan(0, 0, 1, 4);
        ui->passengerTable->setItem(0, 0, emptyItem);
    }
}

void PassengerDialog::on_addBtn_clicked()
{
    QString name = QInputDialog::getText(this, "添加乘机人", "请输入姓名：");
    if (name.isEmpty()) return;

    QString idCard = QInputDialog::getText(this, "添加乘机人", "请输入身份证号：");
    if (idCard.isEmpty() || idCard.length() != 18)
    {
        QMessageBox::warning(this, "Error", "ID card must be 18 characters!");
        return;
    }

    QString phone = QInputDialog::getText(this, "添加乘机人", "请输入手机号：");
    if (phone.isEmpty() || phone.length() != 11)
    {
        QMessageBox::warning(this, "Error", "Phone number must be 11 characters!");
        return;
    }

    QSqlQuery query(m_db);
    const QString sql = "INSERT INTO passenger (user_id, name, id_card, phone) VALUES (?, UNHEX(?), ?, ?)";
    query.prepare(sql);
    query.addBindValue(m_userId);
    query.addBindValue(name.toUtf8().toHex());
    query.addBindValue(idCard);
    query.addBindValue(phone);

    if (query.exec())
    {
        QMessageBox::information(this, "Success", "Passenger added successfully!");
        loadPassengerData();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Add failed: " + query.lastError().text());
    }
}

void PassengerDialog::on_editBtn_clicked()
{
    QTableWidgetItem *selectedItem = ui->passengerTable->currentItem();
    if (!selectedItem)
    {
        QMessageBox::warning(this, "Tips", "Please select a passenger to edit!");
        return;
    }

    const int row = selectedItem->row();
    if (ui->passengerTable->item(row, 0)->text() == "暂无常用乘机人，点击「添加」按钮新增")
    {
        QMessageBox::warning(this, "Tips", "No passenger available for editing!");
        return;
    }

    const QString oldIdCard = ui->passengerTable->item(row, 1)->text();
    const QString oldName = ui->passengerTable->item(row, 0)->text();
    const QString oldPhone = ui->passengerTable->item(row, 2)->text();

    const QString newName = QInputDialog::getText(this, "修改乘机人", "Enter new name：", QLineEdit::Normal, oldName);
    const QString newPhone = QInputDialog::getText(this, "修改乘机人", "Enter new phone：", QLineEdit::Normal, oldPhone);

    if (newName.isEmpty() || newPhone.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name and phone cannot be empty!");
        return;
    }

    QSqlQuery query(m_db);
    const QString sql = "UPDATE passenger SET name=UNHEX(?), phone=? WHERE id_card=? AND user_id=?";
    query.prepare(sql);
    query.addBindValue(newName.toUtf8().toHex());
    query.addBindValue(newPhone);
    query.addBindValue(oldIdCard);
    query.addBindValue(m_userId);

    if (query.exec())
    {
        QMessageBox::information(this, "Success", "Passenger updated successfully!");
        loadPassengerData();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Update failed: " + query.lastError().text());
    }
}

void PassengerDialog::on_deleteBtn_clicked()
{
    QTableWidgetItem *selectedItem = ui->passengerTable->currentItem();
    if (!selectedItem)
    {
        QMessageBox::warning(this, "Tips", "Please select a passenger to delete!");
        return;
    }

    const int row = selectedItem->row();
    if (ui->passengerTable->item(row, 0)->text() == "暂无常用乘机人，点击「添加」按钮新增")
    {
        QMessageBox::warning(this, "Tips", "No passenger available for deletion!");
        return;
    }

    const QString idCard = ui->passengerTable->item(row, 1)->text();
    const QString name = ui->passengerTable->item(row, 0)->text();

    if (QMessageBox::question(this, "Confirm", "Delete passenger " + name + "?") != QMessageBox::Yes)
    {
        return;
    }

    QSqlQuery query(m_db);
    const QString sql = "DELETE FROM passenger WHERE id_card=? AND user_id=?";
    query.prepare(sql);
    query.addBindValue(idCard);
    query.addBindValue(m_userId);

    if (query.exec())
    {
        QMessageBox::information(this, "Success", "Passenger deleted successfully!");
        ui->passengerTable->removeRow(row);
        if (ui->passengerTable->rowCount() == 0) loadPassengerData();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Delete failed: " + query.lastError().text());
    }
}
