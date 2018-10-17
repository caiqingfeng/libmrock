#include "LYUtils.h"
#include "common/src/alg.h"
#include <boost/algorithm/string.hpp>
#include <boost/random.hpp>

boost::uniform_int<> distribution(1, 1000000);
boost::mt19937 engine;
boost::variate_generator<boost::mt19937, boost::uniform_int<> > my_random(
		engine, distribution);

std::string LYUtils::intToHex(int i, unsigned int length) {
	std::string temp;
	std::stringstream ss;
	ss << std::hex << i;
	ss >> temp;
	if (temp.size() < length) {
		int num = length - temp.size();
		for (; num > 0; --num) {
			temp = "0" + temp;
		}
	} else if (temp.size() > length) {
		temp = temp.substr(0, length);
	}
	return temp;
}

/*
 * 仿照mongo OID算法产生一个唯一的Id, 参考这个文章：http://www.jb51.net/article/35953.htm
 * ObjectId 是一个 12 Bytes 的 类型，其包含：
 * 4 Bytes 自纪元时间开始的秒数
 * 3 Bytes 机器描述符
 * 2 Bytes 进程ID
 * 3 Bytes 随机数
 */
std::string LYUtils::genId() {
	//时间
	time_t t = time(NULL);
	std::string new_t = intToHex(t, 8);
	//机器描述符
	char host_name[100];
	gethostname(host_name, sizeof(host_name));
	std::string host(host_name);
	MD5 md5(host);
	std::string new_host = md5.md5();
	new_host = new_host.substr(0, 6);
	//进程ID
	pid_t pid = getpid();
	std::string new_pid = intToHex(pid, 4);
	//随机数
//	 srand((unsigned) time(NULL));
//	int random = rand() % 1000000;
	std::string new_rand1 = intToHex(my_random(), 6);
//	 std::string new_rand2 = intToHex(my_random(), 2);
//	 std::string new_rand3 = intToHex(my_random(), 2);

	return new_t + new_host + new_pid + new_rand1; // + new_rand2 + new_rand3;
}

void LYUtils::genDigest(std::string& msg, std::string& key,
		std::string& digest) {
	std::string mac;
	CryptoPP::HMAC<CryptoPP::MD5> hmac((byte*) key.data(), key.size());

	//get msg mac
	CryptoPP::StringSource(msg, true,
			new CryptoPP::HashFilter(hmac, new CryptoPP::StringSink(mac)));
	CryptoPP::StringSource(mac, true,
			new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest)));
	boost::to_upper(digest);

}
void LYUtils::printTextOrBinary(const std::string& tag,
		const std::string& str) {
	int size = str.size();
	bool is_text = true;

	int char_nbr;
	unsigned char byte;
	for (char_nbr = 0; char_nbr < size; char_nbr++) {
		byte = str[char_nbr];
		if (byte < 32 || byte > 127)
			is_text = false;
	}

//	LY_LOG_DBG(tag << ":follow this log");
	std::stringstream ss;
//	        std::cout << tag <<":";

	for (char_nbr = 0; char_nbr < size; char_nbr++) {
		if (is_text) {
//	                std::cout << (char)str [char_nbr];
			ss << (char) str[char_nbr];
		} else {
//	                std::cout << std::setfill('0') << std::setw(2)
//	                   << std::hex << (unsigned int) str [char_nbr];
			ss << std::setfill('0') << std::setw(2) << std::hex
					<< (unsigned int) str[char_nbr];
		}
	}
	ss << std::endl;
//	LY_LOG_DBG(ss);
}
