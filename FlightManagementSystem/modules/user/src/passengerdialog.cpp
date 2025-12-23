#include "passengerdialog.h"
#include "ui_passengerdialog.h"
#include "databasemanager.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QSqlError>

PassengerDialog::PassengerDialog(int userId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PassengerDialog)
    , m_userId(userId)
    , m_isBuyTicketMode(false)
{
    initialize();
}

PassengerDialog::PassengerDialog(int userId, bool isBuyTicketMode, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PassengerDialog)
    , m_userId(userId)
    , m_isBuyTicketMode(isBuyTicketMode)
{
    initialize();
}

PassengerDialog::~PassengerDialog()
{
    delete ui;
}

void PassengerDialog::initialize()
{
    ui->setupUi(this);

    if (m_isBuyTicketMode) {
        setWindowTitle("选择乘机人（购票模式）");
    } else {
        setWindowTitle("常用乘机人管理");
    }

    resize(950, 600);

    setupLayout();
    loadPassengerData();
}

void PassengerDialog::setupLayout()
{
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(layout());
    if (!mainLayout) {
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
    btnLayout->setSpacing(15);
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
    updateButtonStyle();
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

void PassengerDialog::updateButtonStyle()
{
    if (m_isBuyTicketMode) {
        ui->deleteBtn->setText("支付");
        ui->deleteBtn->setStyleSheet("QPushButton { background:green; color:white; border:none; border-radius:6px; font-size:14px; font-weight:bold; }"
                                     "QPushButton:hover { background:rgb(0, 200, 0); }"
                                     "QPushButton:pressed { background:rgb(0, 180, 0); }");
    } else {
        ui->deleteBtn->setText("删除");
        ui->deleteBtn->setStyleSheet("QPushButton { background:#FF4757; color:white; border:none; border-radius:6px; font-size:14px; }"
                                     "QPushButton:hover { background:#ff6b81; }"
                                     "QPushButton:pressed { background:#e03140; }");
    }
}

void PassengerDialog::loadPassengerData()
{
    ui->passengerTable->setRowCount(0);
    m_rowSelectBtnMap.clear();
    m_rowSelectedMap.clear();

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    // 直接查询现有的passenger表
    QSqlQuery query(db);
    const QString sql = "SELECT name, id_card, phone FROM passenger WHERE user_id=?";
    query.prepare(sql);
    query.addBindValue(m_userId);

    if (!query.exec()) {
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->passengerTable->insertRow(row);

        const QString name = query.value("name").toString();

        const QString idCard = query.value("id_card").toString();
        const QString phone = query.value("phone").toString();

        ui->passengerTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->passengerTable->setItem(row, 1, new QTableWidgetItem(idCard));
        ui->passengerTable->setItem(row, 2, new QTableWidgetItem(phone));

        if (m_isBuyTicketMode) {
            QPushButton *selectBtn = createSelectButton(row);
            ui->passengerTable->setCellWidget(row, 3, selectBtn);
            m_rowSelectBtnMap[row] = selectBtn;
            m_rowSelectedMap[row] = false;
        } else {
            QTableWidgetItem *manageItem = new QTableWidgetItem("管理");
            manageItem->setTextAlignment(Qt::AlignCenter);
            ui->passengerTable->setItem(row, 3, manageItem);
        }

        row++;
    }

    if (row == 0) {
        ui->passengerTable->setRowCount(1);
        QString emptyTip = m_isBuyTicketMode ? "暂无乘机人，点击「添加」按钮新增" : "暂无常用乘机人，点击「添加」按钮新增";
        QTableWidgetItem *emptyItem = new QTableWidgetItem(emptyTip);
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
    if (idCard.isEmpty() || idCard.length() != 18) {
        QMessageBox::warning(this, "错误", "身份证号必须为18位！");
        return;
    }

    QString phone = QInputDialog::getText(this, "添加乘机人", "请输入手机号：");
    if (phone.isEmpty() || phone.length() != 11) {
        QMessageBox::warning(this, "错误", "手机号必须为11位！");
        return;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QSqlQuery query(db);
    const QString sql = "INSERT INTO passenger (user_id, name, id_card, phone) VALUES (?, ?, ?, ?)";
    query.prepare(sql);
    query.addBindValue(m_userId);
    query.addBindValue(name);
    query.addBindValue(idCard);
    query.addBindValue(phone);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "乘机人添加成功！");
        loadPassengerData();
        emit dataChanged();
    } else {
        QMessageBox::warning(this, "错误", "添加失败：" + query.lastError().text());
    }
}

void PassengerDialog::on_editBtn_clicked()
{
    QTableWidgetItem *selectedItem = ui->passengerTable->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "提示", "请选择要编辑的乘机人！");
        return;
    }

    const int row = selectedItem->row();
    if (ui->passengerTable->item(row, 0)->text().contains("暂无")) {
        QMessageBox::warning(this, "提示", "没有可编辑的乘机人！");
        return;
    }

    const QString oldIdCard = ui->passengerTable->item(row, 1)->text();
    const QString oldName = ui->passengerTable->item(row, 0)->text();
    const QString oldPhone = ui->passengerTable->item(row, 2)->text();

    const QString newName = QInputDialog::getText(this, "修改乘机人", "请输入新姓名：", QLineEdit::Normal, oldName);
    const QString newPhone = QInputDialog::getText(this, "修改乘机人", "请输入新手机号：", QLineEdit::Normal, oldPhone);

    if (newName.isEmpty() || newPhone.isEmpty()) {
        QMessageBox::warning(this, "错误", "姓名和手机号不能为空！");
        return;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QSqlQuery query(db);
    const QString sql = "UPDATE passenger SET name=UNHEX(?), phone=? WHERE id_card=? AND user_id=?";
    query.prepare(sql);
    query.addBindValue(newName.toUtf8().toHex());
    query.addBindValue(newPhone);
    query.addBindValue(oldIdCard);
    query.addBindValue(m_userId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "乘机人修改成功！");
        loadPassengerData();
        emit dataChanged();
    } else {
        QMessageBox::warning(this, "错误", "修改失败：" + query.lastError().text());
    }
}

