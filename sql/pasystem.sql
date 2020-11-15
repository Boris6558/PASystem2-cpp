/*
Navicat MySQL Data Transfer

Source Server         : PerformanceAppraisalSystemTest
Source Server Version : 80018
Source Host           : localhost:3306
Source Database       : pasystem

Target Server Type    : MYSQL
Target Server Version : 80018
File Encoding         : 65001

Date: 2020-06-03 12:31:51
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for add_mechanism
-- ----------------------------
DROP TABLE IF EXISTS `add_mechanism`;
CREATE TABLE `add_mechanism` (
  `mechanism_id` varchar(255) NOT NULL COMMENT '当前登录机构的编号',
  `add_mechanism_id` varchar(255) NOT NULL COMMENT '新增机构编号',
  `add_mechanism_name` varchar(255) NOT NULL COMMENT '新增机构名称',
  `add_mechanism_simple_name` varchar(255) NOT NULL,
  `add_mechanism_man` varchar(255) NOT NULL COMMENT '新增机构的法定代表人',
  `add_mechanism_registerMoney` varchar(255) NOT NULL COMMENT '注册资金',
  `add_mechanism_address` varchar(255) NOT NULL COMMENT '注册地',
  PRIMARY KEY (`mechanism_id`,`add_mechanism_id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of add_mechanism
-- ----------------------------
INSERT INTO `add_mechanism` VALUES ('100233-896655', '0001', '广发银行', '广发银行', '陈就', '200000', '广州');
INSERT INTO `add_mechanism` VALUES ('100233-896655', '0002', '佛山银行', '佛山银行', '刘给', '200000', '广州');
INSERT INTO `add_mechanism` VALUES ('100233-896655', '0003', '工行分行', '工行分行', '张炯', '200000', '广州');
INSERT INTO `add_mechanism` VALUES ('100233-896655', '0004', '华尔街银行', '华行', '史蒂夫', '60000', '西雅图');
INSERT INTO `add_mechanism` VALUES ('100233-896655', '0005', '中央银行', '中行', '刘斌', '100000000', '北京');
INSERT INTO `add_mechanism` VALUES ('100233-896655', '0006', 'PAS', 'PAS', '路德', '10000', '洛杉矶');

-- ----------------------------
-- Table structure for admin_acc
-- ----------------------------
DROP TABLE IF EXISTS `admin_acc`;
CREATE TABLE `admin_acc` (
  `login_name` varchar(255) NOT NULL,
  `login_passwd` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of admin_acc
-- ----------------------------
INSERT INTO `admin_acc` VALUES ('admin', 'admin');

-- ----------------------------
-- Table structure for contract_class_info
-- ----------------------------
DROP TABLE IF EXISTS `contract_class_info`;
CREATE TABLE `contract_class_info` (
  `mechanism_id` varchar(255) NOT NULL COMMENT '机构编号',
  `contract_id` varchar(255) NOT NULL COMMENT '合同类别编号',
  `contract_name` varchar(255) NOT NULL COMMENT '合同类别名称',
  PRIMARY KEY (`contract_id`,`mechanism_id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of contract_class_info
-- ----------------------------
INSERT INTO `contract_class_info` VALUES ('000000-4545465', 'CG1234', '股票抛售');
INSERT INTO `contract_class_info` VALUES ('000000-4545465', 'CG445682', '信用');
INSERT INTO `contract_class_info` VALUES ('000000-4545465', 'CG45215', '保险类');
INSERT INTO `contract_class_info` VALUES ('000000-4545465', 'CG452457', '企业合作');
INSERT INTO `contract_class_info` VALUES ('000000-4545465', 'CG45288', '贷款');
INSERT INTO `contract_class_info` VALUES ('100233-896655', 'HU3002', '其他相关');
INSERT INTO `contract_class_info` VALUES ('100233-896655', 'LV1022', '信用');
INSERT INTO `contract_class_info` VALUES ('100233-896655', 'LV4577', '征信');
INSERT INTO `contract_class_info` VALUES ('100233-896655', 'LV5520', '贷款');
INSERT INTO `contract_class_info` VALUES ('100233-896655', 'LV5656', '外资');

-- ----------------------------
-- Table structure for contract_info
-- ----------------------------
DROP TABLE IF EXISTS `contract_info`;
CREATE TABLE `contract_info` (
  `mechanism_id` varchar(255) NOT NULL,
  `contract_id` varchar(255) NOT NULL COMMENT '合同编号',
  `contract_class_id` varchar(255) NOT NULL,
  `contract_class_name` varchar(255) NOT NULL,
  `add_mechanism_id` varchar(255) NOT NULL COMMENT '新增合同 的机构编号',
  `add_mechanism_name` varchar(255) NOT NULL,
  `start` date NOT NULL COMMENT '开始时间',
  `end` date NOT NULL,
  `commit_man` varchar(255) NOT NULL COMMENT '提交人',
  `commit_date` date NOT NULL COMMENT '提交时间',
  `path_contract_face` varchar(255) NOT NULL COMMENT '合同扫描面 正面',
  `path_contract_text` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '合同扫描面 签字面',
  `is_del` varchar(255) NOT NULL COMMENT '该合同是否删除',
  `del_time` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  PRIMARY KEY (`mechanism_id`,`contract_id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of contract_info
-- ----------------------------
INSERT INTO `contract_info` VALUES ('100233-896655', '0001', 'LV1022', '信用', '0002', '佛山银行', '2000-01-01', '2000-01-01', '刘斌', '2000-01-01', '', '', '否', '4/11/2020');
INSERT INTO `contract_info` VALUES ('100233-896655', '0002', 'lv1022', '信用', '0003', '工行分行', '2000-01-01', '2000-01-01', '张解耦', '2000-01-01', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/1.jpg', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/3.jpg', '否', '4/11/2020');
INSERT INTO `contract_info` VALUES ('100233-896655', '0003', 'lv5656', '外资', '0002', '佛山银行', '2020-01-01', '2020-01-01', '张富贵', '2020-01-13', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/2.jpg', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/1.jpg', '否', '4/11/2020');
INSERT INTO `contract_info` VALUES ('100233-896655', '0004', 'lv5656', '外资', '0003', '工行分行', '2000-01-01', '2000-01-01', 'Lily', '2000-01-01', '', '', '否', '4/11/2020');
INSERT INTO `contract_info` VALUES ('100233-896655', '0005', 'HU3002', '其他相关', '0005', '中央银行', '2000-01-01', '2000-01-01', '刘大帅', '2000-01-01', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/hetong1.png', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/hetong1.png', '否', '4/11/2020');

-- ----------------------------
-- Table structure for hr_ecruitment
-- ----------------------------
DROP TABLE IF EXISTS `hr_ecruitment`;
CREATE TABLE `hr_ecruitment` (
  `mechanism_id` varchar(255) NOT NULL,
  `recruitment_post` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '招聘岗位',
  `mechanism_introduce` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '机构介绍',
  `post_introduce` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '岗位介绍',
  `recruitment_count` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '招聘人数',
  `money_start` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '薪资 最低',
  `money_end` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '信息 最高',
  `work_address` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '工作地址',
  `status` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '招聘状态',
  `other` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '其他说明',
  `time` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '发布时间',
  PRIMARY KEY (`mechanism_id`,`recruitment_post`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of hr_ecruitment
-- ----------------------------

-- ----------------------------
-- Table structure for hr_emp_info
-- ----------------------------
DROP TABLE IF EXISTS `hr_emp_info`;
CREATE TABLE `hr_emp_info` (
  `mechanism_id` varchar(255) NOT NULL COMMENT '机构编号',
  `emp_id` varchar(255) NOT NULL,
  `emp_name` varchar(255) NOT NULL,
  `sex` varchar(255) NOT NULL,
  `post` varchar(255) NOT NULL COMMENT '职位',
  `email` varchar(255) NOT NULL,
  `phone` varchar(255) NOT NULL,
  `birthday` date NOT NULL,
  `entryday` date NOT NULL COMMENT '入职时间',
  PRIMARY KEY (`mechanism_id`,`emp_id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of hr_emp_info
-- ----------------------------
INSERT INTO `hr_emp_info` VALUES ('000000-454545', '0000', '蒋介石', '男', '经理', 'fwg@ga.com', '13356568420', '2019-12-17', '2019-12-18');
INSERT INTO `hr_emp_info` VALUES ('000000-454545', '0001', '刘德华', '男', '职员', 'gww@ggg.com', '13975421003', '2020-03-03', '2020-03-25');
INSERT INTO `hr_emp_info` VALUES ('100233-896655', '0000', '李白', '男', '职员', 'gw@gjao.com', '15684521256', '1998-01-01', '2019-08-28');
INSERT INTO `hr_emp_info` VALUES ('100233-896655', '0001', '李欣', '女', '前台', 'gww@ga.com', '13352014025', '1998-01-01', '2019-08-01');
INSERT INTO `hr_emp_info` VALUES ('100233-896655', '0002', '亲苏若', '男', '职员', 'gwe@gao.com', '13152012204', '2003-01-01', '2020-03-01');
INSERT INTO `hr_emp_info` VALUES ('100233-896655', '0004', '苏格拉底', '男', '算法工程师', 'gweg@jo.com', '18245782102', '1991-01-01', '2020-02-19');
INSERT INTO `hr_emp_info` VALUES ('100233-896655', '0005', '漩涡鸣人', '男', '前台', 'jgou@jgo.com', '13387400002', '1995-01-01', '2019-12-01');
INSERT INTO `hr_emp_info` VALUES ('100233-896655', '0006', '紫霞', '女', '职员', 'ger@jgo.com', '13975420128', '2001-01-01', '2019-07-31');
INSERT INTO `hr_emp_info` VALUES ('100233-896655', '0007', '孙中山', '男', '经理', 'jojg@jog.com', '13103028465', '2003-01-01', '2019-12-03');
INSERT INTO `hr_emp_info` VALUES ('100233-896655', '0008', '程咬金', '男', '部长', 'cyj@qq.com', '15113132540', '2020-04-09', '2020-02-06');
INSERT INTO `hr_emp_info` VALUES ('100233-896655', '0009', '貂蝉', '女', '前台', 'dc@jog.com', '13350502001', '2018-08-16', '2019-07-19');

-- ----------------------------
-- Table structure for mechanism_feedback
-- ----------------------------
DROP TABLE IF EXISTS `mechanism_feedback`;
CREATE TABLE `mechanism_feedback` (
  `mechanism_id` varchar(255) NOT NULL,
  `feedback` varchar(255) NOT NULL,
  `img_1` varchar(255) NOT NULL,
  `img_2` varchar(255) NOT NULL,
  `img_3` varchar(255) NOT NULL,
  `feedback_time` varchar(255) NOT NULL,
  `is_write` varchar(255) NOT NULL,
  PRIMARY KEY (`mechanism_id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of mechanism_feedback
-- ----------------------------
INSERT INTO `mechanism_feedback` VALUES ('100233-896655', '绩效等级有误！', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/unnamed.jpg', '', '', '2020-4-12', '是');

-- ----------------------------
-- Table structure for mechanism_info
-- ----------------------------
DROP TABLE IF EXISTS `mechanism_info`;
CREATE TABLE `mechanism_info` (
  `mechanism_id` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '受理机构编号',
  `mechanism_name` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '机构名称',
  `mechanism_introduce` varchar(255) NOT NULL COMMENT '公司介绍',
  `address` varchar(255) NOT NULL COMMENT '地址',
  `type` varchar(255) NOT NULL COMMENT '行业类型',
  `register` varchar(255) NOT NULL COMMENT '注册人',
  `id_card` varchar(255) NOT NULL COMMENT '身份证',
  `phone` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `status` varchar(255) NOT NULL COMMENT '状态（存续、在业、吊销、注销、迁入、迁出、停业、清算）',
  `path_id` varchar(255) NOT NULL COMMENT '组织机构代码证 图片',
  `count` varchar(255) NOT NULL COMMENT '公司总人数',
  `male_rate` varchar(255) NOT NULL COMMENT '男性占比',
  `female_rate` varchar(255) NOT NULL COMMENT '女性占比',
  `RCC_rate` varchar(255) NOT NULL COMMENT '本科占比',
  `non_RCC_rate` varchar(255) NOT NULL COMMENT '非本科占比',
  `more_RCC` varchar(255) NOT NULL COMMENT '本科以上的占比',
  `mark` varchar(255) NOT NULL COMMENT '备注',
  `path_logo` varchar(255) NOT NULL,
  `login_name` varchar(255) NOT NULL,
  `login_passwd` varchar(255) NOT NULL,
  PRIMARY KEY (`mechanism_id`,`login_name`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of mechanism_info
-- ----------------------------
INSERT INTO `mechanism_info` VALUES ('000000-454545', '遥信证券', '简介', '广东省', '证券', '正三', '460030166545457810', '13358421572', 'fwg@ga.com', '在业', 'C:/Users/root/Desktop/__UE4uImage/Dark_Seamless_Wood_Texture.jpg', '100', '50%', '50%', '30%', '60%', '10%', '备注信息', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/Bingood_logo.png', '0000', '0000');
INSERT INTO `mechanism_info` VALUES ('100233-896655', 'Bin信分行', 'Bin信分行简介4646546556', '广州市', '银行', '刘斌', '46003019910103392800', '13154521021', 'gjoa@gmial.com', '在业', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/unnamed.jpg', '10', '75%', '25%', '64%', '36%', '10%', '信息修改', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/Bingood_logo.png', 'bbbb', 'bbbb');
INSERT INTO `mechanism_info` VALUES ('101101-230023', 'bb银行', '简介', '广东省广州市', '银行', '刘斌', '460030199712083911', '13352048575', 'gj@gmail.com', '在业', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/11.jpg', '2000', '50%', '50%', '60%', '40%', '30%', '14', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/Bingood_logo.png', '6666', '6666');
INSERT INTO `mechanism_info` VALUES ('155454-568942', '广州美丽银行', '简介', '广州', '银行', '张力', '4600301278541225', '13145458989', 'gw@ga.com', '在业', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/11.jpg', '101', '50%', '50%', '50%', '50%', '30%', 'ffe', '', 'test', 'test');
INSERT INTO `mechanism_info` VALUES ('450225-487752', '工行佛山分行', '工行佛山分行的简介', '广东佛山', '银行', '杜特地', '460030155754210002', '13165033057', 'gw@jjgl.com', '在业', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/11.jpg', '100', '30%', '70%', '50%', '50%', '30%', '备注', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/Bingood_logo.png', '5555', '5555');
INSERT INTO `mechanism_info` VALUES ('454024-545580', '中国保险', '简介Xinxi', '广东省广州', '保险', '韩解耦', '460030167825102112', '133547885558', 'ili@cgwog.com', '在业', '', '1000', '40%', '60%', '80%', '20%', '30%', '没有', '', 'gwegw', 'hrtr');
INSERT INTO `mechanism_info` VALUES ('454664-888580', 'Jolie证券公司', 'Jolie证券公司简介', '广东省东莞市石碣镇', '证券', '刘宏观', '460030195402610222', '13975214202', 'joili@cjog.com', '在业', '', '100', '50%', '50%', '50%', '50%', '30%', '没有', '', 'gaete', 'ggge');
INSERT INTO `mechanism_info` VALUES ('454664-888582', '华尔金融银行', '我们银行即将进入华尔街', '广东省东莞市', '银行', '李继红', '460030199845210255', '13356201444', 'gw@jo.com', '存续', '', '10', '30%', '70%', '60%', '40%', '20%', '没有', '', 'fff', 'gwgwgwr');
INSERT INTO `mechanism_info` VALUES ('456566-565656', 'ui银行', 'ui银行的介绍', '广州', '银行', '张九万', '460030199712086555', '18256568989', 'fwg@jgoa.com', '在业', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/2.jpg', '1545', '57%', '57%', '67%', '67%', '47%', 'f我怪我', '', 'ouog', 'gwg452');
INSERT INTO `mechanism_info` VALUES ('456568-894562', '美丽银行', 'ffw', '广州', '银行', '张六', '460030211445780100', '13356784521', 'fwg@sfgs.com', '在业', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/11.jpg', '100', '50%', '50%', '50%', '50%', '20%', '', '', 'test2', 'test2');
INSERT INTO `mechanism_info` VALUES ('456665-784454', '顺丰银行', '顺丰简介', '广东广州', '银行', '张富贵', '4300601995456639001240', '13389895641', 'gajil@gmail.com', '在业', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/unnamed.jpg', '1000', '50%', '50%', '60%', '40%', '30%', 'mei', 'D:/__Codes/__Visual_Studio/PASystem/PASystem/Resources/images/Bingood_logo.png', 'test3', 'test3');
INSERT INTO `mechanism_info` VALUES ('464686-456846', '中央-银行', '中央银行简介', '广西', '银行', '张三', '460030197712053911', '18289345159', 'fwgw@gja.ocm', '在业', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/11.jpg', '1000', '50%', '50%', '50%', '50%', '30%', '备注', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/Bingood_logo.png', 'login', '123456');
INSERT INTO `mechanism_info` VALUES ('550245-555555', '夫子银行', '这hi是简介', '广州市', '银行', '林震', '460030166545454545', '13156565656', 'fwgwg@jog.cnf', '在业', 'D:/__Codes/__Visual_Studio/PASystem 2.0/PASystem/Resources/images/11.jpg', '100', '213%', '213%', '2131%', '24%', '24%', '备注', '', 'gwgwg', 'fefeff');
INSERT INTO `mechanism_info` VALUES ('551000-100124', '瑰宝银行', '该银行的简介', '广东省广州市', '银行', '刘国伟', '460030122584520111', '18256407741', 'ge@oug.com', '在业', ' ', '20', '30%', '70%', '30%', '70%', '20%', '这是备注', ' ', '1111', '123456');

-- ----------------------------
-- Table structure for pa_each_level
-- ----------------------------
DROP TABLE IF EXISTS `pa_each_level`;
CREATE TABLE `pa_each_level` (
  `mechanism_id` varchar(255) NOT NULL,
  `mechanism_name` varchar(255) NOT NULL,
  `check_type` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '本月考核 季度考核 年度考核',
  `complaints_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '投诉率 等级  如月考核 则为投诉次数/31',
  `norm_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '手续规范性 等级',
  `loan_efficiency_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '发放贷款效率等级 慢的次数',
  `muster_error_rate_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '归集出错率等级',
  `loan_error_rate_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '贷款出错率等级',
  `get_muster_rate_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '归集资金到账率等级',
  `get_loan_rate_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '贷款资金到账率等级',
  `net_save_error_rate_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '网络缴存出错率等级',
  `net_get_error_rate_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '网络提取错误率等级',
  `net_loan_error_rata_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '网络贷款出错率',
  `net_return_error_rate_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '网络还款错误率',
  `net_over_error_rate_level` varchar(255) NOT NULL COMMENT '网络逾期出错率',
  `net_time_level` varchar(255) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL COMMENT '网络负时效等级',
  `result_level` varchar(255) NOT NULL COMMENT '最终结果',
  PRIMARY KEY (`mechanism_id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of pa_each_level
-- ----------------------------
INSERT INTO `pa_each_level` VALUES ('100233-896655', 'Bin信分行', '月度考核', 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'A', 'A', 'A', 'B', 'B', 'A', 'A');

-- ----------------------------
-- Table structure for pa_level_result
-- ----------------------------
DROP TABLE IF EXISTS `pa_level_result`;
CREATE TABLE `pa_level_result` (
  `mechanism_id` varchar(255) NOT NULL,
  `mechanism_name` varchar(255) NOT NULL,
  `result_level` varchar(255) NOT NULL,
  `date` varchar(255) NOT NULL,
  `is_write` varchar(255) NOT NULL COMMENT '是否填写绩效考核表',
  `type` varchar(255) NOT NULL COMMENT '月/季度/年度',
  PRIMARY KEY (`mechanism_id`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of pa_level_result
-- ----------------------------
INSERT INTO `pa_level_result` VALUES ('000000-454545', '遥信证券', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('100233-896655', 'Bin信分行', 'A', '4/12/2020', '是', '月度考核');
INSERT INTO `pa_level_result` VALUES ('101101-230023', 'bb银行', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('155454-568942', '广州美丽银行', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('450225-487752', '工行佛山分行', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('454024-545580', '中国保险', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('454664-888580', 'Jolie证券公司', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('454664-888582', '华尔金融银行', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('456566-565656', 'ui银行', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('456568-894562', '美丽银行', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('456665-784454', '顺丰银行', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('464686-456846', '中央-银行', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('550245-555555', '夫子银行', 'non', '4/12/2020', '否', '月度考核');
INSERT INTO `pa_level_result` VALUES ('551000-100124', '瑰宝银行', 'non', '4/12/2020', '否', '月度考核');
