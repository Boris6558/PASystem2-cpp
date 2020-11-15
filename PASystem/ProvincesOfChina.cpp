#include "ProvincesOfChina.h"

vector<string> ProvincesOfChina::provinces;
vector< vector<string> > ProvincesOfChina::city;

ProvincesOfChina::ProvincesOfChina()
{
	
}


ProvincesOfChina::~ProvincesOfChina()
{
}

void ProvincesOfChina::init()
{
	provinces +=
		"北京市",
		"天津市",
		"河北省",
		"山西省",
		"内蒙古自治区",
		"辽宁省",
		"吉林省",
		"黑龙江省",
		"上海市",
		"江苏省",
		"浙江省",
		"安徽省",
		"福建省",
		"江西省",
		"山东省",
		"河南省",
		"湖北省",
		"湖南省",
		"广东省",
		"广西壮族自治区",
		"海南省",
		"重庆市",
		"四川省",
		"贵州省",
		"云南省",
		"西藏自治区",
		"陕西省",
		"甘肃省",
		"青海省",
		"宁夏回族自治区",
		"新疆维吾尔自治区",
		"香港特别行政区",
		"澳门特别行政区",
		"台湾地区"
		;

	vector<string> BeiJing; BeiJing += "北京";
	vector<string> TianJin; TianJin += "天津";
	vector<string> HeBei;
	HeBei +=
		"石家庄",
		"唐山",
		"秦皇岛",
		"邯郸",
		"邢台",
		"保定",
		"张家口",
		"承德",
		"沧州",
		"廊坊",
		"衡水"
		;
	vector<string> ShanXi;//山西
	ShanXi +=
		"太原",
		"太同",
		"阳泉",
		"长治",
		"晋城",
		"朔州",
		"晋中",
		"运城",
		"忻州",
		"临汾",
		"吕梁"
		;
	vector<string> NeiMengGu;
	NeiMengGu +=
		"呼和浩特",
		"包头",
		"乌海",
		"赤峰",
		"通辽",
		"鄂尔多斯",
		"呼伦贝尔",
		"巴彦卓尔",
		"乌兰察布",
		"兴安盟",
		"锡林浩特盟",
		"阿拉善盟"
		;
	vector<string> LiaoNing;
	LiaoNing +=
		"潘阳",
		"大连",
		"鞍山",
		"抚顺",
		"本溪",
		"丹东",
		"锦州",
		"营口",
		"阜新",
		"辽阳",
		"盘锦",
		"铁岭",
		"朝阳",
		"葫芦岛"
		;
	vector<string> JiLin;
	JiLin +=
		"长春",
		"吉林",
		"四平",
		"辽源",
		"通化",
		"白山",
		"松原",
		"白城",
		"延边朝鲜族自治州"
		;
	vector<string> HeiLongJiang;
	HeiLongJiang +=
		"哈尔滨",
		"齐齐哈尔",
		"鸡西",
		"鹤岗",
		"双鸭山",
		"大庆",
		"伊春",
		"佳木斯",
		"七台河",
		"牡丹江",
		"黑河",
		"绥化",
		"大兴安岭"
		;
	vector<string> ShangHai; ShangHai += "上海";
	vector<string> JiangSu;
	JiangSu +=
		"南京",
		"无锡",
		"徐州",
		"常州",
		"苏州",
		"南通",
		"连云港",
		"淮安",
		"盐城",
		"扬州",
		"镇江",
		"泰州",
		"宿迁"
		;
	vector<string> ZheJiang;
	ZheJiang +=
		"杭州",
		"宁波",
		"温州",
		"嘉兴",
		"湖州",
		"绍兴",
		"金华",
		"衢州",
		"丹山",
		"台州",
		"丽水"
		;
	vector<string> AnHui;
	AnHui +=
		"合肥",
		"芜湖",
		"蚌埠",
		"淮南",
		"马鞍山",
		"淮北",
		"铜陵",
		"安庆",
		"黄山",
		"滁州",
		"阜阳",
		"宿州",
		"六安",
		"毫州",
		"池州",
		"宣城"
		;
	vector<string> FuJian;
	FuJian +=
		"厦门",
		"福州",
		"莆田",
		"三明",
		"泉州",
		"漳州",
		"南平",
		"龙岩",
		"宁德"
		;
	vector<string> JiangXi;
	JiangXi +=
		"南昌",
		"景德镇",
		"萍乡",
		"九江",
		"新余",
		"鹰潭",
		"贛州",
		"吉安",
		"宜春",
		"抚州",
		"上饶"
		;
	vector<string> ShanDong;
	ShanDong +=
		"济南",
		"青岛",
		"淄博",
		"枣庄",
		"东营",
		"烟台",
		"潍坊",
		"济宁",
		"泰安",
		"威海",
		"日照",
		"临沂",
		"德州",
		"聊城",
		"滨州",
		"菏泽"
		;
	vector<string> HeNan;
	HeNan +=
		"郑州",
		"开封",
		"洛阳",
		"平顶山",
		"安阳",
		"鹤壁",
		"新乡",
		"焦作",
		"濮阳",
		"许昌",
		"漯河",
		"三门峡",
		"南阳",
		"商丘",
		"信阳",
		"周口",
		"驻马店",
		"济源"
		;
	vector<string> HuBei;
	HuBei +=
		"武汉",
		"黄石",
		"十堰",
		"宜昌",
		"襄阳",
		"鄂州",
		"荆门",
		"孝感",
		"荆州",
		"黄冈",
		"咸宁",
		"随州",
		"恩施土家苗族自治州",
		"仙桃",
		"潜江",
		"天门",
		"神农架林区"
		;
	vector<string> HuNan;
	HuNan +=
		"长沙",
		"株洲",
		"湘潭",
		"衡阳",
		"邵阳",
		"岳阳",
		"常德",
		"张家界",
		"益阳",
		"郴州",
		"永州",
		"怀化",
		"娄底",
		"湘西土家族苗族自治州"
		;
	vector<string> GuangDong;
	GuangDong +=
		"广州",
		"深圳",
		"韶关",
		"珠海",
		"汕头",
		"佛山",
		"江门",
		"湛江",
		"茂名",
		"肇庆",
		"惠州",
		"梅州",
		"汕尾",
		"河源",
		"阳江",
		"清远",
		"东莞",
		"中山",
		"潮州",
		"揭阳",
		"云浮"
		;
	vector<string> GuangXi;
	GuangXi +=
		"南宁",
		"柳州",
		"桂林",
		"梧州",
		"北海",
		"防城港",
		"钦州",
		"贵港",
		"玉林",
		"百色",
		"贺州",
		"河池",
		"来宾",
		"崇左市"
		;
	vector<string> HaiNan;
	HaiNan +=
		"海口",
		"三亚",
		"三沙",
		"儋州",
		"五指山",
		"琼海",
		"文昌",
		"万宁",
		"东方"
		;
	vector<string> ChongQing; ChongQing += "重庆";
	vector<string> SiChuan;
	SiChuan +=
		"成都",
		"自贡",
		"攀枝花",
		"泸州",
		"德阳",
		"锦阳",
		"广源",
		"遂宁",
		"内江",
		"乐山",
		"南充",
		"眉山",
		"宜宾",
		"广安",
		"达州",
		"雅安",
		"巴中",
		"资阳",
		"马尔康",
		"康定",
		"西昌"
		;
	vector<string> GuiZhou;
	GuiZhou +=
		"贵阳",
		"六盘水",
		"遵义",
		"安顺",
		"毕节",
		"铜仁",
		"兴义",
		"兴仁",
		"凯里",
		"都匀",
		"福泉"
		;
	vector<string> YunNan;
	YunNan +=
		"昆明",
		"曲靖",
		"玉溪",
		"宝山",
		"昭通",
		"丽江",
		"普洱",
		"临沧",
		"楚雄",
		"蒙自",
		"文三",
		"景洪",
		"大理",
		"芒市",
		"泸水",
		"香格里拉"
		;
	vector<string> XiZhang;
	XiZhang +=
		"拉萨",
		"日喀则",
		"昌都",
		"林芝",
		"山南",
		"那曲",
		"阿里地区"
		;
	vector<string> ShanXi_;//陕西
	ShanXi_ +=
		"西安",
		"铜川",
		"宝鸡",
		"咸阳",
		"渭南",
		"延安",
		"汉中",
		"榆林",
		"安康",
		"商洛"
		;
	vector<string> GanSu;
	GanSu +=
		"兰州",
		"嘉峪关",
		"金昌",
		"白银",
		"天水",
		"武威",
		"张掖",
		"平凉",
		"酒泉",
		"庆阳",
		"定西",
		"陇南",
		"临夏",
		"合作"
		;
	vector<string> QingHai;
	QingHai +=
		"西宁",
		"海东",
		"海北藏族自治州",
		"黄海藏族自治州",
		"海南藏族自治州",
		"玉树藏族自治州",
		"海西蒙古族藏族自治州"
		;
	vector<string> NingXia;
	NingXia +=
		"银川",
		"石嘴山",
		"吴忠",
		"固原",
		"中卫"
		;
	vector<string> XinJiang;
	XinJiang +=
		"乌鲁木齐",
		"克拉玛依",
		"吐鲁番",
		"哈密",
		"阿克苏",
		"喀什",
		"和田",
		"昌吉回族自治州",
		"博尔塔拉蒙古自治州",
		"巴音郭楞蒙古自治州",
		"克孜勒苏阿尔克自治州",
		"伊犁哈萨克自治州自治州",
		"石河子",
		"阿拉尔",
		"图木舒克",
		"五家渠",
		"北屯",
		"铁门关",
		"双河",
		"可克达拉",
		"昆玉"
		;
	vector<string> HongKong;
	HongKong +=
		"香港岛",
		"九龙",
		"新界"
		;
	vector<string> Macao; Macao += "澳门";
	vector<string> TaiWan; TaiWan += "台湾";

	city +=
		BeiJing,
		TianJin,
		HeBei,
		ShanXi,
		NeiMengGu,
		LiaoNing,
		JiLin,
		HeiLongJiang,
		ShangHai,
		JiangSu,
		ZheJiang,
		AnHui,
		FuJian,
		JiangXi,
		ShanDong,
		HeNan,
		HuBei,
		HuNan,
		GuangDong,
		GuangXi,
		HaiNan,
		ChongQing,
		SiChuan,
		GuiZhou,
		YunNan,
		XiZhang,
		ShanXi_,
		GanSu,
		QingHai,
		NingXia,
		XinJiang,
		HongKong,
		Macao,
		TaiWan
		;
}