void PassengerDialog::on_deleteBtn_clicked()
{
    if (m_isBuyTicketMode) {
        QList<PassengerInfo> selectedPassengers = getAllSelectedPassengers();

        if (selectedPassengers.isEmpty()) {
            QMessageBox::warning(this, "提示", "请先选择乘机人再进行支付！");
            return;
        }

        QString paymentInfo = "🎉 支付完成！\n\n";
        for (int i = 0; i < selectedPassengers.size(); i++) {
            const PassengerInfo &info = selectedPassengers[i];
            paymentInfo += QString("乘机人%1：%2\n身份证号：%3\n\n")
                               .arg(i + 1)
                               .arg(info.name)
                               .arg(info.idCard);
        }
        paymentInfo += "状态：虚拟支付成功（无需实际付款）";

        QMessageBox::information(
            this,
            "支付成功",
            paymentInfo,
            QMessageBox::Ok
            );

        for (const PassengerInfo &info : selectedPassengers) {
            emit paymentCompleted(info);
        }
        accept();
        return;
    }

    QTableWidgetItem *selectedItem = ui->passengerTable->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "提示", "请选择要删除的乘机人！");
        return;
    }

    const int row = selectedItem->row();
    if (ui->passengerTable->item(row, 0)->text().contains("暂无")) {
        QMessageBox::warning(this, "提示", "没有可删除的乘机人！");
        return;
    }

    const QString idCard = ui->passengerTable->item(row, 1)->text();
    const QString name = ui->passengerTable->item(row, 0)->text();

    if (QMessageBox::question(this, "确认", "确定要删除乘机人 " + name + " 吗？") != QMessageBox::Yes) {
        return;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接无效");
        return;
    }

    QSqlQuery query(db);
    const QString sql = "DELETE FROM passenger WHERE id_card=? AND user_id=?";
    query.prepare(sql);
    query.addBindValue(idCard);
    query.addBindValue(m_userId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "乘机人删除成功！");
        ui->passengerTable->removeRow(row);
        if (ui->passengerTable->rowCount() == 0) loadPassengerData();
        emit dataChanged();
    } else {
        QMessageBox::warning(this, "错误", "删除失败：" + query.lastError().text());
    }
}

void PassengerDialog::setMode(bool isBuyTicketMode)
{
    m_isBuyTicketMode = isBuyTicketMode;

    if (m_isBuyTicketMode) {
        setWindowTitle("选择乘机人（购票模式）");
    } else {
        setWindowTitle("常用乘机人管理");
    }

    updateButtonStyle();
    loadPassengerData();
}

void PassengerDialog::setDatabaseConnection(const QString &connectionName)
{
    m_connectionName = connectionName;
}

void PassengerDialog::refreshData()
{
    loadPassengerData();
}

PassengerInfo PassengerDialog::getSelectedPassenger() const
{
    PassengerInfo info;

    for (auto it = m_rowSelectedMap.constBegin(); it != m_rowSelectedMap.constEnd(); ++it) {
        if (it.value()) {
            return getPassengerAtRow(it.key());
        }
    }

    return info;
}

QList<PassengerInfo> PassengerDialog::getAllSelectedPassengers() const
{
    QList<PassengerInfo> passengers;

    for (auto it = m_rowSelectedMap.constBegin(); it != m_rowSelectedMap.constEnd(); ++it) {
        if (it.value()) {
            passengers.append(getPassengerAtRow(it.key()));
        }
    }

    return passengers;
}

