-- 数据库修复脚本
-- 用于统一 flight_management_system 数据库结构

USE flight_management_system;

-- 确保 user 表存在且结构正确
CREATE TABLE IF NOT EXISTS `user` (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '用户ID（自增主键）',
  `username` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '用户名',
  `password` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '密码',
  `phone` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL COMMENT '手机号',
  `email` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL COMMENT '邮箱',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='用户表';

-- 如果表已存在，添加缺失的列
ALTER TABLE `user` 
ADD COLUMN IF NOT EXISTS `phone` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL COMMENT '手机号' AFTER `password`,
ADD COLUMN IF NOT EXISTS `email` varchar(100) COLLATE utf8mb4_unicode_ci DEFAULT NULL COMMENT '邮箱' AFTER `phone`;

-- 确保 admin_info 表存在且结构正确
CREATE TABLE IF NOT EXISTS `admin_info` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL COMMENT '管理员账号',
  `password` varchar(50) NOT NULL COMMENT '管理员密码',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='管理员信息表';

-- 确保 passenger 表存在且结构正确
CREATE TABLE IF NOT EXISTS `passenger` (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '乘机人ID（自增主键）',
  `user_id` int NOT NULL COMMENT '关联的用户ID（和user表的id对应）',
  `name` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '乘机人姓名',
  `id_card` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '身份证号（唯一，不重复）',
  `phone` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '手机号',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_card` (`id_card`),
  KEY `user_id` (`user_id`),
  CONSTRAINT `passenger_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='常用乘机人表';

-- 确保 points 表存在且结构正确
CREATE TABLE IF NOT EXISTS `points` (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '积分记录ID',
  `user_id` int NOT NULL COMMENT '关联用户ID（和user表id对应）',
  `points_num` int NOT NULL COMMENT '积分数量（正数=增加，负数=扣除）',
  `points_type` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '积分类型（比如：订单兑换、注册赠送、活动奖励）',
  `create_time` datetime DEFAULT CURRENT_TIMESTAMP COMMENT '积分获取/扣除时间',
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`),
  CONSTRAINT `points_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='用户积分明细表';

-- 确保 order 表存在且结构正确
CREATE TABLE IF NOT EXISTS `order` (
  `order_id` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '订单号（主键）',
  `flight_num` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '航班号',
  `depart_time` datetime NOT NULL COMMENT '出发时间',
  `destination` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '目的地',
  `status` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '订单状态（待出行/已完成/已取消）',
  `user_id` int NOT NULL COMMENT '关联的用户ID',
  PRIMARY KEY (`order_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- 确保 coupon 表存在且结构正确
CREATE TABLE IF NOT EXISTS `coupon` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '优惠券ID',
  `user_id` int(11) NOT NULL COMMENT '所属用户ID',
  `title` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT '优惠券标题',
  `discount` decimal(10,2) NOT NULL COMMENT '优惠金额',
  `min_amount` decimal(10,2) NOT NULL DEFAULT '0.00' COMMENT '使用门槛（0=无门槛）',
  `start_time` datetime NOT NULL COMMENT '生效时间',
  `end_time` datetime NOT NULL COMMENT '过期时间',
  `is_used` tinyint(4) DEFAULT '0' COMMENT '是否已使用：0=未使用，1=已使用',
  `used_time` datetime DEFAULT NULL COMMENT '使用时间',
  PRIMARY KEY (`id`),
  KEY `idx_user_id` (`user_id`),
  KEY `idx_is_used` (`is_used`),
  KEY `idx_end_time` (`end_time`),
  CONSTRAINT `coupon_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='优惠券表';

-- 插入默认管理员账号（如果不存在）
INSERT IGNORE INTO admin_info (username, password) VALUES 
('admin', 'admin123'),
('operator', 'operator123');

-- 插入测试用户（如果不存在）
INSERT IGNORE INTO user (username, password) VALUES 
('test_user', '123456');

-- 为测试用户添加一些积分记录（如果不存在）
INSERT IGNORE INTO points (user_id, points_num, points_type, create_time) VALUES 
(1, 100, '注册赠送', '2025-01-15 10:30:00'),
(1, 50, '订单兑换', '2025-02-20 14:15:00'),
(1, -30, '积分兑换优惠券', '2025-03-05 09:40:00'),
(1, 200, '活动奖励', '2025-04-10 16:20:00');

-- 为测试用户添加一些订单记录（如果不存在）
INSERT IGNORE INTO `order` (order_id, flight_num, depart_time, destination, status, user_id) VALUES 
('ORD2025001', 'CA1234', '2025-12-10 08:30:00', '北京', '已取消', 1),
('ORD2025002', 'MU5678', '2025-12-15 14:20:00', '上海', '已完成', 1),
('ORD2025003', 'CZ9012', '2025-12-20 09:10:00', '广州', '待出行', 1);

-- 为测试用户添加优惠券（如果不存在）
INSERT IGNORE INTO coupon (user_id, title, discount, min_amount, start_time, end_time, is_used) VALUES 
(1, '新用户专享券', 50.00, 500.00, '2024-12-01 00:00:00', '2024-12-31 23:59:59', 0),
(1, '满1000减100', 100.00, 1000.00, '2024-12-01 00:00:00', '2024-12-31 23:59:59', 0);

COMMIT;