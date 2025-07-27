#include <iostream>
#include "httpClient.h"

int main() {
	auto future = PostFacultyAsync("ウルトラゲームクリエイター科");

	while (true) {
		//ゲームの更新・描画処理など

		if (future.valid() &&
			future.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready) {
			std::string res = future.get();
			std::cout << "POST結果: " << res << std::endl;

			//POST完了後に全件取得
			auto getFuture = GetAllFacultiesAsync();
			std::string all = getFuture.get();
			std::cout << "現在の全学科一覧:\n" << all << std::endl;

			break; // デモなので終了
		}
	}
	return 0;
}