PassengerInfo PassengerDialog::getPassengerAtRow(int row) const
{
    PassengerInfo info;

    if (row < 0 || row >= ui->passengerTable->rowCount()) {
        return info;
    }

    QTableWidgetItem *nameItem = ui->passengerTable->item(row, 0);
    QTableWidgetItem *idItem = ui->passengerTable->item(row, 1);
    QTableWidgetItem *phoneItem = ui->passengerTable->item(row, 2);

    if (nameItem && idItem && phoneItem) {
        info.name = nameItem->text();
        info.idCard = idItem->text();
        info.phone = phoneItem->text();
        info.isValid = m_rowSelectedMap.value(row, false);
    }

    return info;
}

QPushButton* PassengerDialog::createSelectButton(int row)
{
    QPushButton *btn = new QPushButton("选择", this);
    btn->setStyleSheet("QPushButton { background:#4CAF50; color:white; border:none; border-radius:4px; padding:4px 8px; font-size:12px; }"
                       "QPushButton:hover { background:#45a049; }");
    btn->setFixedSize(60, 24);
    btn->setProperty("row", row);
    connect(btn, &QPushButton::clicked, this, &PassengerDialog::on_selectBtn_clicked);
    return btn;
}

void PassengerDialog::on_selectBtn_clicked()
{
    QPushButton *senderBtn = qobject_cast<QPushButton*>(sender());
    if (!senderBtn) return;

    int row = senderBtn->property("row").toInt();
    if (row < 0 || row >= ui->passengerTable->rowCount()) return;

    bool isSelected = !m_rowSelectedMap.value(row, false);
    m_rowSelectedMap[row] = isSelected;

    if (isSelected) {
        senderBtn->setText("取消选择");
        senderBtn->setStyleSheet("QPushButton { background:#f44336; color:white; border:none; border-radius:4px; padding:4px 8px; font-size:12px; }"
                                 "QPushButton:hover { background:#d32f2f; }");
    } else {
        senderBtn->setText("选择");
        senderBtn->setStyleSheet("QPushButton { background:#4CAF50; color:white; border:none; border-radius:4px; padding:4px 8px; font-size:12px; }"
                                 "QPushButton:hover { background:#45a049; }");
    }

    PassengerInfo info = getPassengerAtRow(row);
    info.isValid = isSelected;
    emit passengerSelected(info);
}

QList<PassengerInfo> PassengerDialog::getAllPassengers(int userId, const QString &connectionName)
{
    QList<PassengerInfo> passengers;

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        return passengers;
    }

    QSqlQuery query(db);
    const QString sql = "SELECT name, id_card, phone FROM passenger WHERE user_id=?";
    query.prepare(sql);
    query.addBindValue(userId);

    if (!query.exec()) {
        return passengers;
    }

    while (query.next()) {
        PassengerInfo info;
        info.name = query.value("name").toString();
        info.idCard = query.value("id_card").toString();
        info.phone = query.value("phone").toString();
        passengers.append(info);
    }

    return passengers;
}

bool PassengerDialog::addPassenger(int userId, const PassengerInfo &info, const QString &connectionName)
{
    if (info.name.isEmpty() || info.idCard.isEmpty() || info.phone.isEmpty()) {
        return false;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        return false;
    }

    // 直接插入到现有的passenger表
    QSqlQuery query(db);
    const QString sql = "INSERT INTO passenger (user_id, name, id_card, phone) VALUES (?, ?, ?, ?)";
    query.prepare(sql);
    query.addBindValue(userId);
    query.addBindValue(info.name);
    query.addBindValue(info.idCard);
    query.addBindValue(info.phone);

    return query.exec();
}

bool PassengerDialog::deletePassenger(int userId, const QString &idCard, const QString &connectionName)
{
    if (idCard.isEmpty()) {
        return false;
    }

    // 获取数据库连接
    DatabaseManager* dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager->getDatabase();
    
    if (!db.isValid()) {
        return false;
    }

    QSqlQuery query(db);
    const QString sql = "DELETE FROM passenger WHERE id_card=? AND user_id=?";
    query.prepare(sql);
    query.addBindValue(idCard);
    query.addBindValue(userId);

    return query.exec();
}

PassengerInfo PassengerDialog::selectPassenger(int userId, QWidget *parent)
{
    PassengerDialog dialog(userId, true, parent);

    PassengerInfo selectedInfo;

    QObject::connect(&dialog, &PassengerDialog::passengerSelected, [&](const PassengerInfo &info) {
        if (info.isValid) {
            selectedInfo = info;
        }
    });

    dialog.exec();

    return selectedInfo;
}