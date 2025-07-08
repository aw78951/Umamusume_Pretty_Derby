#ifndef _ATLAS_H_
#define _ATLAS_H_

#include <vector>
#include <graphics.h>

class Atlas {
	private:
		std::vector<IMAGE> img_list;

	public:
		Atlas() = default;
		~Atlas() = default;

		void Load(LPCTSTR path_template, int num) {
			img_list.clear();
			img_list.resize(num);
			
			TCHAR path_file[256];//¿ª±Ù»º³åÇø
			for (int i = 0; i < num; i++) {
				_stprintf_s(path_file, path_template, i + 1);
				loadimage(&img_list[i], path_file);
			}

		}

		void clear() {
			img_list.clear();
		}

		int get_size() const {
			return (int)img_list.size();
		}

		IMAGE* get_image(int index) {
			if (index < 0 || index >= (int)img_list.size()) {
				return nullptr;
			}
			return &img_list[index];
		}

		void add_image(const IMAGE& img) {
			img_list.push_back(img);
		}
};

#endif // !_ATLAS_H_