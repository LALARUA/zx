/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50720
Source Host           : localhost:3306
Source Database       : 来换网

Target Server Type    : MYSQL
Target Server Version : 50720
File Encoding         : 65001

Date: 2017-11-23 18:25:58
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `公告`
-- ----------------------------
DROP TABLE IF EXISTS `公告`;
CREATE TABLE `公告` (
  `公告ID` int(20) NOT NULL AUTO_INCREMENT,
  `管理员名` varchar(20) DEFAULT NULL,
  `公告内容` varchar(100) DEFAULT NULL,
  `公告标题` varchar(20) DEFAULT NULL,
  `发布时间` datetime DEFAULT NULL,
  PRIMARY KEY (`公告ID`),
  KEY `管理员名` (`管理员名`),
  CONSTRAINT `管理员名` FOREIGN KEY (`管理员名`) REFERENCES `管理员` (`管理员名`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of 公告
-- ----------------------------

-- ----------------------------
-- Table structure for `商品`
-- ----------------------------
DROP TABLE IF EXISTS `商品`;
CREATE TABLE `商品` (
  `商品ID` int(20) NOT NULL AUTO_INCREMENT,
  `商品名` varchar(20) DEFAULT NULL,
  `商品类别` varchar(20) DEFAULT NULL,
  `想换商品类别` varchar(20) DEFAULT NULL,
  `图片文件` varchar(20) DEFAULT NULL,
  `用户名` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`商品ID`),
  KEY `用户名` (`用户名`),
  KEY `商品名` (`商品名`),
  CONSTRAINT `用户名` FOREIGN KEY (`用户名`) REFERENCES `用户` (`用户名`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of 商品
-- ----------------------------

-- ----------------------------
-- Table structure for `用户`
-- ----------------------------
DROP TABLE IF EXISTS `用户`;
CREATE TABLE `用户` (
  `用户ID` int(20) NOT NULL AUTO_INCREMENT,
  `用户名` varchar(20) NOT NULL,
  `密码` varchar(20) DEFAULT NULL,
  `手机号码` varchar(20) DEFAULT NULL,
  `性别` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`用户ID`,`用户名`),
  KEY `用户名` (`用户名`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of 用户
-- ----------------------------

-- ----------------------------
-- Table structure for `留言`
-- ----------------------------
DROP TABLE IF EXISTS `留言`;
CREATE TABLE `留言` (
  `留言编号` varchar(20) NOT NULL,
  `留言用户` varchar(20) DEFAULT NULL,
  `留言内容` varchar(100) DEFAULT NULL,
  `所属商品ID` int(20) DEFAULT NULL,
  `留言时间` datetime DEFAULT NULL,
  PRIMARY KEY (`留言编号`),
  KEY `留言用户` (`留言用户`),
  KEY `商品ID` (`所属商品ID`),
  CONSTRAINT `商品ID` FOREIGN KEY (`所属商品ID`) REFERENCES `商品` (`商品ID`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `留言用户` FOREIGN KEY (`留言用户`) REFERENCES `用户` (`用户名`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of 留言
-- ----------------------------

-- ----------------------------
-- Table structure for `管理员`
-- ----------------------------
DROP TABLE IF EXISTS `管理员`;
CREATE TABLE `管理员` (
  `管理员ID` int(20) NOT NULL AUTO_INCREMENT,
  `管理员名` varchar(20) DEFAULT NULL,
  `管理员密码` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`管理员ID`),
  KEY `管理员名` (`管理员名`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of 管理员
-- ----------------------------

-- ----------------------------
-- Table structure for `订单`
-- ----------------------------
DROP TABLE IF EXISTS `订单`;
CREATE TABLE `订单` (
  `订单编号` int(20) NOT NULL AUTO_INCREMENT,
  `用户1` varchar(20) DEFAULT NULL,
  `用户2` varchar(20) DEFAULT NULL,
  `商品1ID` varchar(20) DEFAULT NULL,
  `商品2ID` varchar(20) DEFAULT NULL,
  `订单时间` datetime DEFAULT NULL,
  PRIMARY KEY (`订单编号`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of 订单
-- ----------------------------
INSERT INTO `订单` VALUES ('1', null, null, null, null, null);

-- ----------------------------
-- Procedure structure for `usergoods`
-- ----------------------------
DROP PROCEDURE IF EXISTS `usergoods`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `usergoods`(IN `username` varchar(20))
BEGIN
	#Routine body goes here...
SELECT *FROM `商品`
WHERE `用户名`=username;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `userorder`
-- ----------------------------
DROP PROCEDURE IF EXISTS `userorder`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `userorder`(IN `username` varchar(20))
BEGIN
	#Routine body goes here...
SELECT * FROM `订单`
WHERE `用户1`=username OR `用户2`=username;
END
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for `whichstylegoods`
-- ----------------------------
DROP PROCEDURE IF EXISTS `whichstylegoods`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `whichstylegoods`(IN `goodsstyle` varchar(20))
BEGIN
	#Routine body goes here...
SELECT * FROM `商品`
WHERE `商品类别`=goodsstyle;
END
;;
DELIMITER ;
