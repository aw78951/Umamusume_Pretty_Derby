#include "../thirdparty/httplib.h"

#include <string>
#include <mutex>
#include <fstream>

std::string str_text;//�ı�����
std::mutex g_mutex;//ȫ�ֻ�����

int progress_1 = -1;//��ҽ��� 
int progress_2 = -1;

void on_hello(const httplib::Request& req, httplib::Response& res) {
	std::lock_guard<std::mutex> lock(g_mutex);

	std::cout << "Hello From Client" << std::endl;

	res.set_content("Hello From Server", "text/plain");
}

int main(int argc, char** argy) {
	httplib::Server server;

	server.Post("/hello", on_hello);

	server.listen("localhost", 25565);

	return 0;
}