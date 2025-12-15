-- MySQL dump 10.13  Distrib 8.0.44, for Win64 (x86_64)
--
-- Host: localhost    Database: flightmanagesystem
-- ------------------------------------------------------
-- Server version	8.0.44

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `message`
--

DROP TABLE IF EXISTS `message`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `message` (
  `id` int NOT NULL AUTO_INCREMENT,
  `user_id` int NOT NULL,
  `title` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '??Ϣ???',
  `content` text COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '??Ϣ???',
  `create_time` datetime DEFAULT CURRENT_TIMESTAMP COMMENT '????ʱ?',
  `is_read` tinyint DEFAULT '0' COMMENT '0=δ????1=?Ѷ?',
  PRIMARY KEY (`id`),
  KEY `fk_message_user` (`user_id`),
  CONSTRAINT `fk_message_user` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `message`
--

LOCK TABLES `message` WRITE;
/*!40000 ALTER TABLE `message` DISABLE KEYS */;
INSERT INTO `message` VALUES (11,1,'订单支付成功通知','您预订的【2025-12-10 北京→上海】MU5101 航班已支付成功，订单号：OD20251201001，请提前2小时到机场办理登机手续。','2025-12-01 09:23:45',1),(12,1,'航班动态变更提醒','您乘坐的【2025-12-10 北京→上海】MU5101 航班起飞时间调整为 14:30（原15:00），请留意时间变化，给您带来不便敬请谅解。','2025-12-01 11:05:22',1),(13,1,'会员积分到账通知','您的航班出行已累计 800 会员积分，当前总积分 5600 分，可兑换机票、贵宾室服务等，详情请登录APP查看。','2025-11-30 16:48:10',1),(14,1,'系统安全提醒','您的账户于 2025-11-29 20:15 在新设备登录，若不是本人操作，请及时修改密码并联系客服。','2025-11-29 20:18:03',1),(15,1,'订单取消成功通知','您提交的【2025-12-15 广州→深圳】CZ3102 航班订单（OD20251128003）已取消，退款将在 1-3 个工作日原路退回您的支付账户。','2025-11-28 14:32:56',1),(16,1,'活动推广通知','双12航班特惠活动开启！全场机票8折起，叠加优惠券最高立减300元，活动时间：2025-12-01 至 2025-12-12，速来抢购～','2025-12-01 00:05:18',0),(17,1,'登机牌电子凭证提醒','您的【2025-12-05 深圳→成都】3U8632 航班登机牌已生成，可登录APP查看电子登机牌，无需打印纸质版。','2025-12-02 10:12:33',0),(18,1,'行李额不足提醒','您预订的【2025-12-08 上海→三亚】HO1256 航班经济舱免费行李额为 20kg，您当前已勾选 25kg，需补缴超重费 150 元，请在起飞前完成支付。','2025-11-27 18:09:44',1),(19,1,'航班延误通知','受航路天气影响，您乘坐的【2025-12-08 上海→三亚】HO1256 航班预计延误 1 小时，最新起飞时间 16:00，具体以机场广播为准。','2025-12-08 13:30:21',0);
/*!40000 ALTER TABLE `message` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `order`
--

DROP TABLE IF EXISTS `order`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `order` (
  `order_id` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '订单号（主键）',
  `flight_num` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '航班号',
  `depart_time` datetime NOT NULL COMMENT '出发时间',
  `destination` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '目的地',
  `status` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '订单状态（待出行/已完成/已取消）',
  `user_id` int NOT NULL COMMENT '关联的用户ID',
  PRIMARY KEY (`order_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `order`
--

LOCK TABLES `order` WRITE;
/*!40000 ALTER TABLE `order` DISABLE KEYS */;
INSERT INTO `order` VALUES ('ORD2025001','CA1234','2025-12-10 08:30:00','北京','已取消',1),('ORD2025002','MU5678','2025-12-15 14:20:00','上海','已完成',1),('ORD2025003','CZ9012','2025-12-20 09:10:00','广州','已取消',1);
/*!40000 ALTER TABLE `order` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `passenger`
--

DROP TABLE IF EXISTS `passenger`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `passenger` (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '乘机人ID（自增主键）',
  `user_id` int NOT NULL COMMENT '关联的用户ID（和user表的id对应）',
  `name` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '乘机人姓名',
  `id_card` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '身份证号（唯一，不重复）',
  `phone` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '手机号',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_card` (`id_card`),
  KEY `fk_passenger_user` (`user_id`),
  CONSTRAINT `fk_passenger_user` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='常用乘机人表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `passenger`
--

LOCK TABLES `passenger` WRITE;
/*!40000 ALTER TABLE `passenger` DISABLE KEYS */;
INSERT INTO `passenger` VALUES (2,1,'杨文玲','440883200609162927','17875904308'),(3,1,'孙雪岑','340504200602280626','12345678908'),(4,1,'朱曼怡','440882200609162927','13656288056');
/*!40000 ALTER TABLE `passenger` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `points`
--

DROP TABLE IF EXISTS `points`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `points` (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '积分记录ID',
  `user_id` int NOT NULL COMMENT '关联用户ID（和user表id对应）',
  `points_num` int NOT NULL COMMENT '积分数量（正数=增加，负数=扣除）',
  `points_type` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '积分类型（比如：订单兑换、注册赠送、活动奖励）',
  `create_time` datetime DEFAULT CURRENT_TIMESTAMP COMMENT '积分获取/扣除时间',
  PRIMARY KEY (`id`),
  KEY `fk_points_user` (`user_id`),
  CONSTRAINT `fk_points_user` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='用户积分明细表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `points`
--

LOCK TABLES `points` WRITE;
/*!40000 ALTER TABLE `points` DISABLE KEYS */;
INSERT INTO `points` VALUES (1,1,100,'注册赠送','2025-01-15 10:30:00'),(2,1,50,'订单兑换','2025-02-20 14:15:00'),(3,1,-30,'积分兑换优惠券','2025-03-05 09:40:00'),(4,1,200,'活动奖励','2025-04-10 16:20:00'),(5,1,250,'活动奖励','2025-05-10 16:30:00'),(6,1,250,'活动奖励','2025-05-10 16:30:00');
/*!40000 ALTER TABLE `points` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '用户ID（自增主键）',
  `username` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '用户名',
  `password` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '密码',
  `nickname` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT '' COMMENT '用户昵称',
  `phone` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT '' COMMENT '手机号',
  `email` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT '' COMMENT '邮箱',
  `create_time` datetime DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='用户表';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'test_user','123456','朱曼怡','13800138000','test@example.com','2025-12-08 17:29:35'),(2,'newuser','123456','新用户','13900139000','newuser@example.com','2025-12-08 17:30:00');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-12-14 19:41:41
